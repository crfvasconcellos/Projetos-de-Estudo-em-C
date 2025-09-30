#include "IntBacana.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _tno{

    int val;
    struct _tno * next;

}TNo;

struct _linkedlist
{
    TNo * begin;
    TNo * end;
};

TNo * TNo_create(int num){
    TNo * no = (TNo*) calloc(1,sizeof(TNo));
    no->next=NULL;
    no->val = num;

    return no;
}


LinkedList * LinkedList_create(int num){

    LinkedList * L = (LinkedList*) calloc(1,sizeof(LinkedList));
    L->begin = TNo_create(num);
    L->end = L->begin;

    LinkedList_InteirosBacanasbroke(L);

    return L;

}


void LinkedList_Insert_begin(LinkedList * L, int num){

    TNo * no = TNo_create(num);

    no->next = L->begin;
    L->begin = no;

    

}


void LinkedList_Insert_end(LinkedList * L, int num) {
    TNo *no = TNo_create(num);
    if (L->begin == NULL) {  // lista vazia
        L->begin = no;
        L->end = no;
    } else {
        L->end->next = no;
        L->end = no;
    }
}


void LinkedList_destroy(LinkedList **Lref){
    if (*Lref == NULL) return;

    TNo *proc = (*Lref)->begin;
    TNo *aux;

    while (proc != NULL) {
        aux = proc;
        proc = proc->next;
        free(aux);
    }

    free(*Lref);
    *Lref = NULL;
}



int InteirosBacanaquadrado(int num){

    int resultado = 0;
    while (num > 0) {
        int digito = num % 10;
        resultado += digito * digito;
        num /= 10;
    }
    return resultado;

}


void LinkedList_InteirosBacanasbroke(LinkedList *L){

    int retorno= L->begin->val;


    while (retorno != 1 && retorno > 9)
    {
        retorno = InteirosBacanaquadrado(retorno);

        LinkedList_Insert_end(L,retorno);

    }
    


} 


void verificaBacana(LinkedList * L){


    if (L->end->val == 1 )
    {
        printf("\nbacana");
    }
    else{
        printf("\nnon-bacana");
    }

}

void LinkedList_print(LinkedList * L){

    printf("\n L -> ");
    
    TNo * proc = L->begin;

    while (proc != NULL)
    {
        printf("%d",proc->val);
        printf(" -> ");
        proc = proc->next;
    }
    

    verificaBacana(L);


}