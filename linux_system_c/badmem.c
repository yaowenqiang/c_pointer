/*
 * badmem.c - Demonstrate usage of memory debugging tools
 */
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

char g_buf[5];

int main(void)
{
    char *buf;
    char *leak;
    char l_buf[5];
    /* won't free this */

    leak = malloc(10);

    /* overrun buf a little bit */ 
    buf = malloc(5);
    strcpy(buf, "abcde");
    printf("LITTLE: %s\n", buf);

    /* overrun buf a lot */

    buf = malloc(5);

    strcpy(buf, "abcdefgh");
    //fprintf("BIG:     %s\n", buf);

    /* underrun buf */
    *(buf - 2) = '\0';
    printf("UNDERRUN: %s\n", buf);

    /* free buf twice */
    free(buf);
    free(buf);

    /* access fredd memory */
    strcpy(buf, "This will blow up");
    printf("GLOBAL    : %s\n", g_buf);

    /* trash the local variable */

    strcpy(l_buf, "local boom");
    printf("LOCAL    :   %s\n", l_buf);

    exit(EXIT_SUCCESS);
}
