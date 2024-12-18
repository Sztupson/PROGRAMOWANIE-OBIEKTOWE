#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define DIGIT_COUNT 10 // 1234567890

typedef struct shared {
    unsigned long count[DIGIT_COUNT];
    pthread_mutex_t mutex;
} shared_t;

void count_digits(const char *data, size_t start, size_t end, shared_t *shared_context) {
    unsigned long local_count[DIGIT_COUNT] = {0};

    for (size_t i = start; i < end; i++) {
        if (data[i] >= '0' && data[i] <= '9') { local_count[data[i] - '0']++; }
    }

    pthread_mutex_lock(&shared_context->mutex);
    for (int i = 0; i < DIGIT_COUNT; i++) {
        shared_context->count[i] += local_count[i];
    }
    pthread_mutex_unlock(&shared_context->mutex);
}

int main(int argc, char* argv[2]) {
    struct stat statbuf;
    if (argc != 3) { fprintf(stderr, "Wrong program input.\n", argv[0]); return 1; }

    const char* file_path = argv[1];
    int process_count = atoi(argv[2]);

    if (process_count < 1) { fprintf(stderr, "Processes have to be >=1\n"); return 1; }

    int fd = open(file_path, O_RDONLY);
    if (fd == -1) { perror("Cannot open file"); return 1; }

    if (fstat(fd, &statbuf) == -1) {
        perror("Failed to get file stats");
        close(fd);
        return 1;
    }
    printf("File size: %ld bytes\n", statbuf.st_size);

    char *content = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (content == MAP_FAILED) { 
        perror("Failed to mmap file"); 
        close(fd); 
        return 1; 
    }

    close(fd);

    int prot = PROT_READ | PROT_WRITE;
    int vis = MAP_SHARED | MAP_ANONYMOUS;
    shared_t *shared_context = mmap(NULL, sizeof(shared_t), prot, vis, -1, 0);
    if (shared_context == MAP_FAILED) {
        perror("Failed to mmap shared context");
        munmap(content, statbuf.st_size);
        return 1;
    }

    memset(shared_context->count, 0, sizeof(shared_context->count));

    pthread_mutexattr_t mutexattr;
    if (pthread_mutexattr_init(&mutexattr) != 0 ||
        pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED) != 0 ||
        pthread_mutex_init(&shared_context->mutex, &mutexattr) != 0) {
        perror("Failed to initialize mutex");
        munmap(content, statbuf.st_size);
        munmap(shared_context, sizeof(shared_t));
        return 1;
    }

    size_t chunk_size = statbuf.st_size / process_count;
    size_t remainder = statbuf.st_size % process_count;

    pid_t pids[process_count];

    for (int i = 0; i < process_count; i++) {
        size_t start = i * chunk_size;
        size_t end = (i == process_count - 1) ? (start + chunk_size + remainder) : (start + chunk_size);

        pid_t pid = fork();
        if (pid == -1) {
            perror("Failed to fork process");
            munmap(content, statbuf.st_size);
            munmap(shared_context, sizeof(shared_t));
            return 1;
        }

        if (pid == 0) {
            count_digits(content, start, end, shared_context);
            munmap(content, statbuf.st_size);
            munmap(shared_context, sizeof(shared_t));
            exit(0);
        } else { pids[i] = pid; }
    }

    for (int i = 0; i < process_count; i++) {
        waitpid(pids[i], NULL, 0);
    }

    for (int i = 0; i < DIGIT_COUNT; i++) {
        printf("Digit %d: %lu\n", i, shared_context->count[i]);
    }

    pthread_mutex_destroy(&shared_context->mutex);
    munmap(shared_context, sizeof(shared_t));
    munmap(content, statbuf.st_size);

    return 1;
}
