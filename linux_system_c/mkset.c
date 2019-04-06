/*
 * mkset.c - Create a signal set
 */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void err_quit(char *);

int main(void)
{
    sigset_t newset;
    /* Create the set */

    if ((sigemptyset(&newset)) < 0) {
        err_quit("sigemptyset"); 
    }

    /* add SIGNCHLD to the set */

    if ((sigaddset(&newset , SIGCHLD)) < 0) {
        err_quit("sigaddset") ;
    }
    /* Check the signal mask */

    if (sigismember(&newset, SIGCHLD))  {
        puts("SIGNCHLD is in signal mask") ;       
    } else {
        puts("SIGNCHLD not in signal mask") ;       
    }

    /* SIGTERM shouldn't be there */
    if (sigismember(&newset , SIGTERM)) {
        puts("SIGTERM in signal task");
    } else {
        puts("SIGTERM not in signal task");
    }
    exit(EXIT_SUCCESS);
}

void err_quit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
