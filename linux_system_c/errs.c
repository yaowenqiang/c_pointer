/*
 * errs.c - Using perror and strerror
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main(void)
{
    double d;
    char *p;
    errno = 0;
    d = sqrt(-1);

    if (errno) {
        p = strerror(errno);
        fprintf(stderr, "sqrt(-1) %s\n", p);
    }

    errno = 0; /* Reset errno to 0 to catch true errors */
    d = sqrt(-2);
    if (errno) {
        perror("sqrt(-2)");
    }
    exit(EXIT_SUCCESS);
}
