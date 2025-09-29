#include <stdlib.h>
#include "linked_list.h"
#include <stdio.h>


typedef struct _snode
{
    int val;
    struct _snode * next;
   
}SNode;


typedef struct linked_list
{
    SNode * begin;
    SNode * end;
}LinkedList;


LinkedList * LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1,sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
}



SNode * SNode_create(int val){
    SNode *N = (SNode*) calloc(1,sizeof(SNode));
    N->val = val;
    N->next=NULL;

    return N;

}


void LinkedList_add_First(LinkedList * L , int val){
    SNode* no = SNode_create(val);
    no->next = L->begin;
    
    if (L->begin == NULL && L->end == NULL)
    {
        L->end= no; 
    }
    L->begin = no;
    
}

void LinkedList_add_Last(LinkedList * L , int val){
    
    if (L->begin == NULL && L->end == NULL)
    {
        SNode* no = SNode_create(val);
        L->begin= no;
        L->end= no;
        
    }
    else{
        SNode* no = L->end;
        no->next = SNode_create(val);
        L->end= no->next;
        
    }

}


void LinkedList_remove(LinkedList * L,int val)
{
   if (L->begin != NULL && L->end != NULL )
   {
            // CASO 1 = O elemento está na cabeça
            if (val == L->begin->val)
            {
                SNode * no = L->begin;
                L->begin = L->begin->next;
                free(no);
            }   

            // CASO 2 = O elemento não está na cabeça
            else
            {
                SNode * no = L->begin->next;
                SNode * antno= L->begin;
                while (1)
                {
                        
                    if (no->val == val)
                    {
                        //Caso Seja o Último
                        if (no->next == NULL)
                        {
                            L->end = antno;
                        }
                        
                        antno->next = no->next;
                        free (no);
                        break;    
                    }
                    else
                    {
                        if (no->next == NULL)
                        {
                            printf("\n Valor a ser removido nao encontrado ");
                            break;
                        }
                        
                        no = no->next;
                        antno = antno->next;
                        
                    } 
                }
            
            }
   }
    
}


void LinkedList_Print(const LinkedList * L){
    
    SNode* no = L->begin;

    printf("L -> ");

    while (no!= NULL)
    {
        printf("%d -> ", no->val);
        no = no->next;
    }
    printf("NULL");
}


