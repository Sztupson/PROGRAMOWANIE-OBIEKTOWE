#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define BACKLOG 10
#define BUFSIZE 1024

const char* http_header_template = 
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/plain; charset=UTF-8\r\n"
    "Connection: close\r\n"
    "Content-Length: %d\r\n\r\n";

void handle_client(int client_fd) {
    char buffer[BUFSIZE];

    recv(client_fd, buffer, BUFSIZE - 1, 0);

    FILE* f = fopen("/proc/uptime", "r");
    if (!f) {
        perror("fopen /proc/uptime");
        close(client_fd);
        return;
    }

    double uptime = 0.0;
    fscanf(f, "%lf", &uptime);
    fclose(f);

    char body[64];
    int body_len = snprintf(body, sizeof(body), "%.2f\n", uptime);

    char header[BUFSIZE];
    int header_len = snprintf(header, sizeof(header), http_header_template, body_len);

    send(client_fd, header, header_len, 0);
    send(client_fd, body, body_len, 0);

    shutdown(client_fd, SHUT_WR);
    close(client_fd);
}

int main(int argc, char* argv[]) {
    int port = 80;
    if (argc >= 2) {
        port = atoi(argv[1]);
        if (port <= 0 || port > 65535) {
            fprintf(stderr, "Invalid port number.\n");
            return EXIT_FAILURE;
        }
    }

    if (getuid() == 0) {
        fprintf(stderr, "Nie wolno uruchamiać jako root!\n");
        return EXIT_FAILURE;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);  
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(server_fd);
        return EXIT_FAILURE;
    }

    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Serwer nasłuchuje na porcie %d...\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Połączono z %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(client_fd);
    }

    close(server_fd);
    return EXIT_SUCCESS;
}


// http://localhost:####
