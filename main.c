#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8080

int main () {
    int server_filedesc;
    int host_socket;
    int client_socket;

    struct sockaddr_in address;
    int address_length = sizeof(address);

    char buffer[1024] = {0};
    char *response = "HTTP/1.1 200 OK \r\nContent-Type: text/plain\r\n\r\nHelo. Dis is server in C!";

    host_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(!host_socket) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // ip 0.0.0.0 (0x00000000)
    address.sin_port = htons(PORT);

    if(bind(server_filedesc, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Binding failed!");
        exit(EXIT_FAILURE);
    }


    return 0;
}