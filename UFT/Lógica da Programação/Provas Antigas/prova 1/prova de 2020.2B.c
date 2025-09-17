#include <stdio.h>

/*Uma editora pretende fazer uma análise estatística sobre os dados de seus pedidos nos últimos
anos. Faça um algoritmo que receba como entrada, para cada pedido realizado no período, o
número de livros encomendados e, para cada livro, receba o seguimento do livro (Fundamental,
Médio ou Superior) e se o livro teve incentivo fiscal ou não. Para encerrar a coleta dos dados, será
digitado o código -1 na variável de entrada referente ao número de livros do pedido.
Após o encerramento das leituras, o algoritmo deve imprimir o seguinte relatório:
- Porcentagem de livros de cada seguimento,
- Número total de livros que não receberam incentivo fiscal,
- Média de livros por pedido no período.
- Quantos pedidos tiveram mais de 20 livros com incentivo fiscal,
- Quantos livros tinha o maior pedido.*/

int main()
{
    int ano,totallivros,qtdlivros,escolhalivro,contfundamental,contmedio,contsuperior,escolhafisxal,contnaoincentivo,contmais20,qtdmais20,maiorpedido;

    ano=0,contfundamental=0,totallivros=0,contmedio=contnaoincentivo=contsuperior=maiorpedido=qtdmais20=totallivros=0;

    while (1)
    {
        qtdlivros=0;
    
        printf("\nQuantos livros foram pegos no %dº Pedido (-1 para parar) ? \n",ano+1);
        scanf("%d",&qtdlivros);  
        

        if(qtdlivros<0)
        {
            break;
        }

        totallivros= totallivros + qtdlivros;


        if (ano==0 || qtdlivros > maiorpedido )
        {
            maiorpedido=qtdlivros;
        }
        
        ano++;
        contmais20=0;

        for (int i = 0; i < qtdlivros; i++)
        {
            printf("\nQual o tipo do %dº livro? (1-  Fundamental 2- Médio 3-Superior) \n",i+1);
            scanf("%d",&escolhalivro);

            if (escolhalivro==1)
            {
                contfundamental++;
            }

            else if (escolhalivro==2)
            {
                contmedio++;
            }

            else if (escolhalivro==3)
            {
                contsuperior++;
            }
            
            escolhafisxal=0;
            
            printf("\nO livro teve incentivo fiscal? (1-sim 2-nao) \n");
            scanf("%d",&escolhafisxal);

            if (escolhafisxal==2)
            {
                contnaoincentivo++;
            }

            else if (escolhafisxal==1)
            {
                contmais20++;

                if(contmais20>20)
                {
                    qtdmais20++;
                }
            }
            

            
            
            
        }
        

        
    }

    float porcentfund= (float)((float)contfundamental/(float)totallivros)*100;
    float porcentmed= (float)((float)contmedio/(float)totallivros)*100;
    float porcentsup= (float)((float)contsuperior/(float)totallivros)*100;

    printf("\n o total de livros foi %d\n",totallivros);
    printf("\n No geral, foram pegos %.2f%% da categoria fundamental, %.2f%% da médio e %.2f%% da superior \n ",porcentfund,porcentmed,porcentsup);
    printf("\n A quantidade total de livros que não receberam incentivo fiscal foi de %d \n",contnaoincentivo);
    printf("\n A média de livros por pedido no ano foi de %.2f ",(float)totallivros/(float)ano);
    printf("\n A quantidade de pedidos com mais de 20 livros com icentivo fiscal foi de %d \n",qtdmais20);
    printf("\nO maior pedido realizado tinha cerca de %d livros \n",maiorpedido);

    




}