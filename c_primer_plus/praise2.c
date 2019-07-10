/*
 * praise2.c
 */

#include <stdio.h>
#include <string.h>
#define PRAISE "what a super marelous name!"

int main(void)
{
    char name[40];
    printf("%lu\n", strlen(name));
    printf("%lu\n", sizeof(name));
    //name[40] = '\0';
    printf("%s\n", name);

    printf("%lu\n", strlen(PRAISE));
    printf("%lu\n", sizeof(PRAISE));
    
    char x = 'x';
    char y[1] = "y";
    printf("%c\n", x);
    printf("%ld\n", sizeof(x));
    printf("%s\n", y);
    printf("%lu\n", sizeof(y));
}

