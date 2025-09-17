#include <stdio.h>

typedef struct {
    char nome[30];
    int quantidade;
} Item;

void menu(Item itens[10][3],int qtd[3])
{
    while (1)
    {
        int opcao= -1;
        printf("\n--- MENU ---\n");
        printf("1. Mostrar conteúdo do escaninho\n");
        printf("2. Mostrar número de escaninhos vazios\n");
        printf("3. Mostrar todos os itens de uma estante\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        int escolha1=0,escolha2;
        switch (opcao)
        {
        case 1:
            printf("\n Qual estante? ");
            scanf("%d",&escolha1);
            escolha1--;
            printf("\n Qual número do item? ");
            scanf("%d",&escolha2);
            escolha2--;
            printf("\n --Item %d--\n\nNome: %s \nQtd: %d ",escolha2+1,itens[escolha2][escolha1].nome,itens[escolha2][escolha1].quantidade);
            break;
        case 2:
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (itens[j][i].quantidade==0)
                    {
                        escolha1++;
                    }
                    
                }
                
            }
            printf("\n Cerca de %d escaninhos estão vazios! ",escolha1);
            break;
        case 3:
            printf("\n Qual estante? ");
            scanf("%d",&escolha1);
            printf("\n == Estante %d ==",escolha1);
            escolha1--;
            for (int j = 0; j < qtd[escolha1]; j++)
                {
                    printf("\nItem(%d): %s qtd: %d",j+1,itens[j][escolha1].nome,itens[j][escolha1].quantidade);   
                }
            break;
        
        default:
            break;
        }
    }
    
}

int main()
{
    Item itens [10] [3]={0};
    int qtd[3]={0};


    FILE*F=fopen("itens.bin","rb");
    if (F== NULL)
    {
        printf("\nErro ao Abrir arquivo de leitura!");
        return 1;
    }
    

    for (int i = 0; i < 3; i++)
    {
        fread(&qtd[i],sizeof(int),1,F);

        for (int j = 0; j < qtd[i]; j++)
        {
            fread(itens[j][i].nome,sizeof(itens[j][i].nome),1,F);
            fread(&itens[j][i].quantidade,sizeof(int),1,F);       
        }
        
    }

    menu(itens,qtd);
    


}