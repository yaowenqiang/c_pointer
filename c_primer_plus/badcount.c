/*
 * badcount.c - 不正确的参数个数 
 */

#include <stdio.h>
int main(void)
{
    int f = 4;
    int g = 5;
    float h = 5.6f;
    printf("%d\n", f,g);
    printf("%d %d\n", f);
    printf("%d %f\n", h ,g);
    return 0;
}
