#include <stdio.h>

int main() {

int i;
int soma;
soma=0;

for (i = 0; i < 101; i++)
{   
    
    soma = soma + i;

    if (i != 100)
    {
        printf("%d +",i);
    }
    
    if (i == 100)
    {
    printf("%d = ",i);
    }

    
}
printf("%d",soma);
}