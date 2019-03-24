/*
 * blunder.c - Mistakes caught by -W(warning)
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, j;
    printf("%c=n", "Not a character"); /* -Wformat */

    if (i = 10)    /* -Wparentheses */
        printf("oops\n");
    
    if (j != 0)   /* -Wuninitialized */
      printf("another oops\n");

    /* /* */    /* -Wcomment */
    no_decl();  /* -Wmissing-declaration */
    
    return(EXIT_SUCCESS);
}
void no_decl(void)
{
    printf("no_decl\n");
}
