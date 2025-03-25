#include <stdio.h>

#define TENTATIVAS 5

int main(){
    printf("**************************************\n");
    printf("BEM VINDO AO JOGO DE ADIVINHAÇÃO!!\n");
    printf("**************************************\n");

    int secreto= 42;
    int chute;
    int ganhou = 0;
    int i = 0; //tentativas

while (ganhou==0){
    i= i + 1;
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
        printf("TENTATIVA %d !\n", i);
    }

}
printf("JOGO ENCERRADO!\n");
printf("VOCÊ TERMINOU COM %d TENTATIVAS!",i);
}