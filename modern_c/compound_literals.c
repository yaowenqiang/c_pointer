/*
 * compound_liters.c
 */

#include <stdio.h>
#include <stdlib.h>


int f (void)
{
    struct s {int i;} *p = 0, *q;
    int j = 0;
again:
    q = p; p = &((struct s){j++});
    if (j < 2) {
        goto again;
    }
    return p == q && q ->i == 1;
}

int main(void)
{
    int *p = (int[]){2,4};
    int foo = f();
    printf("%d\n", foo);
    return 0;
}
