/*
 * function_pointer.c 
 */
#include <stdio.h>
//char* (*pf)(int*)
//https://www.learn-c.org/en/Function_Pointers

void someFunction(int arg)
{
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");

}
int main(void)
{
    void (*pf)(int);
    pf = someFunction;
    printf("We're about to call someFunction() using a pointer!\n");
    (pf)(5);
    printf("Wow that was cool. Back to main now!\n\n");
    return 0;
}
