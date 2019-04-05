/*
 * env.c - setenv and getenv demo
 */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char envval[] = {"MYPATH=/usr/local/someapp/bin"};
    if (putenv(envval) == 0) {
        puts("putenv succeeded");
    }

    if (getenv("MYPATH")) {
       printf("MYPATH=%s\n", getenv("MYPATH")); 
    } else {
        puts("MYPATH unassigned");
    }
}

