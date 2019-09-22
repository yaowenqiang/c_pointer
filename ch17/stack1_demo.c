#include <stdio.h>
#include "stack1.c"
int main(void)
{
    push(1);
    STACK_TYPE a = top();
    printf("a = %d\n", a);
    STACK_TYPE b =  pop();
    printf("b = %d\n", b);
    return 0;
}
