/*
 * fgets2.c - 使用fgets()和fputs()
 */

#include <stdio.h>
#define SLEN 10
int main(void)
{
    char words[SLEN];
    puts("Enter strings (empty line to quit.)");
    while(fgets(words, SLEN, stdin) != NULL && words[0] != '\n') {
        fputs(words, stdout);
    }
    puts("Done");
    return 0;
}
