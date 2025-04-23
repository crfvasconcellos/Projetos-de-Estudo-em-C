// Ler 20 valores reais, somar cada valor lido com uma constante fornecida pelo usuário e, logo após, mostrar os resultados.

#include <stdio.h>

int main ()
{
    float num[20];
    float somageral=0;

    for (int i = 0; i < 20; i++)
    {
       num[i]=0;
       printf("\n Qual o valor do %d º número? ",i+1);
       scanf("%f",&num[i]);

       somageral= somageral + num[i];
    }

    printf("\n A soma de todos os números é %.2f ",somageral);

}


