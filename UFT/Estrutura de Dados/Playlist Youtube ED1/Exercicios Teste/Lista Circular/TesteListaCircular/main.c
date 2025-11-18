#include <stdio.h>
#include "CircList.h"

int main(){

    CircList* Lista = CircList_create();

    CircList_addFirst(Lista,10);
    CircList_addFirst(Lista,6);
    CircList_addFirst(Lista,7);
    CircList_addFirst(Lista,2);

    CircList_printf(Lista);


    CircList_addLast(Lista,11);
    CircList_addLast(Lista,12);



    CircList_printf(Lista);

    CircList_remove(Lista,12);


    CircList_printf(Lista);
    




}