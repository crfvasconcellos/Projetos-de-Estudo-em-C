#ifndef DOUBLYLINKEDLIST_H // DoublyLinkedList
#define DOUBLYLINKEDLIST_H

#include <stdbool.h>

typedef struct _doubly_node DoublyNode,Node;
typedef struct _doubly_linked_list DoublyLinkedList, List;

Node * Node_create();

DoublyLinkedList * DoublyLinkedList_create();

bool DoublyLinkedList_isempety(DoublyLinkedList * L);

void DoublyLinkedList_destroy(DoublyLinkedList** L);
void DoublyLinkedList_addfirst(DoublyLinkedList * L, int val);
void DoublyLinkedList_print(DoublyLinkedList * L);
void DoublyLinkedList_invertedprint(DoublyLinkedList * L);

#endif