/*
 * resusg2.c - Getting resource usage with getrusage
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>
void err_quit(char *);
void doit(char *str, clock_t time);

int main(void)
{
    struct rusage usage;
    /* redirect output to prevent screen clutter */
    system("grep linux /usr/share/doc/*/* > /dev/null 2> /dev/null");
    /* get the resource structure for the parent */
    if ((getrusage(RUSAGE_SELF, &usage)) == -1) {
        err_quit("getrusage"); 
    }
    puts("parent times");
    doit("\tUser CPU", usage.ru_utime.tv_sec);
    doit("\tsys CPU", usage.ru_stime.tv_sec);

    puts("parent memory stats");
    doit("\tminor faults", usage.ru_minflt);
    doit("\tmajor faults", usage.ru_majflt);
    doit("\tpage swaps", usage.ru_nswap);

    /* get the resource structure for the child */
    if ((getrusage(RUSAGE_CHILDREN, &usage)) == -1) {
        err_quit("getrusage"); 
    }
    puts("child times");
    doit("\tUser CPU", usage.ru_utime.tv_sec);
    doit("\tsys CPU", usage.ru_stime.tv_sec);

    puts("child memory stats");
    doit("\tminor faults", usage.ru_minflt);
    doit("\tmajor faults", usage.ru_majflt);
    doit("\tpage swaps", usage.ru_nswap);
    
}
void doit(char *str, long reaval)
{
    printf("%s: %ld\n", str, reaval);
}

void err_quit(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}
