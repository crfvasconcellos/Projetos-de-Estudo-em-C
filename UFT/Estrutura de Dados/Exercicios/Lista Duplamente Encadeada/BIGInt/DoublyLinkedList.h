#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct _snode SNode;
typedef struct doubly_linked_list DoublyLinkedList;


SNode* SNode_create(int val);


DoublyLinkedList* DoublyLinkedList_create();
void DoublyLinkedList_addFirst(DoublyLinkedList* L,int val);
void DoublyLinkedList_addLast(DoublyLinkedList* L,int val);
void DoublyLinkedList_addBigNumber(DoublyLinkedList* L, int val);

int DoublyLinkedList_printf(DoublyLinkedList* L);

DoublyLinkedList* DoublyLinkedList_BigSum(int val1, int val2);




#endif