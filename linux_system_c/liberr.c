/*
 * liberr.c
 * Implementation of error-handling library
 */
#include <errno.h> /* errno */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liberr.h"

void err_ret(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    err_prn(fmt, ap, NULL);
    va_end(ap);
    return;
}

void err_quit(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_prn(fmt, ap, NULL);
    va_end(ap);
    exit(EXIT_FAILURE);
}

void log_ret(char *logfile, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_prn(fmt, ap, NULL);
    va_end(ap);
    return;
}

void log_quit(char *logfile, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_prn(fmt, ap, NULL);
    va_end(ap);
    exit(EXIT_FAILURE);
}

//extern void err_prn(const char *fmt, va_list ap, char *logfile)
void err_prn(const char *fmt, va_list ap, char *logfile)
{
    int save_err;
    char buf[MAXLINELEN];
    FILE *plf;

    save_err = errno; /* value caller might want printed */
    vsprintf(buf, fmt, ap);
    sprintf(buf + strlen(buf), ":%s", strerror(save_err));
    strcat(buf, "\n");

    fflush(stdout); /* in case stdout and stderr are the same */
    if(logfile != NULL) {
        if((plf = fopen(logfile, "a")) != NULL) {
           fputs(buf, plf);
           fclose(plf);
      } else {
          fputs("failed to open log file \n", stderr);
      }
    } else {
          fputs(buf, stderr);
    }

    fputs(buf, stderr);
    fflush(NULL); /* flush everything */
    return;
}

