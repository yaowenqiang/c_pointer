/*
 * swap1.c - 交换函数的第一个版本
 */

#include <stdio.h>
void interchange(int x, int y);
int main(void)
{
    int x = 6, y = 10;
    printf("Originally x = %d and y = %d\n", x, y);
    interchange(x, y);
    printf("Now x = %d and y = %d\n", x, y);
    return 0;
}

void interchange(int u, int v)
{
    int tmp;
    tmp = u;
    u = v;
    v = tmp;
}
