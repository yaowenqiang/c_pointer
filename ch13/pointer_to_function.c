#include <stdio.h>
int f(int);
int main(void)
{
    int (*pf)(int) = &f;
    int ans;

    ans = f(25);
    printf("f(25) = %d\n", ans);
    ans = pf(25);
    printf("pf(25) = %d\n", ans);
    ans = (*pf)(25);
    printf("(*pf)(25) = %d\n", ans);

    return 0;
}

int f(int a)
{
    return a;
}
