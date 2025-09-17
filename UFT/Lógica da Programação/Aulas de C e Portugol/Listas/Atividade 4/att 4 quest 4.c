/*
 4) Faça um algoritmo que receba dois números e execute uma das operações listadas a seguir de acordo com a escolha do usuário. Considere que pode haver erro de entrada no código da operação. 1. Soma dos números, 2. Subtração do maior pelo menor, 3. Divião do primeiro pelo segundo.

*/

#include <stdio.h>


 int main()
 {
     
     int n1, n2,escolha; 
     printf("Digite dois números: \n ");
     scanf("%d %d",&n1,&n2);
     
     printf("Escolha o que deseja fazer com tais números: \n [1] Soma \n [2] sutração \n [3] Divião \n ");
     scanf("%d",&escolha);
     
     if (escolha==1){
         int soma= n1 + n2;
         printf("A soma é %d", soma);
    
     }
     else if (escolha==2) {
        if (n1> n2){
            int sub= n1-n2;
            printf("A subtração é %d", sub);
        }
        else if (n1<n2) {
            int sub= n2-n1;
            printf("A subtração é %d", sub);
        }    
        }
