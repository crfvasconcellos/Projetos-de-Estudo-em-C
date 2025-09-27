#include "Numcplex.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Complexo* c1 = criarComplexo(2, 3);
    Complexo* c2 = criarComplexo(1, 4);

    printf("C1 = ");
    imprimirComplexo(c1);
    printf("C2 = ");
    imprimirComplexo(c2);

    Complexo* soma = somaComplexos(c1, c2);
    printf("Soma = ");
    imprimirComplexo(soma);

    Complexo* sub = subtraiComplexos(c1, c2);
    printf("Subtracao = ");
    imprimirComplexo(sub);

    destroi(c1);
    destroi(c2);
    destroi(soma);
    destroi(sub);

    return 0;
}