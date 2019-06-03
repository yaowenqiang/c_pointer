/*
 * post_pre.c
 */

#include <stdio.h>
int main(void)
{
    int a = 1, b = 1, c = 1, d = 1, r = 0, s = 0;
    int aplus, plusb;
    int p;
    int q;

    p = 2*c++;
    q = 2*++c;
    printf("%d %d\n", p ,q);

    r = 2*++d;
    s = 2*d++;
    printf("%d\n", d);
    aplus = a++;
    plusb = ++b;
    printf("a aplus b  plusb\n");
    printf("%d %5d %5d %5d \n", a, aplus, b , plusb);
    printf("%d %d\n", r ,s);
}

