/*
 * width.c - 字段宽度
 */

#include <stdio.h>
#define PAGES 931

int main(void)
{
    const double RENT = 3862.99;

    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);

    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3e*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);

    printf("%x %X %#x\n", 31,31,31);
    printf("**%d**% d**% d**\n", 42,42, -42);
    printf("**%5d**%5.3d**%5d**%5.3d**\n", 6,6,6,6);
}
