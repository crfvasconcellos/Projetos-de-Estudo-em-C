//Ler nome e idade de 13 pessoas, após as leituras mostrar todos os nomes, suas idades e quem é o mais velho.

#include <stdio.h>

int main()
{
    int idades [13],nmaior=0;
    char nomes [13] [100];

    for (int i = 0; i < 13 ; i++)
    {
        printf("\nQual o nome %dº ? ",i+1);
        scanf(" %s",nomes[i]);

        printf("Qual a idade dele? ");
        scanf("%d",&idades[i]);

        if (i==0 || idades[i] > nmaior)
        {
            nmaior= idades[i];
        }

    }

    printf(" \n A maior idade foi %d ",nmaior);

    printf("\n Lista dos indivíduos : ");

    for (int j = 0; j < 13 ; j++)
    {
        printf(" \n ********* \n");
        printf("Nome %dº: %s ",j+1,nomes[j]);

        printf("\nIdade: %d",idades[j]);

    }
    


    
}