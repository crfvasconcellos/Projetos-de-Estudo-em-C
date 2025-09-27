#include <stdio.h>
#include "racional.h"

int main() {
    Racional* r1 = createRacional(1, 2); // 1/2
    Racional* r2 = createRacional(3, 4); // 3/4

    printf("R1 = "); imprimirRacional(r1);
    printf("R2 = "); imprimirRacional(r2);

    Racional* soma = somaRacional(r1, r2);
    printf("Soma = "); imprimirRacional(soma);

    Racional* prod = multiplicaRacional(r1, r2);
    printf("Multiplicacao = "); imprimirRacional(prod);

    printf("Sao iguais? %s\n", testaIgualRacio(r1, r2) ? "Sim" : "Nao");

    destruirRacional(r1);
    destruirRacional(r2);
    destruirRacional(soma);
    destruirRacional(prod);

    return 0;
}
