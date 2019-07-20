/*
 * fit.c 
 */
#include <stdio.h>
#include <string.h>

void fit(char *, unsigned int );

int main(void)
{
    char  strings[] = "Things should be as simple as possible,"
                      "but not simpler.";
    puts(strings);
    fit(strings, 38);
    puts(strings);
    puts("Let's look at some more of the string.");
    puts(strings + 39);
    return 0;
}

void fit(char *string, unsigned int size)
{
    if(strlen(string) > size)
    {
        string[size] = '\0';
    }
}
