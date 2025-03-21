#include <stdio.h>

int main(){
    printf("**************************************\n");
    printf("BEM VINDO AO JOGO DE ADIVINHAÇÃO!!\n");
    printf("**************************************\n");

    int secreto= 42;
    int chute;

    printf("Chute um número: \n");
    scanf("%d",&chute);
    printf("Você chutou %d \n", chute);

    if (chute==secreto){
       
        printf("PARABÉNS, VOCÊ ACERTOU!!! (O NÚMERO SECRETO ERA 42)\n");

    }
    else {
        printf("Você errou!!");
    }

}
