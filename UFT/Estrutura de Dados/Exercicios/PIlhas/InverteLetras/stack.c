#include "stack.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct _node {

    int val;
    struct _node * next;

}SNode;


typedef struct _stack {

    int size;
    SNode * top; // o ultimo

}Stack;

SNode * SNode_create(int val){

    SNode * node = (SNode*) calloc(1,sizeof(SNode));
    node->val = val;
    node->next = NULL;

    return node;
}


Stack * Stack_create(){

    Stack * stack = (Stack*) calloc(1, sizeof(Stack));
    stack->size= 0;
    stack->top= NULL;

    return stack;
}


void Stack_push(Stack * S ,int val){

    SNode * node = SNode_create(val);

    if (S->size == 0)
    {
        S->top = node;
    
    }
    else{

        node->next = S->top;
        S->top = node;

    }

    S->size++;

}

int Stack_pop(Stack * S, int * recebeval){

    if (S->size == 0)
    {
        printf("\n Não há elementos na Pilha");
        return 1;
    }
    
    *recebeval = S->top->val;

    SNode * aux = S->top;
    S->top = aux->next;
    free(aux);
    S->size--;
    return 0;
}


void Stack_destroy(Stack ** S){

    if ((*S)->size != 0)
    {
        while((*S)->top != NULL)
        {
            SNode * aux = (*S)->top->next;
            free((*S)->top);
            (*S)->top = aux;
        }
        
    }

    free(*S);
    (*S) = NULL;



}

