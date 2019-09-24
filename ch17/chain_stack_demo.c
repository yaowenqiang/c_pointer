/*
 * 链表实现堆栈
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"
#include "chain_stack.c"
int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    destroy_stack();
        
    return 0;
}
