#include <stdio.h>
#include <stdlib.h>
#include "IntBacana.h"


int main(){

int numero;
scanf("%d",&numero);


LinkedList * L = LinkedList_create(numero);



LinkedList_print(L);

}