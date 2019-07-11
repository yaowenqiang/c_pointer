/*
 * pnt_add.c - 指针地址
 */

#include <stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short * ptl;
    short index;
    double bills[SIZE];
    double * ptf;
    ptl = dates;
    ptf = bills;
    printf("%23s %15s \n", "short", "double");
    for (index = 0; index < SIZE; index++) {
        printf("pointers + %d: %10p %10p\n", index, ptl + index, ptf + index );
    }

    return 0;
}
