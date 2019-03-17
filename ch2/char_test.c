#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /*
     * char   -0  ~ 127
     * unsigned char   -0  ~ 255
     * short int   -32767  ~ 32767
     *
     *
     * */
    char  a = 0;
    printf("%d\n",a);
    a = -1;
    printf("%d\n",a);
    a = 127;
    printf("%d\n",a);
    a = 128;
    unsigned char c = 0;
    printf("c is : %d\n",c);
    c = -1;
    printf("c is : %d\n",c);
    c = 255;
    printf("c is : %d\n",c);
    c = 256;
    printf("c is : %d\n",c);

    short int  b = 32768;
    printf("%d",b);
}

