#include <stdio.h>
#include "stack1.c"
int main(void)
{
    push(1);
    int a = top();
    printf("a = %d\n", a);
    return 0;
}
