#include <stdio.h>

typedef struct 
{
    char nome [30];
    int qtd;
}item;


int main()
{
    item itens[10][3];
    FILE * F= fopen("itens.bin","wb");
    if (F== NULL)
    {
        printf("\n ERRO EM ABRIR O ARQUIVO DE TEXTO!");
        return 1;
    }
    
    int qtd[3];
    

    for (int i = 0; i < 3; i++)
    {
        printf("\nEstante %d",i+1);
        printf("\nQual a quantidade de itens estocados na estante %d ? (max de 10) ",i+1);
        scanf("%d",&qtd[i]);
        fwrite(&qtd[i],sizeof(qtd[i]),1,F);
        for (int j = 0; j < qtd[i]; j++)
        {
            printf("\nItem %d: ",j+1);
            scanf(" %s",itens[j][i].nome);
            printf("\nQtd: ");
            scanf("%d",&itens[j][i].qtd);

            fwrite(itens[j][i].nome,sizeof(itens[j][i].nome),1,F);
            fwrite(&itens[j][i].qtd,sizeof(itens[j][i].qtd),1,F);
        }
        
    }
    
    
}