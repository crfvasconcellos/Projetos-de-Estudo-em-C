#include <stdio.h>
#include <stdlib.h>


int main(){
    // Alocação de um Vetor Estático (memória Stack)

    int v[5] = {0,10,20,30,40};

    printf("\n&V = %p  V = %p \n", &v,v);

    for (int i = 0; i < 5; i++)
    {
        printf("&V[%d] = %p V[%d] = %d \n",i,&v[i],i, v[i]);

    }

    printf("\n\n");




    
}