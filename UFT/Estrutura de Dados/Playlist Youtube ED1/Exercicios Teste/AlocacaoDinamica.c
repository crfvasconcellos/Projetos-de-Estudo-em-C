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


    //Alocação de Um Vetor Dinâmico Usando Malloc (Memória Heap)

    int* vmal = (int*) malloc(5*sizeof(int));


    printf("\n&Vmal = %p  Vmal = %p \n", &vmal,vmal);

    for (int i = 0; i < 5; i++)
    {
        printf("&Vmal[%d] = %p Vmal[%d] = %d \n",i,&vmal[i],i,vmal[i]);

    }

    printf("\n\n");
    



    
}