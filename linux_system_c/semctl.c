/*
 * semctl.c - Manipuate and delete a semaphore
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int semid; /* Semaphore identifier */
    if (argc != 2) {
        puts("Usage: semctl <semphore id>");
        exit(EXIT_FAILURE);
    }

    semid = atoi(argv[1]);
    printf("%d \n", semid);

    /* Remove the semaphore */
    if ((semctl(semid, 0, IPC_RMID)) < 0) {
        perror("semctl IPC_RMID");
        exit(EXIT_FAILURE);
    } else {
        puts("semphaore removed");
        system("ipcs -m");
    }
    return 0;
}
