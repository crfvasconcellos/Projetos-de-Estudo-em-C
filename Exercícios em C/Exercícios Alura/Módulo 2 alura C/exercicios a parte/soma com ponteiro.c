#include <stdio.h>

//Escreva uma função soma que recebe um ponteiro de inteiro num e mais dois inteiros a e b. A função deve calcular a soma de a+b em num.

void soma (int* x, int y,int z)
{
    (*x)= y + z;

}

int main()
{
    int a,b,num;
    printf("Digite 2 números: \n");
    scanf("%d %d",&a,&b);

    soma(&num,a,b);
    printf("\n A soma de %d + %d é %d ",a,b,num);
}