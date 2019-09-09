/*
 * segmentation violation error demo
 */

#include <stdio.h>
int main(void)
{
    int  a;
    //*a = 1;
    int b = 0;
    int *d = &b;
    *d = 10 - *d;
    //d = 10 - *d;
    //
    *&a = 20;
    // a = 20

    printf("%d\n", a);
    printf("%d\n",d );
    printf("%d\n",b );

    return 0;
}
