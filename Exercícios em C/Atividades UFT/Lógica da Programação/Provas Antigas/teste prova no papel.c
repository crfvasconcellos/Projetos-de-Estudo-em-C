#include <stdio.h>

int main() 
{
    int modalidade,mednutri,contmednutri,contotal,contmatporano[7],contfut1[7],contfut2[7],contfut3[7],contnat1[7],contnat2[7],contnat3[7],turmanat,totalpresenca[7],presenca,contnatacaotot,todasmatriculas;

    modalidade=mednutri=contmednutri=contotal=turmanat=presenca=contnatacaotot=todasmatriculas=0;

    for (int i = 0; i < 7; i++)
    {
        contmatporano[i]=totalpresenca[i]=0;
        printf("\n%d---------\n",2018+i);

        while (1)
        {
            
            int idade=0;
            mednutri=modalidade=0;
            printf("\nQual é a idade do %d º aluno? (-1 para parar)",contmatporano[i]+1);
            scanf("%d",&idade);

            if (idade<=0)
            {
                break;
            }

            todasmatriculas++;
            contmatporano[i]++;

            printf("\nQual a modalidade [1 - Futebol 2 -Natação ]: ");
            scanf("%d",&modalidade);

            if (modalidade==1)
            {
                if (idade>=4 && idade<=6)
                {
                    contfut1[i]++;
                }

                else if (idade>=7 && idade <=10)
                {
                    contfut2[i]++;
                }
                
                else if (idade>=11 && idade <=13)
                {
                    contfut3[i]++;
                }     
            }

            else if (modalidade==2)
            {
                contnatacaotot++;
                printf("\nQual a turma de natação? [1- Iniciante 2- Intermwdiário 3- Treinamento ]: ");
                scanf("%d",&turmanat);

                if (turmanat==1)
                {
                    contnat1[i]++;
                }
                else if (turmanat==2)
                {
                    contnat2[i]++;
                }

                else if (turmanat==3)
                {
                    contnat3[i]++;
                }
                
                
                
            }
            
            printf("\nPossue acompanhamento médico e nutricional? (1- sim 2- não): ");
            scanf("%d",&mednutri);

            if (mednutri==1)
            {
                contmednutri++;
            }

            for (int j = 0; j < 12; j++)
            {
                presenca=0;
                printf("\n O aluno estava presente no %dº mês? (1-sim 2 - não) ",j+1);
                scanf("%d",&presenca);

                if (presenca==1)
                {
                    totalpresenca[i]++;
                }
                

            }
            printf("\nForam feitas %d matrículas no ano,sendo de futebol: turma 1 (%d),turma 2 (%d), turma 3 (%d) e de natação: Iniciante (%d), intermediário (%d) e treinamento(%d) ", contmatporano[i],contfut1[i],contfut2[i],contfut3[i],contnat1[i],contnat2[i],contnat3[i]);

            float medanualpresenca= (float)totalpresenca[i]/(float)contmatporano[i];
            printf("\n A média de presença anual é de %.2f ",medanualpresenca);
        
        
    }
   
   
        
    }
    
    printf("\n Na natação foram realizados %d matrículas nos últimos 7 anos ",contnatacaotot);
    printf("\n A porcentagem de matrículas com acompanhamento médico e nutricional nos últimos 7 anos foi de %.2f%% ",((float)contmednutri/(float)todasmatriculas)*100);


}