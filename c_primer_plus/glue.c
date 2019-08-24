/*
 * glue.c -- 使用##运管符 
 */

#include <stdio.h>
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);
int main(void)
{
    
    int XNAME(1) = 14; //变量x1 = 14;

    int XNAME(2) = 20; //变量x2 = 20;

    int x3 = 30;
    PRINT_XN(1); //变成printf("x1 = %d\n", x1)
    PRINT_XN(2); //变成printf("x2 = %d\n", x2)
    PRINT_XN(3); //变成printf("x3 = %d\n", x3)


    return 0;
}
