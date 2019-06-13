/*
 * power.c - 计算数值的整数次冥
 */

#include <stdio.h>

double power(double n, int p);
int main(void)
{
    double x, xpow;
    int exp;
    printf("Enter a number and the positive integer power\n");
    printf(" To which\nthe number will be raised, Enter q\n");
    printf(" to quit. \n");
    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g.\n", x ,exp, xpow);
        printf("Enter next pair of numbers or q to quite. \n");
    }

    printf("Hope you enjoyed this power trip - bye!\n");
    return 0;
}

double power(double n, int p)
{
    double pow = 1;
    int i;
    for (i = 0; i <= p; i++) {
        pow *= n; 
    }
    return pow;

}
