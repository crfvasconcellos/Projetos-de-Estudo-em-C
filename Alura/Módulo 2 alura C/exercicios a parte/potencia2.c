#include <stdio.h>


void potencia(int* resultado,int x,int y)
{
    (*resultado)= x;

    for ( int i=1; i < y ; i++)
    {
      (*resultado)= (*resultado) * x; 
    }
}

int main()
{

int a, b,resultado;

printf("\n Digite 2 números: \n");
scanf("%d %d",&a,&b);

potencia(&resultado,a,b);

printf(" %d elevado à %d é %d ",a,b,resultado);

}