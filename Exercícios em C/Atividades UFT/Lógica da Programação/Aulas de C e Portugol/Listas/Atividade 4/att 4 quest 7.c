/* 7) Uma importadora envia seus produtos para várias regiões do País. Os códigos de destino adotados são 1 para Sul, 2 para Norte, 3 e 4 para Leste e 5 a 10 para Oeste. Cada região tem uma alíquota de imposto. Para a região Sul a alíquota é de 10%, para Norte, é de 5%, para Leste, é de 8% e para Oeste, é de 9%. Elabore um algoritmo que leia o código de destino e imprima o nome do destino e a sua alíquota. */

#include <stdio.h>

int main() {
    int cod;

    printf("Qual é o código do destino? \n ");
    scanf("%d",&cod);

    if (cod == 1)
    {
        printf("Para a Região Sul, o imposto será de 10%%");
    }
    else if (cod==2)
    {
        printf("Para a Região Norte, o imposto será de 5%%");
    }
    
    else if (cod==3 || cod==4)
    {
        printf("Para a Região Leste, o imposto será de 8%%");
    }

    else if (cod>=5 && cod<=10)
    {
        printf("Para a Região Oeste, o imposto será de 9%%");
    }
    
    else{
        printf("Erro, Código Inválido");
        return 1;
    }
    
    return 0;

}