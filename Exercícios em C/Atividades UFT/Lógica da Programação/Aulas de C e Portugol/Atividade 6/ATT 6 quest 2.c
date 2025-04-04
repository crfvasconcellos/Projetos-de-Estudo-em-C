#include <stdio.h>

/*2. Leia um número indeterminado de idades. Para cada idade, informe se a pessoa é maior ou menor de idade. Ao final, mostre quantas idades foram processadas.
*/

int main() {

int count=0, idade;
char resp = 's';

while (resp!='n')
{
    printf("Digite a sua idade: ");
    scanf("%d",&idade);
    
    count++;

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

printf("Foram processadas %d idades!! \n",count);

printf("Programa encerrado!");
return 0;



}