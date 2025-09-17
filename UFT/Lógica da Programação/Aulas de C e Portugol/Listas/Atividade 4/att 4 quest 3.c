/*
 3) Elabore um algoritmo que dadas as medidas dos lados de um triângulo, diga se é um triângulo equilátero, isósceles ou escaleno. Se as medidas não corresponderem a um triângulo, mostre uma mensagem de erro.
*/

#include <stdio.h>

int main()
{

int lado[3];

for (int c=0;c<=2;c= c +1){
    printf("Informe o lado%d: \n",c+1);
    scanf ("%d",&lado[c]);
  
}    
if (lado[0] + lado[1] > lado[2] && lado[1] + lado [2] > lado[0] && lado[2] + lado[0] > lado[1]){
    printf("Com esses números, é possivel fazer um triangulo!!\n");
    if (lado[0]==lado[1] && lado[2]==lado[0]){
        printf("Ele é um triângulo equilátero\n");
    }
    else if (lado[0]==lado[1] && lado[1]!= lado[2] || lado[2]==lado[1] && lado[1] != lado[0] || lado[0]==lado[2] &&  lado[2] != lado[1] ){
        printf("O triângulo é isóceles\n");
    }
        
    else{
        printf("O triângulo é escaleno\n");
    }    
    }
else {
    printf("Com esses lados não é possivel fazer um triângulo!");
}
}
