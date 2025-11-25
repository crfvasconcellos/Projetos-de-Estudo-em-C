#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>


typedef struct _queue Queue;
typedef struct _qnode QNode;

QNode * QNode_create(int val);
Queue * Queue_create();

void Queue_enqueue(Queue * q, int val);
void Queue_destroy(Queue** que);
void Queue_print(Queue *q);

int Queue_dequeue(Queue* q );

bool Queue_is_empty(Queue * q);

#endif