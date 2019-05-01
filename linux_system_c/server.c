/*
 * server.c 
 * Copyright Mark Watson 1999, open Source Software License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int port = 8000;

int main(void)
{
    struct sockaddr_in sin;
    struct sockaddr_in pin;

    int sock_descriptor;
    int temp_sock_descriptor;

    //int address_size;
    socklen_t address_size;
    char buf[16384];
    int i, len;

    sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_descriptor == -1) {
        perror("call to socket");
        //exit(1);
        
        exit(EXIT_FAILURE);
    }
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);

    if (bind(sock_descriptor, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("call to bind");
        exit(EXIT_FAILURE);
    }
    if (listen(sock_descriptor, 20) == -1) {
        perror("call to listen");
        exit(EXIT_FAILURE);
    }

    printf("Accepting connection ...\n");

    while (1) {
        temp_sock_descriptor = accept(sock_descriptor, (struct sockaddr *)&pin, &address_size);
        if (temp_sock_descriptor == -1) {
            perror("call to accept");
            exit(1);
        }
        if (recv(temp_sock_descriptor, buf, 16384, 0) == -1) {
            perror("call to recv");
            exit(1);
        }

        printf("received from client: %s\n", buf);

        // for this server example, we just conver the 
        // characters to upper case;

        len = strlen(buf);
        for ( i = 0; i < len; i++) {
            buf[i] = toupper(buf[i]);
        }

        if (send(temp_sock_descriptor, buf, len ,0) == -1) {
            perror("call to send");
            exit(1);
        }

        close(temp_sock_descriptor);
    }
}
