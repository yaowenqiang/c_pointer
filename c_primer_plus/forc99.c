/*
 * forc99.c - 新的c99块规则
 */

#include <stdio.h>
int main(void)
{
    int n = 0;
    printf("    Initially, n = %d at %p\n", n, &n);
    for (int n=1; n < 3; n++)
        printf("        loop1, n = %d at %p\n", n, &n);

    printf("After loop1,   n = %d at %p\n", n, &n);

    for (int n = 1; n < 3; n++) {
        printf("loop2 index    n = %d at %p\n", n, &n);
        int n = 6;
        printf("        loop2, n = %d at %p\n", n, &n);
        n++;
    }

    printf("After loop2,   n = %d at %p\n", n, &n);


    return 0;
}
