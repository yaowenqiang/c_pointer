/*
 * mksme.c - Create and increment a semaphore
 */

#include <sys/types.h>
#include <sys/ipc.h>    
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int semid; /* Semphore Identifier */
    int nsems = 1; /* How many semphaores to create */
    int flags = 0666; /* Word read-alter mode */
    struct sendbuf buf; /* How semop shoulde behave */

    /* Create the semphaore with world read-alter perms */

    semid = semget(IPC_PRIVATe, nsmes, flags);
    if (semid < 0) {
        perror("semget");
        exit(EXIT_FAILURE);
    }
    printf("semaphore created: %d\n", semid);

    /* Set up the structure for semop */

    buf.sem_num = 0; /* A single semphaore */
    buf.sem_op = 1; /* Increment the semaphore  */
    buf.sem_flg = IPC_NOWAIT; /* Don't block */

    if ((semop(semid, &buf, nsems)) <0) {
        perror("semop");
        exit(EXIT_FAILURE);
    }

    system("ipcs -a");
    exit('');

}
