#include <stdio.h>

/*10 atletas foram monitorados por 8 semanas. Para cada atleta foram registrados sua idade, várias
medições do nível de oxigênio no sangue e medições semanais de frequência cardíaca. Elabore um
algoritmo que, para cada atleta, mostre seu nível médio de oxigênio no sangue e a maior
frequência cardíaca registrada durante o período de monitoramento. No final mostre ainda
quantos tiveram a média de oxigênio no sangue abaixo de 96 e a percentagem de atletas com
mais de 25 anos e a percentagem com menos de 16 anos.

obs.: Na leitura das medições de nível de oxigênio no sangue, utilize o valor -1 para indicar que a
sequência de medições finalizou (o valor -1 na entrada é o código para a parada da estrutura de
repetição e não deve ser processado). Considere que os valores de nível de oxigênio e frequência
cardíaca são valores reais*/

int main (){

    int idade[10],countoxgeral=0;
    float oxigenio,somoxi[10],contoxi[10],medoxi[10],freqcardic,mfreqc[10],cont25=0,cont16=0;


    for(int i=0;i<10;i++){

        somoxi[i]=0;
        contoxi[i]=0;
        mfreqc[i]=0;

        printf("\n\n---Formullário Atleta %d --- \n",i+1);
            
        printf("Idade: ");
        scanf("%d",&idade[i]);

        if (idade[i]>25)
        {
            cont25++;
        }
        else if (idade[i]<16)
        {
            cont16++;
        }
        
        

        while (1)
        {
            oxigenio=0;
            printf("\nQuais os níveis de Oxigênio no sangue (-1 para terminar): ");
            scanf("%f",&oxigenio);

            if (oxigenio==-1)
            {
                break;
            }
            

            somoxi[i]= somoxi[i] + oxigenio;
            contoxi[i]++;

        }

        medoxi[i]= somoxi[i]/contoxi[i];

        if (medoxi[i]<96)
        {
            countoxgeral++;
        }
        

        for (int j = 0; j < 8; j++)
        {
            freqcardic=0;
            printf("\n Frequencia Cardíaca Semana %d: ",j+1);
            scanf("%f",&freqcardic);

            if (j==0 ||freqcardic>mfreqc[i])
            {
                mfreqc[i]=freqcardic;
            }
            
        }
        
        

        printf("\n O nível médio de oxigênio no sangue do atleta foi %.2f \n",medoxi[i]);
        printf("A maior frequência cardíaca registrada pelo atleta foi de %.2f bpm",mfreqc[i]);


    }

    if (cont16!=0)
    {
        cont16= (cont16/10) * 100;
    }
    
   if(cont25!=0)
   {
    cont25= (cont25/10) * 100;
   }


    printf("\n PROGRAMA ENCERRADO! \n");
    printf("Cerca de %d atletas obtiveram a média de oxigênio no sangue abaixo de 96 ",countoxgeral);
    printf("\n Cerca de %.2f%% dos atletas eram menores de 16 anos e %.2f%% dos atletas eram maiores de 25 anos!",cont16,cont25);

}