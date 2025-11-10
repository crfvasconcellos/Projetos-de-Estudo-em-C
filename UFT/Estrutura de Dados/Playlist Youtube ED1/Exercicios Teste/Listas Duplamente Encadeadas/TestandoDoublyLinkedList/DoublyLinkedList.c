#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct _doubly_node 
{
    int val;
    struct _doubly_node* prev;
    struct _doubly_node* after;

}DoublyNode,Node;

typedef struct _doubly_linked_list 
{
    Node * begin;
    Node* end;
    size_t size;

}DoublyLinkedList,List;


Node * Node_create(int val){

    Node * node = (Node*) calloc(1,sizeof(Node));
    node->val= val;
    node->after= NULL;
    node->prev=NULL;
    return node; 

}


DoublyLinkedList * DoublyLinkedList_create()
{
    DoublyLinkedList* list = (DoublyLinkedList*) calloc(1,sizeof(DoublyLinkedList));
    list->begin= NULL;
    list->end= NULL;
    list->size= 0;

    return list;

}

void DoublyLinkedList_destroy(DoublyLinkedList** L){

    Node * aux = (*L)->begin;
    

    while (aux != NULL)
    {
        Node * next = aux->after;
        free(aux);
        aux = next;
        
    }

    free(*L);
    (*L) = NULL;

}



bool DoublyLinkedList_isempety(DoublyLinkedList * L){

    if (L->size == 0)
    {
        return true;
    }
    else{
        return false;
    }


}


void DoublyLinkedList_addfirst(DoublyLinkedList * L, int val){

    Node  * newNode = Node_create(val);

    if (DoublyLinkedList_isempety(L))
    {
      
        L->end = newNode;
        L->begin = newNode;

    }
    else
    {
        newNode->after = L->begin;
        L->begin->prev = newNode;
        L->begin = newNode;
        
    }
    

    L->size++;

}

void DoublyLinkedList_addLast(DoublyLinkedList * L, int val){

    Node * newNode = Node_create(val);


    if (DoublyLinkedList_isempety(L))
    {
        L->begin= newNode;
        L->end= newNode;

    }
    else{

        newNode->after = L->end;
        L->end->prev = newNode;
        L->end = newNode;

    }
    

    L->size++;


}

void DoublyLinkedList_print(DoublyLinkedList * L){

    Node * aux = L->begin;

    printf("\n");

    while (aux != NULL)
    {
        printf("%d->",aux->val);
        aux= aux->after;

    }
    printf(" NULL\n");
    

}

void DoublyLinkedList_invertedprint(DoublyLinkedList * L){

    Node * aux = L->end;

    printf("\n");

    while (aux != NULL)
    {
        printf("%d->",aux->val);
        aux= aux->prev;

    }
    printf(" NULL\n");
    


}


int DoublyLinkedList_remove(DoublyLinkedList * L, int val){

    if (!DoublyLinkedList_isempety(L))
    {
        Node * p;
        p = L->begin;
        
        if (L->begin->val == val)
        {

            if (L->size == 1)
            {
                L->begin= NULL;
                L->end = NULL;
                free(p);    
            }
            else{
                L->begin = p->after;
                L->begin->prev= NULL;
                free(p);
            }
            
            

        }
        else{

            while (p != NULL && p->val != val)
            {
                p = p->after;
            }
            
            if (p == NULL)
            {
                printf("\n\nElemento nao encontrado e não deletado!");
                return 1;
            }
            
            if (p == L->end)
            {
                L->end = p->prev;
                p->prev->after = NULL;
                
            }
            else
            {
                p->prev->after = p->after;
                p->after->prev = p->prev;
            }
            
            free(p);
            
            
        }
        
        printf("\nElemento Removido");
        L->size --;

    }

    return 0;

    }
    
