#include <stdio.h>


void somar (int x, int y)
{
 printf("A somna de %d + %d é %d ",x,y,x+y);
}

int main () 
{
    int a = 10;
    int b = 20;

    somar(a,b);
}