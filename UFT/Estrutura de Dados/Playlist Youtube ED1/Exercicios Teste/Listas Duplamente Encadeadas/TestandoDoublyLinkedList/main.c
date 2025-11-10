#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main(){

    DoublyLinkedList * L = DoublyLinkedList_create();

    int valores[5];

    for (size_t i = 0; i < 5; i++)
    {
        printf("\n Valor %d:  ",i);
        scanf("%d",&valores[i]);
        DoublyLinkedList_addfirst(L,valores[i]);

    }

    DoublyLinkedList_print(L);

    printf("Removendo o 2");
    DoublyLinkedList_remove(L,2);



    DoublyLinkedList_print(L);

    printf("Removendo o 5 ");
    DoublyLinkedList_remove(L,5);

     DoublyLinkedList_print(L);

}