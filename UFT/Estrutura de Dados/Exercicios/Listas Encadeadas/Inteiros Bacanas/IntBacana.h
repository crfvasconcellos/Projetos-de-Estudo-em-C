#ifndef INTBACANA_H
#define INTBACANA_H

typedef struct _linkedlist LinkedList;

LinkedList * LinkedList_create(int num);

int InteirosBacanaquadrado(int num);

void LinkedList_print(LinkedList * L);
void LinkedList_InteirosBacanasbroke(LinkedList *L);

#endif