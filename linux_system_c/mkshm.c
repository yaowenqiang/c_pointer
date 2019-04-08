/*
 * mkshm.c - Create and initialize shared memory segment
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSZ 4096  /* Size of the segmen t*/ 

int main(void)
{
    int shmid;
    if ((shmid = shmget(IPC_PRIVATE, BUFSZ, 0666)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("segment create: %d\n", shmid);
    system("ipcs -m");
    exit(EXIT_SUCCESS);
}

