/*
 * abort.c - Demonstrate the abort system call
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    abort();
    /* Shouldn't get here */
    exit(EXIT_SUCCESS);
}
