/*
 * badptr.c - Testing assert
 */
#include <stdio.h>
#define NDEBUG
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    FILE *fp;
    fp = fopen("foo_bar","w"); /* This should work */
    assert(fp);
    fclose(fp);

    fp = fopen("bar_baz","r"); /* This should fail */
    assert(fp); 
    fclose(fp); /* Should never get here */

    exit(EXIT_FAILURE);
}
