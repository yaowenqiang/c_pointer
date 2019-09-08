/*
 * pointer test
 */

#include <stdio.h>
int main(void)
{
    
    int a = 112, b = -1;
    float c = 3.14;
    int *d = &a;
    float *e = &c;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %f\n", c);
    printf("d = %p\n", d);
    printf("d = %p\n", &d);
    printf("d = %d\n", *d);
    printf("e = %d\n", e);

    return 0;
}
