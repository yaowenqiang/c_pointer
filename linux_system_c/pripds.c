/*
 * pripds.c - Print PID and PPID
 */

#include <stdio.h>  
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("PID = %d\n", getpid());
    printf("PPID = %d\n", getppid());
    printf("Real UID = %d\n", getuid());
    printf("effective UID = %d\n", geteuid());
    printf("Real GID = %d\n", getgid());
    printf("effective GID = %d\n", getegid());
    exit(EXIT_SUCCESS);
}
