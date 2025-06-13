#include <stdio.h>

void verlista()
{
    FILE * F;

    F= fopen("../banco de dados.txt", "r");
    if (F == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char palavra[100];
    while (fscanf(F,"%s",palavra)==1)
    {
        printf("\nPalavra: %s",palavra);
    }

    fclose(F);

    

}


void escreverarq()
{
    FILE*F;

    F= fopen("../banco de dados.txt","a");


    printf("\nQual o nome deseja adicionar? ");
    char resposta[100];
    scanf("%s",resposta); 
    fprintf(F,"%s\n",resposta);

    fclose(F);
}

int main()
{
    while (1)
    {
        
        printf("O que deseja fazer? \n [1] Ver nomes na Lista \n [2] Adicionar Nome \n [3] Sair \n R: ");
        int resp;
        scanf("%d",&resp);


        switch (resp)
        {
        case 1:
            verlista();
            break;
        
        case 2:
            escreverarq();
            break;
        case 3:
            return 0;
           
        default:
            break;
        }

        
        
    }
    
}