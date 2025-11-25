#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct _snode{

    struct _snode* next;
    int val;

} SNode;


typedef struct _stack{


    SNode * top;
    int qtd;


} Stack;

SNode * SNode_create(int val){

    SNode * no = (SNode*) calloc(1,sizeof(SNode));

    no->next = NULL;
    no->val = val;

    return no;


}

Stack * Stack_create(){

    Stack * s = (Stack*) calloc(1,sizeof(Stack));

    
    s->top = NULL;
    s->qtd = 0;

    return s;

}

void Stack_push(Stack* s, int val){

    SNode * no = SNode_create(val);
    
    no->next = s->top;
    s->top = no;

    s->qtd++;
}

int Stack_pop(Stack * s){

    if (!Stack_is_empty(s))
    {
        int val = s->top->val;
        SNode * aux = s->top;
        s->top = s->top->next;
    
        free(aux);
        s->qtd--;
    
        return val;
        
    }
    else{
        printf("\nPilha vazia");
        exit(1);
    }


}

int Stack_peek(Stack* s){

     if (!Stack_is_empty(s))
    {
        return s->top->val;
    }
    else{
        printf("\nPilha vazia");
        exit(1);
    }


}

void Stack_destroy(Stack ** s1){

    Stack * s = *s1;

    if (!Stack_is_empty(s))
    {
        SNode * aux = s->top;
    
        while(s->top != NULL)
        {
            s->top = s->top->next;
            free(aux);
            aux = s->top;
    
        }
        
    }
    
    free(s);

    *s1 = NULL;


}


bool Stack_is_empty(Stack * s){
    return s->qtd == 0;

}

void Stack_print(Stack * s){

    if (s == NULL){
        printf("Pilha (NULL)\n");
        return;
    }

    if (Stack_is_empty(s)){
        printf("Pilha vazia\n");
        return;
    }

    SNode * aux = s->top;
    printf("Pilha (top -> bottom): ");
    while(aux != NULL){
        printf("%d ", aux->val);
        aux = aux->next;
    }
    printf("\n");
}