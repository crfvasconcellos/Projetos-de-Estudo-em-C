#include <stdio.h>

/*Durante 6 meses, 30 funcionários de um shopping participaram de um programa de exercícios
ocupacionais. Durante o programa foram registrados, para cada funcionário, sua idade, medições
mensais de frequência cardíaca e várias medições do peso corporal. Elabore um algoritmo que,
para cada funcionário, mostre seu peso médio e a maior frequência cardíaca registrada durante o
programa.
No final mostre ainda a percentagem de funcionários que tiveram sua maior frequência
cardíaca ultrapassando 105 bpm e quantos tiveram o peso médio maior que seu peso final,
quantos tiveram o peso médio menor que seu peso final e quantos foram iguais.
obs.: Na leitura das medições do peso, utilize o valor -1 para indicar que a sequência de medições
finalizou (o valor -1 na entrada é o código para a parada da estrutura de repetição e não deve ser
processado. Considere que os valores de peso e frequência cardíaca são valores reai*/



int main()
{

    int idade[30],contpmafinal=0,contpmefinal=0,contpigualfinal=0;
    float freqcard[6],fremaior[30],contfreq105=0,porcent05;

    for (int i = 0; i < 30; i++)
    {
        int contp=0;
        float pesos,pesofinal=0,somap=0,medp=0;
        fremaior[i] = 0; 


        printf("\n--- FUNCIONÁRIO %d ---\n",i+1);
        printf("Sua idade: ");
        scanf("%d",&idade[i]);

        for (int j = 0; j < 6; j++)
        {
            freqcard[j]=0;
             printf("\nQual foi a sua frequência cardíaca no %dº mês? ",j+1);
             scanf("%f",&freqcard[j]);

             if (j==0 || freqcard[j]>fremaior[i])
             {
                fremaior[i]= freqcard[j];
             }
             
        }
            if (fremaior[i]>=105)
            {
                contfreq105++;
            }
        

        while (1)
        {
            pesos=0;
            printf("\nQual foi seu peso %dº? (-1 para prosseguir): ",contp+1);
            scanf("%f",&pesos);

            if (pesos<1)
            {
                break;
            }
            pesofinal=pesos;

            somap= somap + pesos;
            contp++;
        }   

        if (contp == 0) {
            printf("Nenhum peso informado!\n");
            medp = 0;
        } else {
            medp = somap / contp;
        }
        

        if (pesofinal>medp)
        {
            contpmafinal++;
        }
        else if (pesofinal<medp)
        {
            contpmefinal++;
        }

        else 
        {
            contpigualfinal++;
        }
        
        

        
        
        printf("\nA maior Frequência Cardíaca registrada do funcionário foi %.2f bpm ",fremaior[i]);
        printf("\nA média dos pesos do paciente é %.2f \n",medp);


    }

    porcent05= (contfreq105/30)*100;
    printf("\n---PROGRAMA FINALIZADO!!!---\n");
    printf(" \nA percentagem de funcionários que tiveram sua maior frequência cardíaca ultrapassando 105 bpm foi de %.1f%% ",porcent05);
    printf("\n Cerca de %d funcionários tiveram o peso médio maior que seu peso final, %d tiveram o peso médio menor que seu peso final e %d foram iguais.",contpmafinal,contpmefinal,contpigualfinal);
}