#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct _snode 
{
    int val;
    struct _snode * before;
    struct _snode * after;

}SNode;


typedef struct doubly_linked_list 
{
    int places;
    SNode * begin;
    SNode * end;


}DoublyLinkedList;


DoublyLinkedList* DoublyLinkedList_create(){

    DoublyLinkedList * L = (DoublyLinkedList*) calloc(1,sizeof(DoublyLinkedList));
    L->begin = NULL;
    L->end = NULL;
    L->places = 0;

    return L;

}

SNode* SNode_create(int val){
    SNode * no = (SNode*) calloc(1,sizeof(SNode));

    no->val = val;
    no->after = NULL;
    no->before = NULL;

    return no;
}


void DoublyLinkedList_addFirst(DoublyLinkedList* L,int val){

    SNode * no = SNode_create(val);

    if (L->begin == NULL && L->end == NULL)
    {
        L->begin = no;
        L->end = no;

    }
    else{

        SNode * aux; 
        aux = L->begin;
        L->begin = no;
        no->after = aux;
        aux->before = no;
    }

    L->places++;
    

}

void DoublyLinkedList_addLast(DoublyLinkedList* L,int val){

    SNode * no = SNode_create(val);

    if (L->begin == NULL && L->end == NULL)
    {
        L->begin = no;
        L->end = no;
    }
    else{

        L->end->after = no;
        no->before = L->end;
        L->end = no;

    }

    L->places++;

}

void DoublyLinkedList_addBigNumber(DoublyLinkedList* L, int BigNumber){

    int breaker = BigNumber;
    int rest;


    while (breaker>=10)
    {
        
        rest = breaker % 10;
        breaker = breaker / 10;

        DoublyLinkedList_addFirst(L,rest);
        
    }
    
}


DoublyLinkedList* DoublyLinkedList_BigSum(int val1, int val2){

    DoublyLinkedList * L1 = DoublyLinkedList_create();
    DoublyLinkedList * L2 = DoublyLinkedList_create();

    DoublyLinkedList * L3 = DoublyLinkedList_create();

    DoublyLinkedList_addBigNumber(L1,val1);
    DoublyLinkedList_addBigNumber(L2,val2);

    int cont = 0;
    int sum;
    int add;
    SNode * aux1 = L1->end;
    SNode * aux2 = L2->end;

    while (aux1 != NULL || aux2 != NULL)
    {


        if (cont == 0 )
        {
            sum = L1->end->val + L2->end->val;
            aux1 = L1->end->before;
            aux2= L2->end->before;

            if (sum >= 10)
            {
                sum = sum % 10;
                add = sum / 10;

                L1->end->before->val = L1->end->before->val + add;
            }

        }
        else
        {
            sum = aux1->val + aux2->val;
            aux1 = aux1->before;
            aux2 = aux2->before;

            if (sum >= 10)
            {
                sum = sum % 10;
                add = sum / 10;

                aux1->before->val = aux1->before->val + add;
            }

        }
    
        

        DoublyLinkedList_addLast(L3,sum);
    }
    
    return L3;

}


int DoublyLinkedList_printf(DoublyLinkedList* L){

    if (L == NULL) 
    {
        printf("\nErro: A soma retornou um ponteiro nulo.\n");
        return 1; 
    }

    SNode * aux = L->begin;

    printf("\nNumero Big: ");

    for (int i = 0; i < L->places; i++)
    {
        printf("%d",aux->val);
        aux = aux->after;
    }
    



}

