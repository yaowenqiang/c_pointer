/*
 * lpudated-sig.c Simple timestamping daemon that read a config in /etc and handles signals
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
#include <signal.h>

#define RCFILE "/etc/lpudated.conf" /* the config file */
#define BUFLEN 256 /* length of buffer reads */

#define NORMAL 1
#define ROT13 2

/* Read the config file */
int read_config(int rcfd, int *o_style);

int main(void)
{
    pid_t pid, sid;
    time_t timebuf;
    int fd, rcfd, len, o_style;

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

    /* Read the config file */

    if ((rcfd = open(RCFILE, O_RDONLY)) < 0) {
        syslog(LOG_ERR, "%s\n", "error opening  RCFILE \n");
        exit(EXIT_FAILURE);
    } else {
        /* Read the config file */
        char rcbuf[BUFSIZ]; /* Hold the value readed */
        int len; /* the length of the buffer */
        if ((len = read_config(rcfd, &o_style)) < 0) {
            syslog(LOG_ERR, "%s\n", "error opening %RCFILE\n");
            exit(EXIT_FAILURE);
        }

        rcbuf[len] = '\0';

        /* Close the config file */

        if (close(rcfd) < 0) {
            syslog(LOG_ERR, "%s\n", "error closing %RCFILE\n");
            exit(EXIT_FAILURE);
        }
        /* write the read value out to the syslog */
        syslog(LOG_INFO, "%s\n",rcbuf);
    }



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

        sigset_t sigset;
        struct sigaction action;
        int i;

        if (buf == NULL) {
            syslog(LOG_ERR, "%s\n", "malloc");
            exit(EXIT_FAILURE);
        }

        if ((fd = open("/var/log/lpudated2.log",O_CREAT | O_WRONLY | O_APPEND, 0600)) < 0) {
            syslog(LOG_ERR, "%s\n", "open");
            exit(EXIT_FAILURE);
        }

        sigemptyset(&sigset); /* Initialize signal set */
        sigaddset(&sigset, SIGHUP); /* Add SIGHUP to it */
        sigprocmask(SIG_BLOCK, &sigset, NULL); /*block SIGHUP */
        ;

        time(&timebuf);
        strncpy(buf, ctime(&timebuf), len + 1);

        if (o_style == ROT13) {
            for ( i = 0; i < len; ++i) {
                if ((buf[i] >= 'A' && buf[i] <= 'M' )  ||
                    (buf[i] >= 'a' && buf[i] <= 'm' ) ) {
                    buf[i] += 13;
                } else if ((buf[i] >= 'N' && buf[i] <= 'Z' ) ||
                    (buf[i] >= 'n' && buf[i] <= 'z' )) {
                    buf[i] -= 13;

                } 
            } 
        }

        write(fd, buf, len + 1);
        close(fd);

        sigpending(&sigset); /* Check for pending signals */
        if (sigismember(&sigset, SIGHUP)) {
            syslog(LOG_INFO, "received SIGHUP\n");
            /* Ignore SIGHUP */
            sigemptyset(&action.sa_mask);
            action.sa_handler = SIG_IGN;
            sigaction(SIGHUP, &action, NULL);

            /* Reread the configuration file */
            if ((rcfd = open(RCFILE, O_RDONLY)) < 0) {
                syslog(LOG_ERR, "error opening %s\n", RCFILE);
                exit(EXIT_FAILURE);
            } else {
                if (read_config(rcfd, &o_style) < 0)  {
                    syslog(LOG_ERR, "error reading  %s\n", RCFILE);
                    exit(EXIT_FAILURE);
                }

                if (close(rcfd) < 0) {
                    syslog(LOG_ERR, "error closing  %s\n", RCFILE);
                    exit(EXIT_FAILURE);
                }

                /* Unlock SIGHUP */
                sigprocmask(SIG_UNBLOCK, &sigset, NULL);
            }
        }
        sleep(60);
    }

    /* Close the system log and scram */
    closelog();
    exit(EXIT_SUCCESS);
}

int read_config(int rcfd, int *o_style)
{
    char rcbuf[BUFLEN]; /* Hold the value read */
    int len; /* the length of the buffer */

    /* read the config file */
    if ((len = read(rcfd, rcbuf, BUFLEN)) < 0) {
        syslog(LOG_ERR, "error reading  %s\n", RCFILE);
        return 1;
    }

    rcbuf[len] = '\0';
    /* Determine what we read */
    if (0 == strncmp(rcbuf, "rot13", 5) ) { /* want rot13 output */
        *o_style = ROT13;
        syslog(LOG_INFO, "output style is rot13\n");
    } else if (0 == strncmp(rcbuf, "normal", 6)) { /* want normal output */
        *o_style = NORMAL;
        syslog(LOG_INFO, "output style is normal\n");
    } else {
        syslog(LOG_INFO, "invalid  output style %d\n", *o_style);
        return 2;
    }
    return 0;
}
