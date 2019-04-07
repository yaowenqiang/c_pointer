/*
 * newfifo.c - Create a FIFO
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const* argv[])
{
    mode_t mode = 0666;
    if (argc != 2) {
        puts("USAGE: newfifo {name} ");
        exit(EXIT_FAILURE);
    }
    if ((mkfifo(argv[1], mode)) < 0) {
        perror("fifo");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
