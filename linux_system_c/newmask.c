/*
 * newmask.c - Change the umask
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    mode_t newmask = 0222, oldmask;
    system("touch before");
    oldmask = umask(newmask);
    printf("old umask is %#o\n", oldmask);
    printf("new mask is %#o\n", newmask);
    system("touch after");
    exit(EXIT_SUCCESS);
}


