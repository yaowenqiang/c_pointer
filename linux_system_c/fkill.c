/*
 * fkill.c - Send a signal using kill(2)
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

int main(void)
{
    pid_t child;
    int errret;
    if ((child = fork()) <0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child == 0) { /* in the child process */
        sleep(30);
    } else { /* in the parent */
        /* send a signal that gets ignored */
        printf("sending SIGNCHLD to %d\n", child);
        errret = kill(child, SIGCHLD);
        if (errret < 0) {
            perror("kill:SIGNCHLD"); 
        } else {
            printf("%d still alive\n", child);
            /* now kill the child process */
            printf("killing %d\n", child);
            if ((kill(child, SIGTERM)) < 0) {
                perror("kill:SIGNTERM");
                /* have to wait to reap the status */
                waitpid(child, NULL, 0);
            }
        }
    }
    exit(EXIT_SUCCESS);
}
