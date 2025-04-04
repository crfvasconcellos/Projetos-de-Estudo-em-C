/*Escreva um programa que peça um inteiro ao usuário, e com esse inteiro, ele imprima, linha-a-linha, 
a tabuada daquele número até o 10. Por exemplo, se ele escolher o número 2, o programa imprimirá: 2x1=2, 2x2=4, 2x3=6, ..., 2x10=20.*/

#include <stdio.h>

int main() {


    int num,numr;
    printf("Diga um número e lhe mostrarei a tabuada! \n Número: ");
    scanf("%d",&num);


    for (int i = 1; i <= 10; i++)
    {
        numr= num*i;
        printf("%d x %d = %d \n",num,i,numr);
    }
    
}