#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main(){

    DoublyLinkedList * L = DoublyLinkedList_create();

    int valores[3];

    for (size_t i = 0; i < 3; i++)
    {
        printf("\n Valor %d:  ",i);
        scanf("%d",&valores[i]);
        DoublyLinkedList_addfirst(L,valores[i]);

    }

    DoublyLinkedList_print(L);
    DoublyLinkedList_invertedprint(L);
    



}