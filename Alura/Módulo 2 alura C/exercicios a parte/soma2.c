#include <stdio.h>

int soma(int* num,int qtd)
{
    int soma= 0;
    for (int i = 0; i < qtd ; i++)
    {
        soma= soma + (*num);
        num++;
    }

    return soma;
}

int main ()
{
    int num[3];

    printf("\n Digite 3 números: ");
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    

    int total= soma(num,3);
    printf("A soma dos 3 é %d ", total);

}