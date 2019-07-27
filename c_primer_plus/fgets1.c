/*
 * fgets1.c - 使用fgets()和fputs()
 */

#include <stdio.h>
#define STLEN 14
int main(void)
{
    char words[STLEN];
    puts("Enter a string please");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs())\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please!");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs())\n");
    puts(words);
    fputs(words, stdout);
    int i = 0;
    while(words[i]) {
        printf("%d\n", words[i]);
        i++;
    }
    printf("%d\n", '\0');
    puts("Done.");
    char tmp[] = "a";
    printf("%d\n", tmp[0]);
    printf("%d\n", tmp[1]);
    printf("%d\n", tmp[2]);
    printf("%d\n", tmp[2]);

    char * mystr = "h";
    printf("%s\n", mystr);

    return 0;
}
