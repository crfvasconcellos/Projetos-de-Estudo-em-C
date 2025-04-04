#include <stdio.h>

/*2. Leia um número indeterminado de idades. Para cada idade, informe se a pessoa é maior ou menor de idade. Ao final, mostre quantas idades foram processadas.
*/

int main() {

int count=0, idade,med,soma=0;
char resp = 's';

while (resp!='n')
{
    printf("Digite a sua idade: ");
    scanf("%d",&idade);
    
    count++;
    soma= soma + idade;

    if (idade>=18)
    {
        printf("\nO Usuário é maior de idade!\n");
    }

    else{
        printf("\nO Usuário ainda é menor de idade!\n");
    }

    printf("Deseja adicionar mais uma idade? s ou n \n");
    scanf(" %c",&resp);
    
    idade=0;
}


med= soma/count;
printf("Foram processadas %d idades!! \n",count);
printf("A média das idades foi: %d \n",med);

printf("Programa encerrado!");
return 0;



}