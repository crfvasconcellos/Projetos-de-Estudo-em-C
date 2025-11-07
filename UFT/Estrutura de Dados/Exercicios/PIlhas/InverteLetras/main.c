#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Stack *S = Stack_create();

    char frase[100];

    printf("\nDigite seu nome: ");
    fgets(frase, 100, stdin);

    // 🔹 remove o '\n' do final, se existir
    frase[strcspn(frase, "\n")] = '\0';

    printf("\nOlá, %s", frase);

    // 🔹 empilha cada caractere da string
    for (int i = 0; i < strlen(frase); i++) {
        Stack_push(S, frase[i]);
    }

    // 🔹 cria string invertida
    char fraseInvertida[100];
    int len = strlen(frase);

    for (int i = 0; i < len; i++) {
        Stack_pop(S, &fraseInvertida[i]);
    }

    // 🔹 adiciona terminador de string
    fraseInvertida[len] = '\0';

    int iguais = 1;

    for (int i = 0; i < len; i++)
    {
        if (frase[i] != fraseInvertida[i])
        {
            iguais = 0;
        }
        
    }
    
    

    if (iguais == 1)
    {
        printf("\nAs palavaras são palíndromos!\n");
    }
    

    printf("\n\n%s ficou ao inverter: %s\n", frase, fraseInvertida);

    return 0;
}
