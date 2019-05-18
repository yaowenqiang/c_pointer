/*
 * defines.c - 使用limits.h 和float.h中定义的常量
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Some number limits for this system.\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("smallest unsigned long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system. \n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %f digits\n", FLT_MAX);
    printf("float epsilon = %e\n", FLT_EPSILON); //1.00 和比1.00大的最小的float类型值之前的差值
    return 0;
}
