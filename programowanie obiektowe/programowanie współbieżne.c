#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define TAB_LENGTH 10
#define DIGIT_COUNT 10


struct context {
    unsigned long count[DIGIT_COUNT];
    pthread_mutex_t mutex;
};

typedef struct shared {
    int tab[TAB_LENGTH];
    pthread_mutex_t mutex;
} shared_t;

void child(shared_t *shr) {
    int n = 0;
    while(1) {
        pthread_mutex_lock(&shr->mutex);
        for (int i = 0; i < TAB_LENGTH; i++)
            shr->tab[i] = n;
        pthread_mutex_unlock(&shr->mutex);
        n++;
    }
}

void parent(shared_t *shr) {
    int n = 0; //
    while(1) {
        pthread_mutex_lock(&shr->mutex);
        for (int i = 0; i < TAB_LENGTH; i++)
            printf("%d ", shr->tab[i]);
        pthread_mutex_unlock(&shr->mutex);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {    
    struct stat statbuf;
    if (argc != 3) { fprintf(stderr, "Kolejnosc: <program> <sciezka pliku> <ilosc procesow>\n", argv[0]); return 1; }

    int process_count = atoi(argv[2]);
    if (process_count < 1) { fprintf(stderr, "Liczba procesow musi byc >= 1\n"); return 1; }    
    printf("argc=%d\n", argc);

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) { perror("Error opening file"); return 1; }
    printf("fd=%d\n", fd);
    fstat(fd, &statbuf); /* TODO: sprawdzic ret value */
    printf("len=%d\n", statbuf.st_size);
    char *content = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    printf("content ptr=%p\n", content);
    /* TODO: sprawdzic ret value z mmap */
    for (int i = 0; i < statbuf.st_size; i++)
    {
        /* [48, 57] */
        if (content[i] >= '0' && content[i] <= '9') { 
            int val = content[i] - '0'; /* content[i] - 48 */
            /* Zwiększyć odpowiednią wartość w tablicy,
               która zlicza ilość wystąpień */
            printf("%d", val);
        }
    } 
    munmap(content, statbuf.st_size);
    close(fd);


    int prot = PROT_READ | PROT_WRITE; // odczyt i zapis
    int vis = MAP_SHARED | MAP_ANONYMOUS;
    shared_t *shr = (shared_t*)mmap(NULL, sizeof(shared_t), prot, vis, -1, 0);
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
    munmap(shr, sizeof(shared_t));
    return 0;
}