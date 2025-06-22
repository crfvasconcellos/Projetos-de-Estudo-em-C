#include <stdio.h>

void escrevetxt()
{
    
}

int main()
{
    

    typedef struct 
    {
        char nome [50];
        int qtd;

    }itens;
    
    itens escaninhos[10][3];

    for (int i = 0; i < 3; i++)
    {
        printf("\n--- %d escaninho ---\n",i+1);
        for (int j = 0; j < 10; j++)
        {
            printf("\nNome do Item: ");
            scanf("%s",escaninhos[j][i].nome);
            printf("Qtd do Item %d:");
            scanf ("%d",&escaninhos[j][i].qtd);

        }
        
    }




}

