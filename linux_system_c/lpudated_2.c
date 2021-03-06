/*
 * lpudated_2.c Simple timestamping daemon
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <syslog.h>

int main(void)
{
    pid_t pid, sid;
    time_t timebuf;
    int fd, len;

    pid = fork();
    if (pid < 0) {
        syslog(LOG_ERR, "%s\n", "fork");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        /* In the parent, Let's bail */
        exit(EXIT_SUCCESS);
    }
    /* In The child */
    /* Open the system log */
    openlog("lpudated", LOG_PID, LOG_DAEMON);

    /* First start a new session */
    if ((sid = setsid()) < 0) {
        syslog(LOG_ERR, "%s\n", "setsid");
        exit(EXIT_FAILURE);
    }
    /* Next make / the current directory */
    if ((chdir("/")) < 0) {
        syslog(LOG_ERR, "%s\n", "chdir");
        exit(EXIT_FAILURE);
    }
    /* Reset the file mode */
    umask(0);
    /* Close unneeded file descriptors */
    close(STDIN_FILENO);
    close(STDERR_FILENO);
    close(STDOUT_FILENO);

    /* Finally, do our work */

    len = strlen(ctime(&timebuf));

    while (1) {
        char *buf = malloc(sizeof(char) * (len + 1));
        if (buf == NULL) {
            syslog(LOG_ERR, "%s\n", "malloc");
            exit(EXIT_FAILURE);
        }

        if ((fd = open("/var/log/lpudated2.log",O_CREAT | O_WRONLY | O_APPEND, 0600)) < 0) {
            syslog(LOG_ERR, "%s\n", "open");
            exit(EXIT_FAILURE);
        }

        time(&timebuf);
        strncpy(buf, ctime(&timebuf), len + 1);

        write(fd, buf, len + 1);
        close(fd);
        sleep(60);
    }

    /* Close the system log and scram */
    closelog();
    exit(EXIT_SUCCESS);
}
