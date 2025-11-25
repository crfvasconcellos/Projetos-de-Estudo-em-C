#include "StaticQueue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 5


typedef struct _staticqueue{

    int begin;
    int tail;
    int qtd;
    int * data;


} StaticQueue;


StaticQueue * StaticQueue_create(){

    StaticQueue * q= (StaticQueue*) calloc(1,sizeof(StaticQueue));

    q->begin = 0;
    q->tail = 0;
    q->data = (int*) calloc(MAX,sizeof(int));
    q->qtd = 0;

    return q;
}

void StaticQueue_destroy(StaticQueue** q){

    if (q != NULL && *q != NULL)
    {
        
        StaticQueue * que = *q;
        
        free(que->data);
        free(que);
        *q = NULL;
        
    }
    


}
int StaticQueue_enqueue(StaticQueue* q, int val){

    if (q->qtd != MAX)
    {

        q->data[q->tail] = val;
        q->tail = (q->tail+1) % MAX;
        q->qtd++;
        return 0;
        
    }
    else{
        return 1;
    }

}
int StaticQueue_dequeue(StaticQueue* q){

    if (q->qtd != 0)
    {
        int val = q->data[q->begin];
        q->begin = (q->begin + 1) % MAX;

        q->qtd--;
        return val;
    }
    else{

        return -1;
    }




}


void StaticQueue_print(StaticQueue* q){

    if(q == NULL){
        printf("Fila inexistente!\n");
        return;
    }

    printf("Fila: ");

    for(int i = 0; i < MAX; i++)
    {
        if(i == q->begin && q->qtd > 0)
        {
            printf("%d (BEGIN)", q->data[i]);
        }
        else if(i == ((q->tail - 1 + MAX) % MAX) && q->qtd > 0)
        {
            printf("%d (END)", q->data[i]);
        }
        else
        {
            printf("%d", q->data[i]);
        }

        printf(" -> ");
    }

    printf("\n");
}