/*
 * pnt_add.c - 指针地址
 */

#include <stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short * pt1;
    short index;
    double bills[SIZE];
    double * ptf;
    pt1 = dates;
    pt2 = bills;
    printf("%23s %15s \n", "short", "double");
    for (int index = 0; index < SIZE; index++) {
        printf("pointers + %d: %10p %10p\n", index, pti + index );
    }

    return 0;
}
