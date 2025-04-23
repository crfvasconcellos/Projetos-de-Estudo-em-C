//Leia 10 números inteiros e, após as leituras, mostre todos os valores na tela.

#include <stdio.h>

int main()
{
 int num[10];

 for (int i = 0; i < 10; i++)
 {
    num[i]=0;
    printf("\n Qual o valor do %d º número? ",i+1);
    scanf("%d",&num[i]);
 }
 
 for (int j = 0; j < 10 ; j++)
 {
   printf("\nValor %dº : %d ",j+1,num[j]);
 }
 

}