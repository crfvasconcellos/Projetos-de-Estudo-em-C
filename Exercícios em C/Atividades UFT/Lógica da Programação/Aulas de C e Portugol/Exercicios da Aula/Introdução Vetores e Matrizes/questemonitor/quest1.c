/*Faça um programa que leia 10 números do usuário e armazene-os em um
vetor. Imprima a quantidade de números pares e números ímpares. Utilizar
laço for.*/

#include <stdio.h>

void contadordetipos(int*par,int*impar,int variavel)    
{
    if (variavel % 2 == 0)
    {
        (*par)++;
    }
    else if (variavel % 2 == 1)
    {
        (*impar)++;
    }
    
    
}

int main ()

{

int contpar=0,contimpar=0,num[10];

for (int i = 0; i < 10; i++)
{
    printf("\nDigite o número %dº : ",i+1);
    scanf("%d",&num[i]);

    contadordetipos(&contpar,&contimpar,num[i]);
}

printf("\n Foram identificados %d pares e %d números impares",contpar,contimpar);

}