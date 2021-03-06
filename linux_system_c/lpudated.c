/*
 * lpudated.c - Simple timestamping daemon
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <time.h>

int main(void)
{
    pid_t pid, sid;
    time_t timebuf;
    int fd, len;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid >0) {
        /* In the parent Let's bail */
        exit(EXIT_SUCCESS);
    } 

    /* In the child */
    /* First, start a new session */

    if ((sid = setsid()) < 0) {
        perror("setsid");
        exit(EXIT_FAILURE);
    } 

    /* Next, make / the current directory */

    if ((chdir("/")) < 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    /* Reset the file mode */
    umask(0);

    /* Close unneeded file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    /* Finally, do our work */

    len = strlen(ctime(&timebuf));
    while(1) {
        char *buf = malloc(sizeof(char) * (len + 1));
        if (buf == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        if ((fd = open("/var/log/lpudated.log",O_CREAT | O_WRONLY | O_APPEND, 0600)) < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        time(&timebuf);
        strncpy(buf, ctime(&timebuf), len + 1);
        write(fd, buf, len + 1);
        close(fd);
        sleep(60);
    }
    exit(EXIT_SUCCESS);
}
