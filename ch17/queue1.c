/*
 * 一个使用静态数组实现的队列，数组的长度只能通过修改#define定义并重新编译模块来调整
 */

#include "queue1.h"
#include <stdio.h>
#include <assert.h>

#define QUEUE_SIZE 100
#define ARRAY_SIZE (QUEUE_SIZE + 1)

static QUEUE_TYPE queue[ARRAY_SIZE];

static size_t front = 1;
static  size_t rear = 0;

void insert(QUEUE_TYPE value)
{
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

void rm(void)
{
    assert(!is_empty());
    front = (front+1) %  ARRAY_SIZE;
}

QUEUE_TYPE first(void)
{
    assert(!is_empty());
    return queue[front];
}

int is_empty(void)
{
    return (rear + 1) % QUEUE_SIZE == front;
}

int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}

