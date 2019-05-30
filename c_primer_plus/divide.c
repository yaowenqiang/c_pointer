/*
 * divide.c - 我们所知的除法
 */

#include <stdio.h>

int main(void)
{
    printf("integer devision: 5/4 is %d \n", 5/4);
    printf("integer devision: -5/4 is %d \n", -5/4);
    printf("integer devision: -3/4 is %d \n", -3/4);
    printf("integer devision: 6/3 is %d \n", 6/3);
    printf("integer devision: 7/4 is %d \n", 7/4);
    printf("floating devision: 7./4. is %1.2f \n", 7./4.);
    printf("mixed devision: 7.4/4 is %1.2f \n", 7./4);
    printf("mixed devision: 0.0/4 is %1.2f \n", 0.0/4);
    printf("mixed devision: 0.0/0.0 is %1.2f \n", 0.0/0.0);
    return 0;
}
