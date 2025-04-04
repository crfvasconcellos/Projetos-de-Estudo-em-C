/*8) Um banco concederá um crédito especial aos seus clientes de acordo com o saldo médio no último 
ano. Faça um algoritmo que receba o saldo médio de um cliente e calcule o valor do crédito, 
de acordo com a tabela a seguir. Mostre o saldo médio e o valor do crédito. Saldo Médio Crédito Acima 
de R$ 500,00 30% do saldo médio De R$ 500,00 a R$ 250,00 10% do saldo médio Abaixo de R$ 250,00 5% do saldo médio Difícil*/

#include <stdio.h>

int main() {
    int saldo,credito;
    printf("Qual foi seu saldo médio no banco? \n");
    scanf("%d",&saldo);

    if (saldo>=500) {

        credito= saldo*0.3;
    }
    else if (saldo<500 && saldo>=250)
    {
        credito= saldo*0.1;
    }
    else if (saldo<250)
    {
        credito=saldo*0.05;
    }

    printf("Com seu saldo médio de R$%d, você obteria um crédito de R$%.2f",saldo,(float)credito);
    
    
}