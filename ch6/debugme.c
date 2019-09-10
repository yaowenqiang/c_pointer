/*
 * debugme.c -- poorly writen program to debug
 *
 */

#include <stdio.h>
#define BIGNUM 5000

void index_to_the_moon(int ary[]);
int main(void)
{
    int intary[100];
    index_to_the_moon(intary);
    return 0;
}

void index_to_the_moon(int ary[])
{
    int i;
    for (i = 0; i < BIGNUM; i++) {
        ary[i] = i;
    }
}
