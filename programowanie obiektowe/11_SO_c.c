#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void count_digits(char* start, size_t length, struct context* shared_ctx) {
    unsigned long local_count[DIGIT_COUNT] = {0};

    for (size_t i = 0; i < length; ++i) {
        if (start[i] >= '0' && start[i] <= '9') {
            local_count[start[i] - '0']++;
        }
    }

    pthread_mutex_lock(&shared_ctx->mutex);
    for (int i = 0; i < DIGIT_COUNT; ++i) {
        shared_ctx->count[i] += local_count[i];
    }
    pthread_mutex_unlock(&shared_ctx->mutex);
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_path> <process_count>\n", argv[0]);
        return 1;
    }

    const char* file_path = argv[1];
    int process_count = atoi(argv[2]);
    if (process_count < 1) {
        fprintf(stderr, "Process count must be at least 1.\n");
        return 1;
    }

    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    size_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    char* file_data = (char*)mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    close(fd);

    int shm_fd = shm_open("/shared_ctx", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Error creating shared memory");
        munmap(file_data, file_size);
        return 1;
    }

    size_t shm_size = sizeof(struct context);
    if (ftruncate(shm_fd, shm_size) == -1) {
        perror("Error setting shared memory size");
        perror("Error setting shared memory size");
        shm_unlink("/shared_ctx");
        munmap(file_data, file_size);
        return 1;
    }

    context* shared_ctx = (context*)mmap(NULL, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_ctx == MAP_FAILED) {
        perror("Error mapping shared memory");
        shm_unlink("/shared_ctx");
        munmap(file_data, file_size);
        return 1;
    }

    memset(shared_ctx->count, 0, sizeof(shared_ctx->count));
    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&shared_ctx->mutex, &mutex_attr);

    size_t chunk_size = file_size / process_count;
    pid_t pids[process_count];

    for (int i = 0; i < process_count; ++i) {
        size_t start = i * chunk_size;
        size_t length = (i == process_count - 1) ? file_size - start : chunk_size;

        if ((pids[i] = fork()) == 0) {
            count_digits(file_data + start, length, shared_ctx);
            munmap(file_data, file_size);
            munmap(shared_ctx, shm_size);
            exit(0);
        }
    }

    for (int i = 0; i < process_count; ++i) {
        waitpid(pids[i], nullptr, 0);
    }

    shared_t *shr = (shared_t*)mmap(NULL, sizeof(shared_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shr == NULL)
        return -1;

    pthread_mutexattr_t mutexattr;
    if (pthread_mutexattr_init(&mutexattr) != 0)
        return -2;
    if (pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED) != 0)
        return -3;
    if (pthread_mutex_init(&shr->mutex, &mutexattr) != 0)
        return -4;

    pid_t pid = fork();
    switch (pid) {
        case -1: /* coś poszło nie tak */
            return -5;
        case 0: /* jesteśmy w nowym procesie */
            child(shr);
            break;
        default: /* jesteśmy w starym procesie */
            parent(shr);
            break;
    }

    pthread_mutex_destroy(&shr->mutex);
    pthread_mutex_destroy(&shared_ctx->mutex);
    munmap(shr, sizeof(shared_t));
    munmap(shared_ctx, shm_size);
    shm_unlink("/shared_ctx");
    munmap(file_data, file_size);

    return 0;
}
