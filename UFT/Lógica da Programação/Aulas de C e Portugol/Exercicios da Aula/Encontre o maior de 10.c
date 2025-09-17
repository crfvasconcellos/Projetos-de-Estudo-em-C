#include <stdio.h>

int main() {


int nummaior,nummenor,num;

for (int i=1;i<=10;i++)
{
    printf("\nDigite o %dº número: ",i);
    scanf("%d",&num);

    if (i==1 || num>nummaior)
    {
        nummaior=num;
    }
    
    if (i==1 || num<nummenor)
    {
        nummenor=num;
    }
    
}

printf("O maior número é %d! \nO menor número é %d!",nummaior,nummenor);


}