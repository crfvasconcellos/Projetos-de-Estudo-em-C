#include <stdlib.h>
#include "linked_list.h"
#include <stdio.h>


typedef struct _snode
{
    int val;
    struct _simple_node * next;
   
}SNode;


typedef struct _linked_list
{
    SNode * begin;
}LinkedList;


LinkedList * LinkedList_create(){
    LinkedList *L = (LinkedList*) calloc(1,sizeof(LinkedList));
    L->begin = NULL;

    return L;
}



SNode_create(int val){
    SNode *N = (SNode*) calloc(1,sizeof(SNode));
    N->val = val;
    N->next=NULL;

    return N;

}


LinkedList_add_First(LinkedList * L , int val){
    if (L->begin == NULL)
    {
        SNode* no = SNode_create(val);
        L->begin= no;
        
    }

    else{
        SNode* no = SNode_create(val);
        no->next= L->begin;
        L->begin = no;
    }
    
    

}