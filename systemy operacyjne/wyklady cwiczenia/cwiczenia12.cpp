#include <iostream>
#include <fstream>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdlib>
#include <cstring>
#include <sys/wait.h>
#include <thread>

#define TAB_LENGTH 10

struct Shared {
    int tab[TAB_LENGTH];
    pthread_mutex_t mutex;
};

int main(int argc, char *argv[]) {
    struct stat statbuf;
    std::cout << "argc=" << argc << "\n Wymagana liczba argumentów: 3\n";

    if (argc != 3) {
        std::cerr << "Invalid number of arguments.\n";
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return -1;
    }

    fstat(fd, &statbuf);
    char *content = static_cast<char*>(mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0));
    if (content == MAP_FAILED) {
        perror("Failed to map file");
        return -1;
    }

    int prot = PROT_READ | PROT_WRITE;
    int vis = MAP_SHARED | MAP_ANONYMOUS;
    Shared *shr = static_cast<Shared*>(mmap(NULL, sizeof(Shared), prot, vis, -1, 0));
    if (shr == MAP_FAILED) {
        perror("Failed to map shared memory");
        return -1;
    }

    std::memset(shr->tab, 0, sizeof(shr->tab));

    pthread_mutexattr_t mutexattr;
    if (pthread_mutexattr_init(&mutexattr) != 0) return -2;
    if (pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED) != 0) return -3;
    if (pthread_mutex_init(&shr->mutex, &mutexattr) != 0) return -4;

    for (int i = 0; i < statbuf.st_size; ++i) {
        if (content[i] >= '0' && content[i] <= '9') {
            int val = content[i] - '0';
            shr->tab[val]++;
        }
    }

    char* endptr;
    int num_args = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0') {
        std::cerr << "Second argument is not a number\n";
        return -1;
    }

    std::vector<int> tab(num_args);
    pid_t pid;
    int rest = statbuf.st_size % num_args;
    int file_pieces = statbuf.st_size / num_args;
    int buff_size = 0;

    for (int i = 0; i < num_args; ++i) {
        if (i + 1 == num_args) {
            buff_size += (statbuf.st_size + rest);
        } else {
            buff_size += file_pieces;
        }

        pid = fork();
        tab[i] = getpid();
        if (pid == -1) {
            perror("Failed to create new process");
            return -1;
        }
        if (pid == 0) {
            for (int j = 0; j < buff_size; ++j) {
                if (content[j] >= '0' && content[j] <= '9') {
                    int val = content[j] - '0';
                    pthread_mutex_lock(&shr->mutex);
                    shr->tab[val]++;
                    pthread_mutex_unlock(&shr->mutex);
                }
            }
            exit(0);
        }
    }

    if (pid > 0) {
        for (int i = 0; i < TAB_LENGTH; ++i) {
            std::cout << i << " = " << shr->tab[i] << "\n";
        }
        for (int i = 0; i < num_args; ++i) {
            waitpid(tab[i], NULL, 0);
        }

        pthread_mutex_destroy(&shr->mutex);
        munmap(content, statbuf.st_size);
        munmap(shr, sizeof(Shared));
        close(fd);
        pthread_mutexattr_destroy(&mutexattr);
    }

    return 0;
}
