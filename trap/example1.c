/*
 * = and ==
 */

#include <stdio.h>

int main(void)
{
    char c;
    FILE *f = fopen("a.txt", "r");
    while (c = ' ' || c == '\t' || c == '\n') {
        c = getc(f); 
    }
    return 0;
}
