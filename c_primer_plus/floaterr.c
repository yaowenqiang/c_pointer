/*
 * floaterr.c - 说明舍入误差
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float f = FLT_MAX;
    printf("%f\n", f);
    float a,b;
    b = 2.0e20 + 1.0;
    printf("%f \n", b);
    a = b - 2.0e20;
    printf("%f \n", a);
    printf("%f \n", b);
    b = 2.0e4 + 1.0;
    a = b - 2.0e4;
    printf("%f \n", a);
    b = 2.0e5 + 1.0;
    a = b - 2.0e5;
    printf("%f \n", a);

    b = 2.0e7 + 1.0;
    a = b - 2.0e7;
    printf("%f \n", a);

    b = 2.0e10 + 1.0;
    a = b - 2.0e10;
    printf("%f \n", a);
    return 0;

}
