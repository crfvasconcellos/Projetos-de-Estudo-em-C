#include <stdio.h>


  /*Faça um algoritmo que receba o preço, o nome, a quantidade em estoque e o tipo (mercearia,
limpeza e perecíveis) de produtos em 34 filiais de uma rede de lojas. Para encerrar a lista de
produtos de uma filial, será inserido o valor -1 na variável de entrada referente ao preço.
Mostre, para cada filial, o valor total (em R$) em estoque. Mostre também a percentagem de
produtos de mercearia, de limpeza e de perecíveis, contando toda as filiais. Por último mostre o
preço do produto mais caro entre todos os produtos lidos e quantas filiais têm menos que R$
60.000,00 em estoque.*/
#define num_max 100

int main () {
    
     
    
     int count=0;
     int qtd[num_max],tipo[num_max]; //tipo 1 - marcearia, 2 - limpeza, -3 perecíveis*/
     char nome[num_max] [20];
     float preco[num_max],estoqval[34];

    for(int i=0;i<=34;i++){
        count=0;
        estoqval[i]=0;
        

        printf("\n-------- %dº FILIAL -------- \n",i+1);

        while (preco[i] != -1 || count == 100)
        {
            printf("Nome do %dº produto da %dº Filial : ",count+1,i+1);
            scanf(" %s",nome[count]);
            
            printf("Qual é o preço do produto? (-1 para encerrar a lista) R$ ");
            scanf("%f",&preco[count]);

            if (preco[count]==-1)
            {
                break;
            }
            

            printf("\nQual é o tipo de produto? \n [1] mercearia \n [2] limpeza \n [3] Perecíveis \n R: ");
            scanf("%d",&tipo[count]);

            printf("\n Qual é a quantidade do estoque? R: ");
            scanf("%d",&qtd[count]);
            
            estoqval[i]= estoqval[i] + preco[count] * qtd[count];

            count++;
        }


        
        printf ("O valor total do estoque da %dº Filial é %.2f",i+1,estoqval[i]);



    }



}