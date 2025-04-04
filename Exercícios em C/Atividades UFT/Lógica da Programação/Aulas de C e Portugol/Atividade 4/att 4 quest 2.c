/*2) Elabore um algoritmo que mostre o tipo de eleitor (obrigatório, opcional ou não eleitor) de acordo com sua idade.
*/

#include <stdio.h>

int main() {
    int idade;

    printf("Qual a sua idade? ");
    scanf("%d",&idade);

    if (idade<16 && idade>0){
        printf("Você não pode ser um eleitor!");

    }
    else if (idade>=16 && idade<18)
    {
        printf("Você é um eleitor Opcional!");
    }
    else if (idade>=18)
    {
        printf("Você é um eleitor Obrigatório!");
    }
    else if (idade<0)
    {
        printf("Essa não é um opção Válida.");
        return 1;
    }
    
    return 0;

}