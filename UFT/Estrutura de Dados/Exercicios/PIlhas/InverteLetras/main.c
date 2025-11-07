#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{

    Stack * S = Stack_create();

    for (int  i = 1; i < 4; i++)
    {
        int val;
        printf("\nValor %d: ",i);
        scanf("%d",&val);
        Stack_push(S,val);
    }
    

    Stack_printf(S);

    // tira o topo

    int topo;

    Stack_pop(S,&topo);

    printf("\nRetiramos o Topo %d e ficou: \n",topo);
    Stack_printf(S);


    return 0;
}