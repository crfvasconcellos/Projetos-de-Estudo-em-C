#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct linked_list LinkedList;
typedef struct _snode SNode;


SNode * SNode_create();

LinkedList * LinkedList_create();

void LinkedList_add_First(LinkedList * L , int val);
void LinkedList_Print(const LinkedList * L);

#endif