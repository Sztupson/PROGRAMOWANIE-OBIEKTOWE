#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

char* buffer;
char* filePath;

int program = 1;

void loadFile() {
    if (filePath == NULL) {
        fprintf(stderr, "Nie wczytano sciezki do pliku.\n"); 
        return;
    }
    FILE *f = fopen(filePath, "r");
    if (f == NULL) {
        fprintf(stderr, "Blad: Nie mozna otworzyc pliku: %s\n", filePath); 
        return;
    }

    free(buffer);
    buffer = NULL;

    fseek(f, 0, SEEK_END);
    size_t fileSize = ftell(f);
    rewind(f);

    buffer = malloc(fileSize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Bd alokacji pamięci.\n");
        fclose(f);
        return;
    }

    fread(buffer, 1, fileSize, f);
    buffer[fileSize] = '\0';
    fclose(f);

    printf("Plik wczytany do bufora.\n");
}

void signalManager (int signal) {
    switch (signal) {
        case SIGUSR1:
            printf("Sygnal SIGUSR1: Wczytywanie pliku na nowo.\n");
            loadFile();
            break;
        case SIGUSR2:
            printf("Sygnal SIGUSR2: Czyszczenie bufora.\n");
            free(buffer);
            buffer = NULL;
            break;
        case SIGINT:
            printf("\nSygnal SIGINT. Czy chcesz zakończyć program? (y/n): ");
            char choice;
            choice = getchar();
            if (choice == 'y' || choice == 'Y') {
                program = 0;
            }
            break;
        default:
            break;
    }
}


int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Blad: Nie wczytano sciezki do pliku\n");
        return -1;
        }
    filePath = argv[1];
    loadFile();


    signal(SIGUSR1, signalManager);
    signal(SIGUSR2, signalManager);
    signal(SIGINT, signalManager);

    while (program == 1) {
        if (buffer != NULL) {
            printf("\nZawartosc bufora:\n %s \n", buffer);
        } else {
            printf("Bufor jest pusty.\n");
        }
    printf("\n ==================== \n");
    sleep(1);
    }
    printf("Koniec programu");


    free(buffer);
    return 0;
}