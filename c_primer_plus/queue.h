/*
 * queue.h -- Queue 的接口
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef int Item;
//或者 typedef struct item {int gumption; int charisma; } Item;

#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node * next;
} Node;


typedef struct queue {
    Node * front;
    Node * rear;
    int items;
} Queue;

void InitializeQueue(Queue * pq);

bool QueueIsFull(Queue * pq);

bool QueueIsEmpty(Queue * pq);

int QueueItemCount(Queue * pq);

bool EnQueue(Item item, Queue * pq);

bool DeQueue(Item *pitem, Queue * pq);

void EmptyTheQueue(Queue * pq);

#endif  
