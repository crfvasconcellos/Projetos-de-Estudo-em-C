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
}LinkedList;


LinkedList * LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1,sizeof(LinkedList));
    L->begin = NULL;

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
    if (L->begin == NULL)
    {
        
        L->begin= no;
        
    }

    else{
        
        no->next= L->begin;
        L->begin = no;
    }
    
    

}

void LinkedList_add_Last(LinkedList * L , int val){
    
    if (L->begin == NULL)
    {
        SNode* no = SNode_create(val);
        L->begin= no;
        
    }
    else{
        SNode* no = L->begin;

        while (1)
        {
            if (no->next== NULL)
            {
               no->next =  SNode_create(val);
               break;
            }
            no = no->next;

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