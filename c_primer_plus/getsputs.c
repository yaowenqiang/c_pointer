/*
 * getsputs.c -  使用gets() 和 puts()
 */
#include <stdio.h>
#define STRLEN  5
int main(void)
{
    char words[STRLEN];
    puts("Enter a string, please");
    gets(words);
    printf("Your string twise:\n");
    puts(words);
    puts("Donw");
    return 0;
}
