/*
 * proto.c - 使用函数原型
 */

#include <stdio.h>
int max(int ,int);
int main(void)
{

    printf("The maximum of %d and %d is %d.\n", 3,5, max(3, 5));
    printf("The maximum of %d and %d is %d.\n", 3,5, max(3.0, 5.0));
    return 0;
}

int max(int n, int m)
{
    int max;
    if (n > m) {
        max = n;
    } else {
        max = m;
    }
    return max;
}

