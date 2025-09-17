/*Produtores de hortaliças de uma região do estado mantém uma cooperativa para a distribuição de
alface e repolho que abastecem os mercados da cidade.

Semanalmente a cooperativa recebe carregamentos de alface e repolho dos produtores associados (no máximo 50 produtores) e anota
o número de pés de alface e o número de pés repolho entregues por cada produtor. A cooperativa
quer fazer um levantamento sobre as hortaliças entregues nas últimas 15 semanas.

Faça um algoritmo que leia, para cada semana, o número de pés de alface e o número de pés
repolho entregues por cada produtor, após as leituras, mostre 1 destes relatórios:
- Relatório por semana: dado a semana, mostrar a quantidade de alface e de repolho entregues
nesta semana.
- Relatório por produtor: dado o produtor, mostrar a quantidade de alface e de repolho entregues
no período por este produtor.
- Relatório de análise de abastecimento: Mostre a quantidade total de alface e de repolho
entregues no período. Se a quantidade total de hortaliças for inferior a 500, emita um sinal de
“Risco de desabastecimento”, se a quantidade de alface for superior a 1300 ou a quantidade de
repolho for superior a 1200, emita um sinal de “Super produção”.Diga também se houve alguma
semana no período que não houve entregas.
Após imprimir um relatório, oferecer a opção para o usurário imprimir outro relatório se desejar.*/

#include <stdio.h>

int main()
{
    
    int repealf [2] [15] [50],qtdprodut; // tipo / semana / produtor 
    int contsemanas=0;


    printf("\n --- Recebendo dados --- \n");

    printf("\n Quantos produtores? ");
    scanf("%d",&qtdprodut);

    for (int i = 0; i < 15 ; i++)
    {
        printf("\n -- Semana %d -- \n",i+1);

        for (int j = 0; j < qtdprodut; j++)
        {
            
            
            printf("\n - Produtor %d - ",j+1);

            for (int k = 0; k < 2; k++)
            {
                    if (k==0)
                    {
                        printf("\n Alface:");
                    }
                    else if (k==1)
                    {
                        printf(" Repolho: ");
                    }
                
                    scanf("%d",&repealf[k] [j] [i]);
                    
                    
                    
            }
            
        }
        
    }
   

    while (1)
    {
        printf("\n --- Relátorios --- \n");
        printf("[1] - Por semana \n [2] - Por Produtor \n [3] - De Análise de Abastecimento");
        int escolha=0;
        scanf("%d",&escolha);

        switch (escolha)
        {
        case 1:
            printf("\n De qual semana você quer os dados? ");
             int semana,somas[2];
            somas[0]=somas[1]=0;
            scanf("%d",&semana);
            semana--;

            for (int i = 0; i < 2 ; i++)
            {
                for (int j = 0; j < qtdprodut; j++)
                {
                    somas[i]= somas[i] + repealf [i] [semana] [j];
                }
                
            }

            printf("\n Na semana foram entregues %d alfaces e %d repolhos ",somas[0],somas[1]);
            
            break;

        case 2:
            printf("\n De qual produtor você quer os dados? ");
            int produtor;
            scanf("%d",&produtor);
            produtor--;
            somas[0]=somas[1]=0;

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 15 ; j++)
                {
                   somas[i] = somas[i] + repealf [i] [j] [produtor];
                }
                
            }

            printf("\n Pelo produtor %d foram entregues %d alfaces e %d repolhos ",produtor+1,somas[0],somas[1]);
            
            break;
        
        case 3:
            somas[0]=somas[1]=0;
            int total = 0;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    int cont = 0;
                    for (int k = 0; k < qtdprodut; k++)
                    {
                        somas[i] = somas [i] + repealf [i] [j] [k];

                        if (repealf [i] [j] [k] == 0)
                        {
                            cont++;
                            if(cont == qtdprodut)
                            {
                                contsemanas++;
                            }
                        }
                        
                    }
                    
                }
                
            }
            
            total= somas[0] +somas[1];

            printf("\nA quantidade total de alface no periodo foi de %d e repolho de %d, totalizando %d hortaliças ",somas[0],somas[1],total);

            if (total < 500)
            {
                printf("\n ALERTA DE RISCO DE ABASTECIMENTO!!! ");
            }

            if (somas[0] > 1300 || somas[1] > 1200)
            {
                printf("\n ALERTA DE SUPER PRODUÇÃO!!!");
            }
            
            
            if (contsemanas>0)
            {
                printf("\n Houve %d semanas em que não houve entegas ", contsemanas);
            }
            

            break;
            
        default:
            break;
        }

        printf("\n Deseja imprimir outro relatório? \n [1] - Sim \n [2] - Não");
        int escolha1;
        scanf("%d",&escolha1);

        if (escolha1 == 2)
        {
           break;
        }
        
    }
        
}