#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TENTATIVAS 5

int main(){
    printf("**************************************\n");
    printf("                 P  /_\\  P                             \n");
    printf("                /_\\_|_|_/_\\                           \n");
    printf("            n_n | ||. .|| | n_n         Bem vindo ao    \n");
    printf("            |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!\n");
    printf("           |" "  |  |_|  |"  " |                        \n");
    printf("           |_____| ' _ ' |_____|                        \n");
    printf("                 \\__|_|__/                             \n");            

    printf("**************************************\n");

    int nivel,nt,pts=0; //conta os níveis de desafio e mostra os pontos só se ganhar
    int x = time(0);
    srand(x);
    int aleatorio= rand();

    printf("Deseja jogar no nível: \n [1] Fácil \n [2] Médio \n [3] Díficil \n R: ");
    scanf("%d",&nivel);
    
    
    int secreto= aleatorio % 100;
    int chute;
    int ganhou = 0;
    int i = 0; //tentativas
    double pontuacao= 1000;
    

while (ganhou==0){

    if (nivel==1)
    {
        nt=20;
        if (i>=21)
        {
            printf("Você Ultrapassou seu número de Tentativas! \n JOGO ENCERRADO!");
            break;
        }
        
    }

    else if (nivel==2)
    {
        nt=10;
        if (i==11)
        {
            printf("Você Ultrapassou seu número de Tentativas! \n JOGO ENCERRADO!");
            break;
        }
        
    }

    else if (nivel==3)
    {
        nt=5;
        if (i==6)
        {
            printf("Você Ultrapassou seu número de Tentativas! \n");
            break;
        }
        
    }

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
        pts=1;

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
        printf("TENTATIVA %d DE %d !\n", i,nt);
        pontuacao= pontuacao - (diferenca)/2;
    }

}
printf("JOGO ENCERRADO!\n");
printf("VOCÊ TERMINOU COM %d TENTATIVAS! \n",i);
if (pts==0)
{
    pontuacao=0;
}
printf("VOCÊ OBTEVE A PONTUAÇÃO %.1f DE 1000 !", pontuacao);
}