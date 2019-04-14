/*
 * atshm.c - Attaching a shared memory segment
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const* argv[])
{
    int shmid; /* Segment ID */
    char *shmbuf; /* address in progress */

    /* Expect an segment id on the command line */
/*
    if (argc != 2) {
        puts("USAGE: atshm <identifier>");
        exit(EXIT_FAILURE);
    }
*/
    //shmid = atoi(argv[1]);

    if ((shmid = shmget(IPC_PRIVATE, BUFSIZ, 0666)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", shmid);


    /* Attach the segment */
    if ((shmbuf = shmat(shmid, 0, SHM_RDONLY)) < (char *)0) {
        perror("shmat");
        exit(EXIT_FAILURE);

    }

    /* Where is  it attached? */
    printf("segment attached at %p\n", shmbuf);

    /* See, we really are attached */

    system("ipcs -m");

    /* Detch */
    if ((shmdt(shmbuf)) < 0) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    puts("segment detched");

    /* Yep, we really did detch it */

    system("ipcs -m");

    exit(EXIT_SUCCESS);

}
