/*
 * cypher1.c - 改变输入，只保留其中的空格.
 */

#include <stdio.h>
#define SPACE ' '
int main(void)
{
    char ch;
    ch = getchar();
    while (ch != '\n') 
    {
        if (ch == SPACE) {
            putchar(ch);
        } else {
            putchar(ch + 1);
        }
        ch = getchar();
    }
    putchar(ch);
    return 0;
}
