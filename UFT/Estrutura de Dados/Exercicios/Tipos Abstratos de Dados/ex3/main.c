#include <stdio.h>
#include "numInteiros.h"


int main() {
    // Criação dos conjuntos
    Inteiros *conjunto1 = Inteiros_create();
    Inteiros *conjunto2 = Inteiros_create();

    // Inserindo elementos
    Inteiros_insert(conjunto1, 1);
    Inteiros_insert(conjunto1, 2);


    Inteiros_insert(conjunto1, 3);
    Inteiros_insert(conjunto2, 2);
    Inteiros_insert(conjunto2, 3);
    Inteiros_insert(conjunto2, 4);

    printf("Conjunto 1: ");
    printInteiros(conjunto1);

    printf("Conjunto 2: ");
    printInteiros(conjunto2);

    // Testando remoção
    Inteiros_remove(conjunto1, 1);
    printf("Conjunto 1 após remover 1: ");
    printInteiros(conjunto1);

    // Interseção
    Inteiros *intersec = Inteiros_intersec(conjunto1, conjunto2);
    printf("Interseção: ");
    printInteiros(intersec);

    // Diferença
    Inteiros *dif = Inteiros_dif(conjunto1, conjunto2);
    printf("Diferença (conjunto1 - conjunto2): ");
    printInteiros(dif);

    // União
    Inteiros *uni = Inteiros_uni(conjunto1, conjunto2);
    printf("União: ");
    printInteiros(uni);

    // Maior valor
    printf("Maior valor do conjunto1: %d\n", Inteiros_maior(conjunto1));

    // Aqui você pode adicionar free para liberar memória
    // free(conjunto1); free(conjunto2); etc.

    return 0;
}
