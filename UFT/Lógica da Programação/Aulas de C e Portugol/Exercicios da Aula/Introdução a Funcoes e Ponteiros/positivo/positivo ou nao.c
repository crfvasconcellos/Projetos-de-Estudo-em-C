#include <stdio.h>

void testador(float x)
{
    if (x>0)
    {
        printf("positivo");
    }

    else if (x<0)
    {
        printf("negativo");
    }

    else{
       printf("nulo");
    }
    
    
}



int main()
{
    float num;
    printf("digite um valor: ");
    scanf("%f",&num);

    printf("o resultado é ");
    testador(num);



}