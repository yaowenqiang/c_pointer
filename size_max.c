/*
 * size_max.c - print the SIZE_MAX value
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

size_t a = 1;
size_t b;
size_t c;
size_t d;

int e, f, g, h, i,j,k,l,m,n;

int main(void)
{
    b = SIZE_MAX + 1;
    c = 0 - 1;
    printf("a = %zu\n",a);
    printf("SIZE_MAX = %zu\n",SIZE_MAX);
    printf("SIZE_MAX + 1 = %zu\n",b);
    printf("0 - 1 = %zu\n",c);
    printf("0 - 1 = %zu\n",0 - 1);
    printf("0 - 1 = %d\n",0 - 1);
    j = (i -= 1);
    printf("j = (i += 1) = %d\n",j);



    e = f = g += h++;
    printf("e=  %d\n", e);
    printf("f=  %d\n", f);
    printf("g=  %d\n", g);
    printf("h=  %d\n", h);
    puts("----------------");
    e = f = g += ++h;
    printf("e=  %d\n", e);
    printf("f=  %d\n", f);
    printf("g=  %d\n", g);
    printf("h=  %d\n", h);

}
