#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

#define _OPEN_SYS
#define TAB_LENGTH 10

typedef struct shared {
    int tab[TAB_LENGTH];
    pthread_mutex_t mutex;
} shared_t;

int main(int argc, char *argv[]) {
    struct stat statbuf;
    printf("argc=%d\n Wymagana liczba argumentów: 3 \n", argc);

    int fd = open(argv[1], O_RDONLY);
    fstat(fd, &statbuf);
    char *content = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);

    
    int prot = PROT_READ | PROT_WRITE;
    int vis = MAP_SHARED | MAP_ANONYMOUS;
    shared_t *shr = (shared_t*)mmap(NULL, sizeof(shared_t), prot, vis, -1, 0);
    if (shr == NULL)
        return -1;

    for (int i = 0; i < TAB_LENGTH; i++) {
        shr->tab[i] = 0;
    }

    pthread_mutexattr_t mutexattr;
    if (pthread_mutexattr_init(&mutexattr) != 0)
        return -2;
    if (pthread_mutexattr_setpshared(&mutexattr, PTHREAD_PROCESS_SHARED) != 0)
        return -3;
    if (pthread_mutex_init(&shr->mutex, &mutexattr) != 0)
        return -4;

    for (int i = 0; i < statbuf.st_size; i++) {
        if (content[i] >= '0' && content[i] <= '9') { 
            int val = content[i] - '0';
            shr->tab[val]++;
        }
    }
    char* endptr;
    int buff_size = 0;
    int num_args = strtol(argv[2], &endptr, 10);
    int* tab = (int*)(malloc(sizeof(int)*num_args));
    printf("%ld",statbuf.st_size);
    if (*endptr != '\0'){
        printf("second argument is not a number");
        return -1;
    }
    pid_t pid;
    int rest = statbuf.st_size % num_args;
    int file_pieces = statbuf.st_size / num_args;
    for (int i = 0; i < num_args; i++){
        if (i+1 == num_args){
            buff_size += (statbuf.st_size + rest);
        }else{
             buff_size += statbuf.st_size;
        }
       
        pid = fork();
        tab[i] = getpid();
        if (pid == -1){
            perror("Failed to create new process");
            return -1;
        }
        if (pid == 0){
            for(int j = 0; j < buff_size; j + buff_size){
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

if (pid > 0){
    for (int i = 0; i < TAB_LENGTH; i++) {
        printf("%d = %d\n", i, shr->tab[i]);
    }
    for (int i = 0; i < num_args; i++){
        waitpid(tab[i], NULL, 0);
    }
    
    pthread_mutex_destroy(&shr->mutex);
    munmap(content, statbuf.st_size);
    munmap(shr, sizeof(shared_t));
    close(fd);
    pthread_mutexattr_destroy(&mutexattr);
    
}
    return 0;
}