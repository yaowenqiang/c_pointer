/*
 * c trap demo
 */

#include <stdio.h>
typedef void (*funcptr)();
//(*(funcptr)0)();

int main(void)
{
    int a ,b = 0;
    printf("a++ + ++b=%d\n", a++ + ++b);

    void (*fp)();
    //(*fp)();
    //*((*fp)());

    //(*fp)();

    //(void (*)())0;


    (*(void (*)())0)();
    return 0;



}
