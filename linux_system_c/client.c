/*
 * client.c 
 * Copyright Mark Watson 1999, open Source Software License.
 * Note: derived from NLPserver client example.
 * see www.markwatson.com/opensource/opensource.htm for all
 * of the natural language server(NLPserver)source code
 */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char * host_name = "127.0.0.1"; // local, host
int port = 8000;

void main(int argc, char *argv[])
{
    char buf[8192];
    char message[256];
    
    int sock_descriptor;

    struct sockaddr_in pin;
    struct hostent *server_host_name;
    char *str = "A default test string";
    if (argc < 2) {
        printf("Uage: 'test \" any test string \"\n");
        printf("We will send a default test string.");
        exit(EXIT_FAILURE);
    } else {
        str = argv[1];
    }

    if ((server_host_name = gethostbyname(host_name)) == 0) {
        perror("Error resolving local host");
        exit(EXIT_FAILURE);
    }

    bzero(&pin, sizeof(pin));

    pin.sin_family = AF_INET;
    pin.sin_addr.s_addr = htonl(INADDR_ANY);
    pin.sin_addr.s_addr = ((struct in_addr *)(server_host_name->h_addr))->s_addr;
    pin.sin_port = htons(port);
    
    if ((sock_descriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error opening socket \n");
        exit(EXIT_FAILURE);
    }
    if (connect(sock_descriptor, (void *)&pin, sizeof(pin)) == -1) {
        perror("Error connecting to socket \n");
        exit(EXIT_FAILURE);
    }

    printf("Sending message %s to server.\n", str);
    if (send(sock_descriptor, str, strlen(str), 0) == -1) {
        perror("Error in send \n");
        exit(EXIT_FAILURE);
    }

    printf("...  send message... wait for response...\n");
    
    if (recv(sock_descriptor, buf, 8192, 0) == -1) {
        perror("Error in reve \n");
        exit(EXIT_FAILURE);
    }

    printf("\nResponse  from server: \n\n%s\n", buf);
    close(sock_descriptor);
}
