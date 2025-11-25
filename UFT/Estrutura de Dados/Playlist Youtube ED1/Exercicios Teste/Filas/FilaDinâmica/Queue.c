#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef struct _qnode{

    struct _qnode * next;
    int val;

} QNode;

typedef struct _queue{

    QNode *begin;
    QNode * end;
    int qtd;


} Queue;



QNode * QNode_create(int val){

    QNode * no = (QNode*) calloc(1,sizeof(QNode));
    no->next= NULL;
    no->val = val;

    return no;


}




Queue * Queue_create(){

    Queue * q = (Queue*) calloc(1,sizeof(Queue));

    q->begin = NULL;
    q->end = NULL;
    q->qtd = 0;

    return q;



}

void Queue_destroy(Queue** que){

    Queue * q = *que;

    if (!Queue_is_empty(q))
    {
        QNode* aux;

        while (q->begin != NULL)
        {
            aux = q->begin;
            q->begin= q->begin->next;
            free(aux);
        }
        q->end = NULL;
        
    }

    free(q);

    *que = NULL;

}

void Queue_enqueue(Queue * q, int val){

    QNode * new = QNode_create(val);

    if (!Queue_is_empty(q))
    {
        q->end->next = new;
        q->end = new;

    }
    else{

        q->begin = new;
        q->end= new;
    }

    q->qtd++;

}

int Queue_dequeue(Queue* q){

    if (!Queue_is_empty(q))
    {
        int val = q->begin->val;
        QNode* aux = q->begin;
        q->begin = q->begin->next;
    
        free(aux);
        
        q->qtd--;

        return val;
    }
    
    return -1;


}

bool Queue_is_empty(Queue * q){

    return q->qtd == 0;



}

void Queue_print(Queue *q) {
    if (Queue_is_empty(q)) {
        printf("[ Fila vazia ]\n");
        return;
    }

    QNode *aux = q->begin;
    printf("Início -> ");

    while (aux != NULL) {
        printf("%d ", aux->val);
        aux = aux->next;
    }

    printf("<- Fim\n");
    printf("Quantidade: %d\n", q->qtd);
}
