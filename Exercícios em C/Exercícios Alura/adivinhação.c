#include <stdio.h>

#define TENTATIVAS 5

int main(){
    printf("**************************************\n");
    printf("BEM VINDO AO JOGO DE ADIVINHAÇÃO!!\n");
    printf("**************************************\n");

    int secreto= 42;
    int chute;

for (int i = 1; i <= TENTATIVAS; i= i +1)
{

    printf("Chute um número: \n");
    scanf("%d",&chute);
    printf("Você chutou %d \n", chute);

    if (chute<0) {
        printf("VOCÊ NÃO PODE CHUTAR NÚMEROS NEGATIVOS!!\n");
        i= i -1;
        continue;
    }

    if (chute==secreto){
       
        printf("PARABÉNS, VOCÊ ACERTOU!!! (O NÚMERO SECRETO ERA 42)\n");
        break;

    }
    else {
        if (chute>secreto)
        {
            printf("Seu chute foi maior que o número secreto!\n");
        }
        if (chute<secreto)
        {
            printf("Seu chute foi menor que o número secreto!\n");
        }
        
        printf("Você errou!! Tente novamente!\n");
        printf("TENTATIVA %d DE %d\n", i,TENTATIVAS);
    }

}
printf("JOGO ENCERRADO!");
}