#include <stdio.h>


int main(){

    int numeros[10];

    int x;

    for (int i = 0; i < 10; i++)
    {
        printf("\n Diga o número %d: ",i+1);
        scanf("%d",&numeros[i]);
    }
    

    printf("\n Qual o numero x? ");
    scanf("%d",&x);
    printf("\n Os Múltiplos desse número são: ");
    for (int i = 0; i < 10; i++)
    {
        
        if (numeros[i] % x == 0)
        {
            printf("\n %d ",numeros[i]);
        }
        
    }
    


}