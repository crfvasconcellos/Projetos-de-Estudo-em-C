//Ler a idade de 13 pessoas, mostrar a média das idades, o número de pessoas com idade abaixo da média e o número de menores de idade.

#include <stdio.h>

int main()
{

    int num[13],mediaida=0,contmenoridade=0;

    for (int i = 0; i < 13; i++)
    {
       num[i]=0;
       printf("\n Qual o valor do %d º número? ",i+1);
       scanf("%d",&num[i]);

       mediaida= mediaida + num[i];

       if (i==12)
       {
        mediaida= mediaida/13;
       }
       

       

       
    }
    

    for (int j = 0; j < 13 ; j++)
    {
        if (num[j]< mediaida)
       {
         contmenoridade++;
       }
       
    }

    printf("\n A média das idades é %d ",mediaida);
    printf("\n Cerca de %d pessoas estão com a idade abaixo da média ",contmenoridade);
    


}