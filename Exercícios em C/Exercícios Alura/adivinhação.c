#include <stdio.h>

int main(){
    printf("**************************************\n");
    printf("BEM VINDO AO JOGO DE ADIVINHAÇÃO!!\n");
    printf("**************************************\n");

    int secreto= 42;
    int chute;
for (int i = 1; i <= 3; i= i +1)
{

    printf("Chute um número: \n");
    scanf("%d",&chute);
    printf("Você chutou %d \n", chute);

    if (chute==secreto){
       
        printf("PARABÉNS, VOCÊ ACERTOU!!! (O NÚMERO SECRETO ERA 42)\n");

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
    }

}
}