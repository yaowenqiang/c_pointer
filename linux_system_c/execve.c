/*
 * execve.c - illustrate execve
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *args[] = {"/bin/ls", NULL};
    if (execve("/bin/ls", args, NULL) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }  
    puts("shouldn't get here");
    exit(EXIT_SUCCESS);
    /* execl("/bin/cat","/bin/cat","/etc/passwd","/etc/group", NULL); */
    /*
     * char *argv[] = {"/bin/cat","/etc/passwd","/etc/group",NULl;
     * execv("/bin/cat/", argv);)
     */

    /*
     * char *envp[] = {"PATH=/bin;/usr/bin","USR=joblow",NULL};
     */
}
