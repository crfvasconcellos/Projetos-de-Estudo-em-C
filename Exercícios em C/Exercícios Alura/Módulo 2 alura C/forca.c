#include <stdio.h>
#include <string.h>

int main(){

    char palavra_secreta[20];
    sprintf(palavra_secreta,"MELANCIA");



    int acertou=0;
    int enforcou=0;

    char chutes[26];
    int tentativas=0;

    do
    {
        for (size_t i = 0; i < strlen(palavra_secreta); i++) //aparecer _ da palavra secreta
        {
            int achou=0;

            for (int j = 0; j < tentativas; j++)
            {
                
                if (chutes[j]==palavra_secreta[i])
                {
                    achou=1;
                    printf("\n SEU CHUTE FOI CORRETO !! \n ");
                    break;
                }
            }
            if (achou==1)
            {
                printf("%c",palavra_secreta[i]);
            }
            else
            {
                printf("_ ");
            }
            
            
           
        }
        printf("\n");
        
        char chute;
        printf("\nQual o seu chute? ");
        scanf(" %c",&chute);

        chutes[tentativas]=chute;
        tentativas++;   

       

        
    } while (!acertou && !enforcou);
    

}