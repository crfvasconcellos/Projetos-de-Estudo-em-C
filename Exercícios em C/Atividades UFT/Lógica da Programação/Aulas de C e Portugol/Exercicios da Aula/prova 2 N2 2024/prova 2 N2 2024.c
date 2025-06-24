#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int presidencia;
    int estado;
    int idade;
    int sal;
} pessoas;


void contagem()
{
    int qtd[3];
    for (int i = 0; i < 3; i++)
    {
        printf("\n Quantas pessoas realizaram o teste no mês %d?",i+1);
        scanf("%d",&qtd[i]);
    }
    
    FILE * F= fopen("votos.bin","wb");
    if(F == NULL) {
    printf("Banco de dados de palavras não disponível\n\n");
    exit(1);
    }

    // Grave as quantidades
    fwrite(qtd, sizeof(int), 3, F);
    

    pessoas p[30][3];
    printf("Contagem de votos\n");
    if(F == NULL) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n1º Mês\n");

        for (int j = 0; j < qtd[i]; j++)
        {
            printf("\nQual é seu candidato à Presidência? \n (1)17 \n (2)26 \n (3)branco \n (4)indeciso \n R: ");
            scanf("%d",&p[j][i].presidencia);

            printf("\nQual é seu candidato ao Governo do Estado? \n (1)17 \n (2)26 \n (3)31 \n (4)branco \n (5)indeciso \n R: ");
            scanf("%d",&p[j][i].estado);

            printf("\nQual sua idade? ");
            scanf("%d",&p[j][i].idade);

            printf("\nQual sua faixa salarial? \n (1)menos que 3 salários mínimos \n (2) de 3 a 5 salários mínimos \n (3) mais que 5 salários mínimos \n R: ");
            scanf("%d",&p[j][i].sal);


            fwrite(&p[j][i],sizeof(pessoas),1,F);
            

        }
        
    }

    fclose(F);
}

int main()
{
    contagem();

    return 0;

}