/*
 * 一个使用链表实现的堆栈，这个堆栈没有长度限制
 */

#include "stack1.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define FALSE 0

typedef struct STACK_NODE {
    STACK_TYPE value;
    struct STACK_NODE *next;
} StackNode;

static  StackNode *stack;

void create_stack(size_t size)
{

}

void destroy_stack(void)
{
    while(!is_empty())
    {
        pop();
    }
}

void push(STACK_TYPE value)
{
    StackNode * new_node;
    new_node = malloc(sizeof(StackNode));
    assert(new_node != NULL);
    new_node->value = value;
    new_node->next  = stack;
    stack = new_node;
}

STACK_TYPE pop(void)
{
    StackNode * first_node;
    assert(!is_empty());

    first_node = stack;
    stack = first_node->next;
    free(first_node);
}

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack->value;
}

int is_empty(void)
{
    return stack == NULL;
}

int is_full(void)
{
    return FALSE;
}
