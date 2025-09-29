#include "linked_list.h"
#include <stdio.h>

int main() {

    LinkedList * L = LinkedList_create();

    LinkedList_add_Last(L , 10 );
    LinkedList_add_Last(L , 5 );
    LinkedList_add_Last(L , 3);
    LinkedList_add_Last(L , 2 );
    LinkedList_add_Last(L , 1 );
    LinkedList_add_First(L,11);
    LinkedList_Print(L);
    printf("\n\n");
    LinkedList_remove(L,0);
    LinkedList_Print(L);
    

}