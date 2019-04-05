/* mplex.c - read input from pipe1 and pip2 using select
 * Adapted from mpx-select.c written
 * by Mhchael Johnson and Erik Troan, Used with the permission of 
 * the authors of Linux Application Development,
 * Michael Johnson and Erik Troan
 * cd /tmp; mknode pipe1 p;mknod pipe2 p
 * cat > pipe1
 * cat > pip2
 * ./mplex
 */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSZ 80

void err_quit(char *msg);

int main(void)
{
    int fds[2];
    char buf[BUFSZ];
    int i, rc, maxfd;

    fd_set watchset; /* Read this set of file descriptors */
    fd_set inset; /* Copy of watchset for select to update */
    /* Open the pipes */
    if ((fds[0] = open("/tmp/pipe1", O_RDONLY | O_NONBLOCK)) < 0) {
        err_quit("Open pipe1");
    }
    if ((fds[1] = open("/tmp/pipe2", O_RDONLY | O_NONBLOCK)) < 0) {
        err_quit("Open pipe2");
    }
    /* Initialize watchset with our file descriptors */
    FD_ZERO(&watchset);
    FD_SET(fds[0], &watchset);
    FD_SET(fds[1], &watchset);

    /* select needs to know the maximum file descriptors */
    maxfd = fds[0] > fds[1] ? fds[0] : fds[1];
    /* Loop while watching the pipes for output to read */
    while (FD_ISSET(fds[0], &watchset) || FD_ISSET(fds[1], &watchset)) {
        /* Make sure select has a current set of descriptors */
        inset = watchset;
        if (select(maxfd +1, &inset, NULL,NULL, NULL) < 0) {
            err_quit("select");
        }
        /* Watch file descriptors is read to read? */
        for (i = 0; i < 2; ++ i)  {
            if (FD_ISSET(fds[i],&inset)) {
                rc = read(fds[i],buf,BUFSZ-1);
                if (rc > 0) {/* Read some data */
                    buf[rc] = '\0';
                    printf("reads %s", buf);
                } else if (rc == 0) { /* This pipe is closed */
                    close(fds[i]);
                    FD_CLR(fds[i], &watchset);
                } else {
                    err_quit("read"); /* Bummer */
                }
            }
        }
    }
    exit(EXIT_SUCCESS);
}

void err_quit(char *msg) 
{
    perror(msg);
    exit(EXIT_FAILURE);
}
