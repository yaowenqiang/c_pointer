/*
 * 用一个静态数组实现的堆栈，数组的长度只能通过修改 #define 定义
 * 并对模块重新编译来实现
 */

#include "stack1.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 100

static STACK_TYPE stack[STACK_SIZE];

static int top_element = -1;

void push(STACK_TYPE value)
{
    assert(!is_full());
    top_element += 1;
    stack[top_element] = value;
}


STACK_TYPE pop(void)
{
    STACK_TYPE temp;
    assert(!is_empty());
    temp = stack[top_element];
    top_element -= 1;
    return temp;
}

STACK_TYPE top(void )
{
    assert(!is_empty());
    return stack[top_element];
}

int is_empty(void)
{
    return top_element == -1;
}

int is_full(void)
{
    return top_element == STACK_SIZE - 1;
}
