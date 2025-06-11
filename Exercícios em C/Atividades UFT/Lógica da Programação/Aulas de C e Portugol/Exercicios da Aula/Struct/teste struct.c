#include <stdio.h>

struct pessoa
    {
        char nome[30];
        int idade;
        int peso;
    };


int main()
{
    struct pessoa p1;

    printf("\nSeu nome: ");
    scanf("%s",p1.nome);

    printf("\nSua idade: ");
    scanf("%d",&p1.idade);

    printf("\nSeu Peso: ");
    scanf("%d",&p1.peso);

    printf("Olá, %s, você tem %d anos e pesa %d kgs \n",p1.nome,p1.idade,p1.peso);
    
}