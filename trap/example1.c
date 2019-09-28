/*
 * = and ==
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    FILE *f = fopen("a.txt", "r");
    while (c = ' ' || c == '\t' || c == '\n') {
        c = getc(f); 
        if ( c == EOF) {
            puts("empty file");
            exit(EXIT_FAILURE);
        } else {
            putchar(c);
            putchar('\n');
        }
    }
    return 0;
}
