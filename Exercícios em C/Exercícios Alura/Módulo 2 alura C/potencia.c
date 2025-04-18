#include <stdio.h>

void potenci(int x, int y)
{
    int resultado=0;
    for (int i = 1; i < y; i++)
    {
        if(resultado==0)
        {
            resultado= x * x;
        }
        else
        {
            resultado= x * resultado;
        }
        
    }
    
    printf("%d elevado à %d é %d ",x,y,resultado);
}

int main ()
{   
    int num[2];
    printf("\n Digite dois números: ");
    scanf("%d",&num[0]);
    scanf("%d",&num[1]);

    potenci(num[0],num[1]);

    return 1;

}