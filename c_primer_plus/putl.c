/*
 * putl.c -- 打印字符串，不添加\n
 */

#include <stdio.h>
void putl(const char * string)
{
    while (*string != '\0') {
        putchar(*string++);
    }
}

int main(void)
{
    char * words = "i am a word";
    putl(words);
    return 0;
}
