#include <stdio.h>

void soma10(int num[10])
{
    int soma=0;
    for (size_t i = 0; i < 10; i++)
    {
        soma= soma + num[i];
    }
    
    printf("A soma deles é %d",soma);
}

int main()
{
    int numeros[10];

    for (size_t i = 0; i < 10; i++)
    {
        printf("\n Digite o número %d : ",i+1);
        scanf("%d",&numeros[i]);
    }

    soma10(numeros);
    
}