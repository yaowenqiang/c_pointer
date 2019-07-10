/*
 * efences.c - demonstrate the  electric fence demo 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = (char *) malloc(1024);
    ptr[0] = 0;

    /* Now write beyond the block */
    ptr[1025] = 0;
    ptr[111025] = 0;
    exit(0);
}
