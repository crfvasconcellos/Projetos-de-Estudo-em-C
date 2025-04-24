/* Faça um programa que imprima os elementos de um vetor que representa uma
progressão aritmética e a soma finita dos elementos. Regras:
a. O primeiro termo deve ser 1;
b. A razão deve ser 5;
c. A soma deve ser feita utilizando a fórmula da soma finita de uma PA;
d. O tamanho do vetor deve ser 20.
*/

#include <stdio.h>

int main()
{
    int num[20],soma=0;

    num[0]=1;

    for (int i=0;i<20;i++)

    {   
        if (i==19)
        {
            num[i]= num[i-1] + 5;
        }
        
        else 
        {
            num[i+1]= num[i] + 5;
        }
        
        soma= soma + num[i];
    }

    for (int  i = 0; i < 20; i++)
    {
     printf(" %d ", num[i]);   
    }

    printf("A soma é %d ",soma);
    



}