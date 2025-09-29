#include "numInteiros.h"
#include <stdlib.h>
#include <stdio.h>

struct _numInteiros
{
    int qtd;
    int elementos[100];
};

// Cria um conjunto vazio
Inteiros * Inteiros_create() {
    Inteiros * I = (Inteiros*) calloc(1, sizeof(Inteiros));
    I->qtd = 0;
    return I;
}

// Insere um elemento, se não existir
int Inteiros_insert(Inteiros * in, int val) {
    if (in->qtd >= 100) {
        printf("\nVetor cheio\n");
        return 1;
    }

    for (int i = 0; i < in->qtd; i++) {
        if (in->elementos[i] == val) {
            printf("\nO número já está incluso\n");
            return 1;
        }
    }

    in->elementos[in->qtd] = val;
    in->qtd++;
    return 0;
}

// Remove um elemento
int Inteiros_remove(Inteiros * in, int val) {
    int encontrado = 0;
    for (int i = 0; i < in->qtd; i++) {
        if (in->elementos[i] == val) {
            // Desloca os elementos à frente
            for (int j = i; j < in->qtd - 1; j++) {
                in->elementos[j] = in->elementos[j + 1];
            }
            in->qtd--;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nValor não encontrado para remoção\n");
        return 1;
    }

    return 0;
}

// Retorna a intersecção de dois conjuntos
Inteiros * Inteiros_intersec(Inteiros * in1, Inteiros * in2) {
    Inteiros * result = Inteiros_create();

    for (int i = 0; i < in1->qtd; i++) {
        for (int k = 0; k < in2->qtd; k++) {
            if (in1->elementos[i] == in2->elementos[k]) {
                Inteiros_insert(result, in1->elementos[i]);
                break;
            }
        }
    }

    return result;
}

// Retorna a diferença de dois conjuntos (in1 - in2)
Inteiros * Inteiros_dif(Inteiros * in1, Inteiros * in2) {
    Inteiros * result = Inteiros_create();

    for (int i = 0; i < in1->qtd; i++) {
        int encontrado = 0;
        for (int k = 0; k < in2->qtd; k++) {
            if (in1->elementos[i] == in2->elementos[k]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            Inteiros_insert(result, in1->elementos[i]);
        }
    }

    return result;
}

// Retorna a união de dois conjuntos
Inteiros * Inteiros_uni(Inteiros * in1, Inteiros * in2) {
    Inteiros * result = Inteiros_create();

    for (int i = 0; i < in1->qtd; i++) {
        Inteiros_insert(result, in1->elementos[i]);
    }

    for (int i = 0; i < in2->qtd; i++) {
        Inteiros_insert(result, in2->elementos[i]);
    }

    return result;
}

// Retorna o maior elemento
int Inteiros_maior(Inteiros * in) {
    if (in->qtd == 0) {
        printf("\nConjunto vazio\n");
        return 0;
    }

    int maior = in->elementos[0];
    for (int i = 1; i < in->qtd; i++) {
        if (in->elementos[i] > maior) {
            maior = in->elementos[i];
        }
    }

    return maior;
}

// Imprime os elementos do conjunto
void printInteiros(Inteiros * in) {
    if (!in) return;

    printf("{ ");
    for (int i = 0; i < in->qtd; i++) {
        printf("%d", in->elementos[i]);
        if (i < in->qtd - 1) printf(", ");
    }
    printf(" }\n");
}
