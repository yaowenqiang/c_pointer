/*
 * udb_sender.c - udp send demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int port = 6789;
void main()
{
    int socket_descriptor;
    int iter = 0;
    char buf[80];
    struct sockaddr_in address;

    /*
     * Initialize socket address structure for Internet Protocols
     */

    bzero(&address, sizeof(address)); /* empty data structure */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port =  htons(port);

    /*
     * create a UDP socket 
     */

    socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);

    /*
     * loop 20 times (a nice round number) sending data.
     */


    /*
     * loop 20 times (a nice round number) sending data.
     * */

    for (iter = 0; iter < 20; iter++) {
        sprintf(buf, "Data packet with ID %d\n", iter);
        sendto(socket_descriptor, buf, sizeof(buf),0, (struct sockaddr *)&address, sizeof(address));
    }

    /*
     * send a termination message
     */

    sprintf(buf, "stop\n");
    sendto(socket_descriptor, buf, sizeof(buf), 0, (struct sockaddr *)&address, sizeof(address));
    close(socket_descriptor);
    printf("Message Sent: Terminating\n");
    exit(0);


}
