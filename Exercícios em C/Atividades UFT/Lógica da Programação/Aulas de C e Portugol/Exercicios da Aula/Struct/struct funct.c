#include <stdio.h>


typedef struct
{
    char Gerente[30];
    char Funcs[5] [30];

}empresa;

void cadastrar(empresa * p)
{
    printf("\nNome do Gerente: ");
    scanf("%s",p->Gerente);
    
    for (int i = 0; i < 5; i++)
    {
        printf("\nFuncionario %d: ",i+1);
        scanf("%s",p->Funcs[i]);
    }
    
}


void imprimirPessoa(empresa P)
{
   printf("Gerente: %s\n",P.Gerente);

   for (int i = 0; i < 5; i++)
    {
        printf("\nFuncionario %d: %s ",i+1,P.Funcs[i]);
    }

}


void funcpornum(empresa P)
{
    printf("Número do Funcionário: ");
    int num;
    scanf("%d",&num);
    num--;
    printf("\n Funcionário %d: %s \n",num+1,P.Funcs[num]);

}


int main()
{
    empresa mac;

    cadastrar(&mac);    
   

    

    while (1)
    {
        printf("\n O que Você deseja? \n [1] - Cadastrar \n [2] - Mostrar Funcionario por número \n [3] - Mostrar Todos \n R:");
        int escolha=0;
        scanf("%d",&escolha);

        switch (escolha)
        {
        case 1:
            cadastrar(&mac);
            break;
        
        case 2:
            funcpornum(mac);
            break;
        case 3:
            imprimirPessoa(mac);
            break;
        default:
            printf("\nOpção Inválida, Tente Novamente!! \n");
            break;
        }
    }
    
}