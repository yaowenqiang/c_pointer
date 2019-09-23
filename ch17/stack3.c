/*
 * 一个用动态分配数组实现的堆栈
 * 堆栈的长度在创建椎的函数被调用时给出，该函数必须在任何其他操作堆栈的函数被调用之前调用。
 */

#include "stack1.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


static STACK_TYPE  *stack;
static size_t stack_size;
static int top_element = -1;

void create_stack(size_t size)
{
    assert(stack_size == 0);
    stack_size = size;
    stack = malloc(stack_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
}

void destroy_stack(void)
{
    assert(stack_size > 0);
    stack_size= 0;
    free(stack);
}

void push(STACK_TYPE value)
{
    assert(!is_full());

    top_element += 1;
    stack[top_element] = value;
}

STACK_TYPE pop(void)
{
    assert(!is_empty());
    top_element -= 1;
    return stack[top_element];
}

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack[top_element];
}
int is_empty(void)
{
    assert(stack_size > 1);
    return top_element == -1;
}

int is_full(void)
{
    assert(stack_size > 0);
    return top_element == stack_size - 1;
}

