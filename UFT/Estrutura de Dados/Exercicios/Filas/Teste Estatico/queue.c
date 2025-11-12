#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 5


typedef struct _queue{

    int qtd;
    int head;
    int tail;
    int data[MAX];

}Queue;



Queue* Queue_create(){

    Queue * q = (Queue*) calloc(1,sizeof(Queue));
    q->head= 0;
    q->qtd= 0;
    q->tail= 0;

 
    return q;

}


bool Queue_enqueue(Queue* q , int val){

    if (Queue_is_full(q))
    {
        return false;
    }
    

    

    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % MAX;
    q->qtd++;

    return true;
}


bool Queue_dequeue(Queue* q, int* recebeval){

    if (q == NULL || Queue_is_empty(q))
    {
        return false;
    }
    
    * recebeval = q->data[q->head];
    q->head = (q->head + 1) % MAX;
    q->qtd--;
    return true;


}


bool Queue_is_full(Queue* q){

    if (q->qtd == MAX)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Queue_is_empty(Queue* q){

    if (q->qtd == 0)
    {
        return true;
    }
    else{
        return false;
    }


}

unsigned int Queue_get_qty(Queue* q){

    return q->qtd;

}