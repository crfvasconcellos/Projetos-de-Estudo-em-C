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