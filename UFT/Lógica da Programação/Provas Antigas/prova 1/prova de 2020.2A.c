#include <stdio.h>

/*Uma cooperativa de produtores rurais possui um armazém para armazenagem de arroz, feijão e
milho. Cada produtor chega com o seu carregamento e este é contabilizado e armazenado. As
sacas que contém produto orgânico, recebem um selo.
Faça um algoritmo que receba como entrada, para cada produtor, o número de sacas entregues e,
para cada saca, seu conteúdo (arroz, feijão ou milho) e se é orgânico ou não. Para encerrar as
atividades do dia, será digitado o código -1 na variável de entrada referente ao número de sacas.
Após o encerramento das atividades, o algoritmo deve imprimir o seguinte relatório:
- Porcentagem de sacas que receberam o selo orgânico,
- Quantidades de sacas recebidas de cada grão,
- Quantidade de sacas da maior entrega do dia,
- Quantos produtores entregaram mais de 15 sacas de arroz,
- Média de sacas entregue por produtor*/

int main() 
{

    int contprodutor, sacas, orgorn,tipo,contarroz,contefeijao,contmilho,contorganic,contnaorg,maiorentrga,contarrozprodutor,contarrozprodutor2,totalsacos;
    contprodutor = sacas =tipo= orgorn= contorganic=contnaorg=maiorentrga=contarrozprodutor =contarrozprodutor2=totalsacos=0;
    contarroz=contefeijao=contmilho=0;
    

    while (1)
    {
        contarrozprodutor=0;
        sacas=0;
        printf("\n---PRODUTOR %d ---",contprodutor+1);
        printf("\nQuantas sacas foram produzidas? [-1 para encerrar] ");
        scanf("%d",&sacas);

       

        if (contprodutor==0 || sacas>maiorentrga)
        {
            maiorentrga=sacas;
        }
        

        if (sacas<=0)
        {
            break;
        }

        totalsacos= totalsacos +sacas;
        contprodutor++;

        for (int i = 1; i <= sacas; i++)
        {
            tipo=0;
            orgorn=0;
           

            while (1)
            {
                printf("\nQual o tipo da saca %d [1 - Arroz 2- Feijão 3- Milho]? \n ",i);
                scanf("%d",&tipo);
                
                if (tipo==1)
                {
                    contarroz++;
                    contarrozprodutor++;
                    break;
                }
                else if (tipo==2)
                {
                    contefeijao++;
                    break;
                }
                else if (tipo==3)
                {
                    contmilho++;
                    break;
                }
                else
                {
                    printf("\nValor da saca inválido, tente novamente!\n");            
                }
                
            }

            while (1)
            {
                printf("\nEla é 1-Orgânica ou 2-Não Orgânica ?\n");
                scanf("%d",&orgorn);

                if (orgorn==1)
                {
                    contorganic++;
                    break;
                }
                else if (orgorn==2)
                {
                    contnaorg++;
                    break;
                }
                else
                {
                    printf("\nValor da saca inválido, tente novamente!\n");    
                }
                
                
            }
            
            
           
            
            
        }

        if (contarrozprodutor>15)
        {
            contarrozprodutor2++;
        }
        
        
        

    }
    
    printf("\n--- PROGRAMA FINALIZADO! ---\n");

    if (contorganic>0)
    {
        float porcentagemorganic= ((float)contorganic/(float)totalsacos)*100;
        printf("\n Cerca de %.1f%% das sacas receberam o selo organico! ",porcentagemorganic);
    }
    
    printf("\n Foram recebidas %d sacas de Arroz, %d de Feijão e %d de Milho ",contarroz,contefeijao,contmilho);
    printf("\n A quantidade de sacas da maior entrega do dia foi de %d ",maiorentrga);
    printf("\n Cerca de %d produtores do total de %d entregaram mais de 15 sacas de arroz ",contarrozprodutor2,contprodutor);
    printf("\n A média de sacas por produtor foi de %.2f ",(float)totalsacos/contprodutor );
    


}