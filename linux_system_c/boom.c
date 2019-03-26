/*
 * boom.c -  abort in action
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("About to abort!\n");
    abort();
    puts("I reckon it worked.\n") ;/* Nerver get here */
    exit(EXIT_SUCCESS);
}
