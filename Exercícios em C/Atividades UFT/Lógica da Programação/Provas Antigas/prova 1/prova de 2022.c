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
     int qtd[num_max],tipo[num_max],nmenor6=0; //tipo 1 - marcearia, 2 - limpeza, -3 perecíveis*/
     char nome[num_max] [20];
     float preco[num_max],estoqval[34],contmarce,contlimpe,contpere,totaltipo,nmaior;


    for(int i=0;i<34;i++){
        count=0;
        estoqval[i]=0;
        preco[count]=0;
        
        

        printf("\n-------- %dº FILIAL -------- \n",i+1);

        while (1)
        {
            
            int veri1=0;
            printf("Nome do %dº produto da %dº Filial : ",count+1,i+1);
            scanf(" %s",nome[count]);
            
            printf("Qual é o preço do produto? (-1 para encerrar a lista) R$ ");
            scanf("%f",&preco[count]);

            if (count==0 || preco[count]>nmaior)
            {
                nmaior=preco[count];
            }
            
            if (preco[count]==-1)
            {
                break;
            }
            
            while (veri1==0)
            {
                printf("\nQual é o tipo de produto? \n [1] mercearia \n [2] limpeza \n [3] Perecíveis \n R: ");
                scanf("%d",&tipo[count]);
    
                if (tipo[count]==1)
                {
                    contmarce++;
                    veri1=1;
                }
                else if (tipo[count]==2)
                {
                    contlimpe++;
                    veri1=1;
                }
                else if (tipo[count]==3)
                {
                    contpere++;
                    veri1=1;
                }
    
                else{
                    printf("Valor inválido, insira novamente");
                }
                
            }

            printf("\n Qual é a quantidade do estoque? R: ");
            scanf("%d",&qtd[count]);
            
            estoqval[i]= estoqval[i] + preco[count] * qtd[count];

            count++;
        }


        
        printf ("O valor total do estoque da %dº Filial é %.2f",i+1,estoqval[i]);
        if (estoqval[i] <60000)
        {
            nmenor6++;
        }
        

    }

    totaltipo= contlimpe + contmarce + contpere;

    if (totaltipo==0)
    {
        printf("\nNenhum produto foi inserido, então não há percentuais de tipos.\n");
    }

    else{
    contlimpe= (contlimpe/totaltipo) * 100;
    contmarce= (contmarce/totaltipo) * 100;
    contpere= (contpere/totaltipo) * 100; 
         }

    printf("\nDe todas as Filiais, %.2f %% dos produtos são referentes à marcearia \n %.2f %% dos produtos são referentes à limpeza \n e %.2f %% dos produtos são referentes à perecíveis\n",contmarce,contlimpe,contpere );

    printf("\n O maior valor de todos os produtos é R$ %f  ",nmaior);

    printf("\nCerca de %d filiais possuem um estoque menor que R$60.000\n",nmenor6);

    return 0;

}