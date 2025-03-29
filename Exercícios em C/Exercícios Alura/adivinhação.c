#include <stdio.h>
#include <stdlib.h>
#include <time.h>>

#define TENTATIVAS 5

int main(){
    printf("**************************************\n");
    printf("BEM VINDO AO JOGO DE ADIVINHAÇÃO!!\n");
    printf("**************************************\n");

    int x = time(0);
    srand(x);
    int aleatorio= rand();
    
    
    int secreto= aleatorio % 100;
    int chute;
    int ganhou = 0;
    int i = 0; //tentativas
    double pontuacao= 1000;
    

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
       
        printf("PARABÉNS, VOCÊ ACERTOU!!! (O NÚMERO SECRETO ERA %d)\n",secreto);
        break;

    }
    else {
        double diferenca=0;
        if (chute>secreto)
        {
            printf("Seu chute foi maior que o número secreto!\n");
            diferenca= chute-secreto;
        }
        if (chute<secreto)
        {
            printf("Seu chute foi menor que o número secreto!\n");
            diferenca= secreto-chute;
        }
        
        printf("Você errou!! Tente novamente!\n");
        printf("TENTATIVA %d !\n", i);
        pontuacao= pontuacao - (diferenca)/2;
    }

}
printf("JOGO ENCERRADO!\n");
printf("VOCÊ TERMINOU COM %d TENTATIVAS! \n",i);
printf("VOCÊ OBTEVE A PONTUAÇÃO %.1f DE 1000 !", pontuacao);
}