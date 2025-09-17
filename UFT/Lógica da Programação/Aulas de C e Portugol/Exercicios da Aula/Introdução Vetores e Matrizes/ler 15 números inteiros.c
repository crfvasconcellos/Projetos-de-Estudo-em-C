// Ler 15 números inteiros, mostrar o maior deles e mostrar esses números em ordem inversa da leitura.

#include <stdio.h>

int main()

{

    int num[15],nummaior=0;

    for (int i = 0; i < 10; i++)
    {
        num[i]=0;
        printf("\n Qual o valor do %d º número? ",i+1);
        scanf("%d",&num[i]);

        if (num[i]> nummaior || i==0)
        {
            nummaior= num[i];
        
        }
        
    }

    printf("\nO maior valor é o %d \n",nummaior);
    for (int j = 9; j >= 0; j--)
    {
        printf("\nO Valor %d º é %d ",j+1 ,num[j]);
    }
    

    


}