#include <stdio.h>
int main(void)
{
    int i;
    int *pi;
    int **ppi;
    ppi = &pi;
    *ppi = &i;
    i = 'a';
    *pi='a';
    **ppi = 'a';
    printf("i = : %d\n", i);
    printf("pi = %d\n", pi);
    printf("ppi = %d\n", ppi);

    printf("*pi = %d\n", *pi);
    printf("**ppi = %d\n", **ppi);
    *pi = 'b';
    printf("i = : %d\n", i);

    return 0;
}
