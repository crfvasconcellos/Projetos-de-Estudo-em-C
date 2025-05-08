/*Ler a idade de 5 grupos de 13 pessoas e mostrar o número de pessoas com idade abaixo da
média de idades do seu grupo. */

#include <stdio.h>


int main ()
{
   int idadepessoas [15] [5],media[5],contabaixomedia=0; // pessoas / grupos 

   printf(" \n Recebendo dados...");
   for (int i = 0; i < 5; i++)
   {
        media[i]=0;
        printf("\n --- Grupo %d --- \n",i+1);
        for (int j = 0; j < 15; j++)
        {
            printf("\nIdade da pessoa %d: ",j+1);
            scanf("%d",&idadepessoas[j] [i]);
            media[i]= media[i] + idadepessoas[j] [i];
            
        }

        media[i]= media[i]/15;
        

        for (int j = 0; j < 15; j++)
        {
            if (idadepessoas[j] [i] < media[i])
            {
                contabaixomedia++;
            }
            
        }
        
        
   }

   printf("\nA quantidade de pessoas que tiveram a idade abaixo da média de idade do seu grupo foi de %d",contabaixomedia);
   
}