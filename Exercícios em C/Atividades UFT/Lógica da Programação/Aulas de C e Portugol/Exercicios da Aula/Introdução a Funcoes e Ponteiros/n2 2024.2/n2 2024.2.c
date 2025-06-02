#include <stdio.h>


void verificasenha()
{
    while (1)
    {
        printf("\n Qual  a senha de ADM? ");
        int senha;
        scanf("%d",&senha);

        if (senha== 1122)
        {
            printf("\n Acesso Liberado!");
            break;
        }

        else
        {
            printf("\n Senha incorreta!!");
        }
    }

}

int entreporescrito(int pacotes [180] [3], int * contador, int  destinos [3] )
{
     printf("\nQual o Escritório? ( 1 Palmas, 2 Gurupi e  3 Goiânia) ");
            int resposta=0;
            int pesototal=0,reforco=0;
            scanf("%d",&resposta);
            resposta--;

            printf("\n-Para o Destino %d -\n",resposta+1);
            printf("\nEstão destinados: %d pacotes ",destinos[resposta]);

            for (int i = 0; i < (*contador); i++)
            {   
                if (pacotes[i] [2]== resposta)
                {
                    pesototal= pacotes [i] [1] + pesototal;

                    if (pacotes[i][1]>50)
                    {
                    reforco=1;
                    }
                }
                
            
               

            }
            
            printf("\nO peso total da entrega será de %d kg ",pesototal);
            int lotes;
            lotes= destinos[resposta]/3;
            if (destinos[resposta] % 3 != 0) 
            {
                lotes++;
            }
          
            
            printf("\nSerão necessários %d lotes",lotes);
            if (reforco==1)
            {
                printf("\nREFORÇO NECESSÁRIO!!!\n");
            }
            
        return resposta;
}

int registropacote (int pacotes [180] [3], int * contador, int  destinos [3] )
{
    int cont=0;
    
    printf("\n-- Registro Pacote %d --\n",*contador+1);
    printf("Qual o código:  ");
    scanf("%d",&pacotes [*contador] [0]);
    printf("O peso: ");
    scanf("%d",&pacotes [*contador] [1]);
    printf("Destino \n [1] - Palmas \n [2] - Gurupi \n [3] - Goiânia \n R:  ");
    scanf("%d",&cont);
    cont--;

    pacotes [*contador] [2]= cont;

    if ((destinos [cont]) < 60)
    {
        (destinos [cont] ++);
        (*contador)++;
        return 1;
    }

    else 
    {
        printf("Limite de 60 pacotes para este destino atingido!\n");

        pacotes [*contador] [0] = 0;
        pacotes [*contador] [1] = 0;
        pacotes [*contador] [2]= 0;

        return 0;
    }

}


void menu(int pacotes [180] [3], int * contador, int  destinos [3])
{
    while (1)
    {
        printf("\n\n--- Menu --- \n");

        printf(" [1] Registrar novo pacote \n [2] Consultar pacote por código \n [3] Quantidade de pacotes geral \n [4] Verificar entrega por escritório \n [5] Autorizar entrega \n R: ");
        
        int resposta = 0;
        scanf("%d", &resposta);
        

        switch (resposta)
        {
        case 1:
            registropacote(pacotes,contador,destinos);
            break;

        case 2:
            
            printf("\n Qual o código do pacote? ");
            int memoria=0,resposta2=0;
            scanf("%d",&resposta2);
            for (int i = 0; i < 180; i++)
            {
                if (resposta2 == pacotes[i] [0])
                {
                    memoria= i;
                    printf("\n A memoria é %d ",memoria);
                }
                
            }
             
            if (memoria==0)
            {
                printf("\n pacote não encontrado ou não existente!! \n");
            }

            else{
                printf("\n ==DADOS DO PACOTE == \n");
                printf("- CÓDIGO: %d \n", pacotes[memoria] [0]);
                printf("- Peso: %d kg \n",pacotes [memoria] [1]);
                printf("- Destino: %d ( 1 Palmas, 2 Gurupi e  3 Goiânia)", pacotes[memoria] [2] +1);

            }
            
            break;

        case 3:
            printf("\nA quantidade de Pacotes na Central é de %d \n",(*contador));
            printf("\nCerca de %d em palmas, ou seja %.2f%%",destinos[0],((float)destinos[0]/(float)(*contador))*100);
            printf("\nCerca de %d em Gurupi, ou seja %.2f%%",destinos[1],((float)destinos[1]/(float)(*contador))*100);
            printf("\nCerca de %d em Goiânia, ou seja %.2f%%",destinos[2],((float)destinos[2]/(float)(*contador))*100);
        
            break;

        case 4:

            entreporescrito(pacotes,contador,destinos);

            

            break;

        case 5:
            verificasenha();
            int escritorio = entreporescrito(pacotes,contador,destinos);


            printf("\nDeseja Autorizar a Entrega? \n [1]-SIM \n [2]-NÂO\nR: ");
            scanf("%d",&resposta2);

            if (resposta2== 1)
            {
                int novaContagem = 0;
                for (int i = 0; i < *contador; i++) 
                {
                    if (pacotes[i][2] != escritorio) 
                    {
                        // Copia os pacotes que não são do escritório selecionado
                        pacotes[novaContagem][0] = pacotes[i][0];
                        pacotes[novaContagem][1] = pacotes[i][1];
                        pacotes[novaContagem][2] = pacotes[i][2];
                        novaContagem++;
                    } 
                    else 
                    {
                        // Diminui o contador do destino (opcional aqui, pois zeramos depois)
                        destinos[escritorio]--;
                    }

                    }
                    *contador = novaContagem;
                    destinos[escritorio] = 0;

            }
            

            break;

        default:
            printf("\nRespodta Inválida!!");
            break;
        }
    }
    
   
}

int main()
{
    int pacotes [180] [3],contadorpacotes = 0,destinos[3]= {0,0,0};

    verificasenha();

    for (int i = 0; i < 3; i++)
    {
       registropacote(pacotes,&contadorpacotes,destinos);
    }
    
    menu(pacotes,&contadorpacotes,destinos);

    

}