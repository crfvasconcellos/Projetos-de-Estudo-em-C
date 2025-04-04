#include <stdio.h> 

int main () {

int nummaior, nummenor, num=0,count=0;
char resp = 's';

printf("Vou encontrar o maior núemro!!");

while (resp=='s')
{
    count++;
    printf("\nDigite um número:");
    scanf("%d",&num);

    if (count==1 || num>nummaior)
    {
        nummaior=num;
    }

    if (count==1 || num<nummenor)
    {
        nummenor=num;
    }

    resp= 'a';

    while (resp!='s' && resp!='n')
    {
    
    printf("Deseja continuar? s ou n ");
    scanf(" %c",&resp);
    
    if (resp!='s' && resp!='n')
    {
        printf("Resposta Inválida! Tente novamente! \n");
    }
    

    }
}

printf("Programa encerrado!! \n O maior número foi %d! \n O menor número foi %d!",nummaior,nummenor);

}