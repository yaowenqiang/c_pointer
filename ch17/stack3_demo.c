/*
 * 动态数组实现堆栈演示
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack3.c"

int main(void)
{
    create_stack(10);
    push(10);
    push(10);
    push(10);
    push(10);
    pop();
    destroy_stack();
    return 0;
}
