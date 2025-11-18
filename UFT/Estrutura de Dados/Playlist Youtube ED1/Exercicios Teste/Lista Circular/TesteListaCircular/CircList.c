#include <stdio.h>
#include <stdlib.h>
#include "CircList.h"


typedef struct _cnode{

    int val;
    struct _cnode* next;
    struct _cnode* before;

}CNode;



typedef  struct _circlist{

    CNode* begin;
    CNode* end;
    int size;

} CircList;


CNode * CNode_create(int val){

    CNode* cn = (CNode*) calloc(1,sizeof(CNode));
    cn->before = cn;
    cn->next = cn;
    cn->val= val;

    return cn;
    
}


CircList * CircList_create(){

    CircList * cL = (CircList*) calloc(1,sizeof(CircList));
    cL->begin = NULL;
    cL->end= NULL;
    cL->size = 0;


    return cL;

}

bool CircList_isempty(CircList* L){

    if (L->size == 0)
    {
        return true;
    }
    else{
        return false;
    }

}


void CircList_destroy(CircList** L){

    CircList * List = (*L);
    

    if (!CircList_isempty(*L))
    {
        CNode * aux = List->begin;
        

        for (int i = 0; i < List->size; i++)
        {
            CNode * next = aux->next;
            free(aux);
            aux = next;
        }
        

    }

    free(List);
    (*L) = NULL;


}

void CircList_addFirst(CircList * L, int val){
    
    CNode * No = CNode_create(val);

    if (CircList_isempty(L))
    {
        L->begin = No;
        L->end = No;    

    }
    else{

        No->next = L->begin;
        L->begin->before = No;
        No->before = L->end;
        L->begin = No;
        L->end->next = No;
    }


    L->size++;


}

void CircList_addLast(CircList * L, int val){
    CNode * no = CNode_create(val);

    if (CircList_isempty(L))
    {
       L->begin = no;
       L->end = no;

    }
    else{

        L->end->next = no;
        L->begin->before = no;
        no->next = L->begin;
        no->before = L->end;
        L->end = no;
    }
    

    L->size++;


}

void CircList_printf(CircList* L){

    printf("\nL -> ");
    CNode * aux = L->begin;

    for (int i = 0; i < L->size; i++)
    {
        printf("%d -> ",aux->val);
        aux = aux->next;

    }

    printf("L \n\n");


}

void CircList_invertedprintf(CircList* L){

    printf("\nL -> ");
    CNode * aux = L->end;

    for (int i = 0; i < L->size; i++)
    {
        printf("%d -> ",aux->val);
        aux = aux->before;

    }

    printf("L \n\n");




}

int CircList_remove(CircList * L, int val){
    if (!CircList_isempty(L))
    {
        CNode * aux = L->begin;

        if (L->begin->val == val)
        {
            if (L->size == 1)
            {
                free(aux);
                L->begin= NULL;
                L->end = NULL;
            }
            else{

                L->begin = aux->next;
                L->end->next = aux->next;
                L->begin->before = L->end;

                free(aux);

            }
            

        }
        else{

            while (aux->val != val && aux != L->end)
            {
                aux = aux->next;
            }

            if (aux == L->end && aux->val == val)
            {
                L->end = aux->before;
                L->end->next = L->begin;
                L->begin->before = L->end;
                free(aux);

            }
            else if (aux->val == val)
            {
                aux->before->next = aux->next;
                aux->next->before = aux->before;
                free(aux);
            }
            else{

                printf("\nValor a ser removido nao encontrado!");
                return 1;


            }
            
            




        }
        
        
        
        
        
        L->size --;
        return 0;
        
    }
    else{

        printf("\nA lista esta vazia!");
        return 1;

    }
    
    

}