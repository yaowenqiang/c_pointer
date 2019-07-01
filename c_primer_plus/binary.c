/*
 * binary.c - 以二进制开式输出整数
 */

#include <stdio.h>
void to_binary(unsigned long n);

int main(void)
{
    unsigned long number;

    printf("Enter an integer (q to quite)\n");
    while ((scanf("%ld", &number)) == 1) {
        printf("Binary equivalent: \n"); 
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit).\n");
    }
    printf("Done\n");
    return 0;
}

void to_binary(unsigned long n)
{
    int r;
    r = n % 2;
    if (n >= 2) {
        to_binary(n/2);
    }
    putchar('0' + r);
    return;
}
