#include <stdio.h>

int cadastroimpre(int  contimpredio[3],int  impressoras [30] [3])
{
    printf("\nEm qual prédio deseja-se cadastrar a impressora? [1,2 ou 3] ");
            int predio;
            scanf("%d",&predio);
            if (predio>3 || predio<1)
            {
                printf("\nPrédio inválido");
                return 0;
            }
            
            predio--;
            printf("\nJá existem %d impressoras no predio %d ",contimpredio[predio],predio+1);
            if (contimpredio[predio]>=30)
            {
                printf("\nO prédio já possue 30 impressoras, não é possível inserir mais");
                return 0;
            }
        
            
            printf("\nQual o código da impressora? ");
            int codigo;
            scanf("%d",&codigo);
            int jaexiste=0;

            for (int i = 0; i < contimpredio[predio]; i++)
            {
                if (codigo== impressoras[i] [predio])
                {
                    printf("\n O código já existe!! Tente Outro!\n");
                    jaexiste= 1;
                }
            }

            if (jaexiste==0)
            {
                int ponteiro= contimpredio[predio];
                impressoras [ponteiro] [predio] = codigo;
                contimpredio[predio]++;
                printf("\n extistem %d impressoras agora ",contimpredio[predio]);
                printf("\nImpressora cadastrada com sucesso!!");
            }           
}

int solicitservico(int impressoras [30] [3],int servicos[30] [3], int qtd [3])
{
    printf("\nEm qual prédio deseja-se solicitar o serviço? (1,2 ou 3) \nR: ");
    int predio;
    scanf("%d",&predio);
    if (predio<=0 || predio >=4)
    {
        printf("\n Prédio Inválido!");
        return 0;
    }
    
    predio--;
    printf("\nQual o código da impressora? \nR: ");
    int codigo,numimpre=-1;
    scanf("%d",&codigo);

    for (int i = 0; i < qtd[predio]; i++)
    {
        if (codigo== impressoras[i][predio])
        {
            numimpre=i;
        }
        
        
    }

        if(numimpre==-1)
        {
            printf("\n ERROR Impressora não encontrada!!!");
            return 0;
        }
        else
        {
            printf("\n Impressora Encontrada!!");
        }
    

        if (servicos[numimpre] [predio] == 1 ||servicos[numimpre] [predio] == 2 || servicos[numimpre] [predio] == 3)
        {
            printf("\n Esta impressora já possui um serviço!");
            return 0;
        }
        else
        {
            printf("\n Qual serviço deseja-se solicitar? \n [1] - Troca de Tonner \n [2] - Reposição de Papel \n [3] - Assistência técnica \n R: ");
            int solicitacao;
            scanf("%d",&solicitacao);

            servicos[numimpre] [predio] = solicitacao;

            printf("\n Serviço atribuído com sucesso! ");
            return 1;
        }

        

}

int servconcl(int impressoras [30] [3],int servicos[30] [3], int qtd [3])
{

 printf("\nEm qual prédio deseja-se solicitar o serviço? (1,2 ou 3) \nR: ");
    int predio;
    scanf("%d",&predio);
    if (predio<=0 || predio >=4)
    {
        printf("\n Prédio Inválido!");
        return 0;
    }
    predio--;
    printf("\nQual o código da impressora? \nR: ");
    int codigo,numimpre=-1;
    scanf("%d",&codigo);

    for (int i = 0; i < qtd[predio]; i++)
    {
        if (codigo== impressoras[i][predio])
        {
            numimpre=i;
        }
        
        
    }

        if(numimpre==-1)
        {
            printf("\n ERROR Impressora não encontrada!!!");
            return 0;
        }
        else
        {
            printf("\n Impressora Encontrada!!");
        }
 
        
        if (servicos[numimpre] [predio] == 1 ||servicos[numimpre] [predio] == 2 || servicos[numimpre] [predio] == 3)
        {
            printf("\n Esta impressora possui um serviço! \n Deseja Remove-lo? \n [1] - SIM \n [2] - NÂO \n R: ");
            int respremo;
            scanf("%d",&respremo);

            if (respremo == 1)
            {
                servicos [numimpre] [predio] =0;
                printf("\n Serviço removido com sucesso!");
            }
            return 1;
        }
        else
        {
            printf("\n Essa impressora não possue nenhum serviço ativo! ");
            return 0;
        }
}

int relatorio(int impressoras [30] [3],int servicos[30] [3],int qtd [3])
{
    printf("\n === Relatório Geral === \n");
    int contserv[3]={0,0,0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < qtd[i]; j++)
        {   

            if (servicos[j] [i] == 1 ||servicos[j] [i] == 2 || servicos[j] [i] == 3)
            {

                contserv[i]++;
                printf("\n -- Impressora código %d prédio %d = Serviço: ",impressoras[j] [i],i+1);
                if (servicos[j] [i]==1)
                {
                    printf("Troca de Tooner");
                }
                else if (servicos [j] [i] == 2)
                {
                    printf("Reposição de Papel");
                }
                else if (servicos[j] [i] == 3)
                {
                    printf("Assistência Técnica");
                }
                
                
                
            }
        }
        
       
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("\n==============\n Prédio %d (IMPRESSORAS: %d SERVIÇOS: %d )",i+1,qtd[i],contserv[i]);
    
    }
    
    printf("\n Relatório Finalizado!! ");
}

int main()
{
    int impressoras [30] [3],servicos[30] [3],contimpredio[3]={0,0,0};
 
    printf("\n- Cadastro dos dados Iniciais -\n");

    for (int i = 0; i < 3; i++)
    {
        int qtd;
        printf("\n - Prédio %d \n\n",i+1);
        while (1)
        {
            printf("Quantas Impressoras deseja-se cadastrar? ");
            
            scanf("%d",&qtd);
            if (qtd <= 30)
            {
                break;
            }
            else if (qtd>30)
            {
                printf("\nQuantidade Inválida!");
            }
    
        }
        int codigo,jaexiste=0;

         printf("\nCódigo da impressora %d: ",1);
                    scanf("%d",&impressoras[0] [i]);
                    contimpredio[i]++;

        for (int j = 1; j < qtd; j++)
        {
                
                    while (1)
                    {
                        jaexiste=0;
                        printf("\nCódigo da impressora %d: ",j+1);
                        scanf("%d",&codigo);
                        for (int k = 0; k < contimpredio[i]; k++)
                        {
                            if (codigo== impressoras[k] [i])
                            {
                                jaexiste= 1;
                            }

                        }
                        
                        if (jaexiste==1)
                        {
                            printf("\nO código já existe!");
                        }
                        else if(jaexiste==0)
                        {
                            break;
                        }
                    }
                    

                    if (jaexiste==0)
                        {
                        
                            impressoras [j] [i] = codigo;
                            contimpredio[i]++;
                    
                        }

               
            
        }
            
    }

    while (1)
    {
        int quebrarloop=0;
        printf("\n-- MENU -- \n ");

        printf("\n [1] - Cadastrar Impressora \n [2] - Solicitar Serviço \n [3] - Serviços Concluídos \n [4] - Imprimir Relatório \n [5] - Sair ");
        int respostamenu;
        scanf("%d",&respostamenu);

        switch (respostamenu)
        {
        case 1:
            cadastroimpre(contimpredio,impressoras);
            break;

        case 2:

            solicitservico(impressoras,servicos,contimpredio);

            break;
        
        case 3:

            servconcl(impressoras,servicos,contimpredio);
            
            break;
        case 4:
            
            relatorio(impressoras,servicos,contimpredio);

            break;
        case 5:
            quebrarloop=1;
            break;
        default:
            printf("\nOpção Inválida!");
            break;
        }

        if (quebrarloop==1)
        {
            break;
        }
        
            
    }

    printf("\nPrograma Finalizado com sucesso!");
    return 0;
       
}