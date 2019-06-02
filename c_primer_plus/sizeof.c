/*
 * sizeof.c - 使用sizeof 运算符
 */

#include <stdio.h>
int main(void)
{
    typedef double  real;
    real deal = 1.0;
    int n = 0;
    size_t intsize;
    size_t doublesize;
    intsize = sizeof(int);
    doublesize = sizeof(deal);
    printf("n = %d.n has %zd bytes;al all ints have %zd bytes\n", n , sizeof n, intsize);
    printf("n = %d.n has %zd bytes;al all ints have %zd bytes\n", n , sizeof(n), intsize);
    printf("deal = %f.deal has %zd bytes;al all float have %zd bytes\n", deal , sizeof(deal), doublesize);
    return 0;
}
