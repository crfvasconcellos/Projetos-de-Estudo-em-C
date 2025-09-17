#include <stdio.h>

int main(){

    int soma=0,num;
    char continu='+';

    printf("Calculadora de soma!! \n");

    while (continu=='+')
    {
        printf("Digite um número: ");
        scanf("%d",&num);

        soma=soma+num;

        printf("\nDigite um símbolo (+ ou =):");
        scanf(" %c",&continu);

        if (continu != '+' && continu != '=')
        {
            while (continu != '+' && continu != '=')
            {
                printf("\nDigite um símbolo (+ ou =):");
                scanf(" %c",&continu);
                printf("Valor Desconsiderado! Digite um símbolo válido!!");
            }
            

           
        }
        

    }

    printf("A soma dos valores é %d ",soma);
    
}