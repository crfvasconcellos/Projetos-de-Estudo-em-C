#include "linked_list.h"
#include <stdio.h>

int main() {

    LinkedList * L = LinkedList_create();

    LinkedList_add_First(L , 10 );
    LinkedList_add_First(L , 5 );
    LinkedList_add_First(L , 3);
    LinkedList_add_First(L , 2 );
    LinkedList_add_First(L , 1 );
    LinkedList_Print(L);


}