#include <stdio.h>
#include <string.h>

#define max_bichos 60 


typedef struct {
    int codigo;
    int tipo; // 1 -  gato 2- cachorro pequeno  3 - cachorro médio 4 - cachorro grande
    int sexo; // 1 - masc 2 - fem
    int idade; // 1- filhote 2- Adulto 
    char nome[30];
    int tutor; // 2 - nao 1 - tem
}Pet;

void ler(Pet * dado)
{
            printf("\n Qual o Tipo do animal? (1 -  gato 2- cachorro pequeno  3 - cachorro médio 4 - cachorro grande): ");
            scanf("%d",&dado->tipo);
            printf("\n Qual o sexo dele? (1- Masculino 2- Feminino): ");
            scanf("%d",&dado->sexo);
            printf("\n Qual a idade? (1- Filhote 2 - Adulto): ");
            scanf("%d",&dado->idade);
            printf("\n Tem tutor? (1- sim  2 - não)");
            scanf("%d",&dado->tutor);
            if (dado->tutor == 1)
            {
                printf("\n Qual o nome do tutor? (Caso não tenha coloque 'sem'): ");
                scanf("%s",dado->nome);
            }

            
            printf("\n Animal Lido!");
            

}

void registrar (Pet dados [60][3],Pet dado,int * qtdtot, int  qtd[3] )
{
     printf("\n Em qual abrigo desej-ase Cadastrar o animal?(1,2 ou 3) ");
    int abrigo;
    scanf("%d",&abrigo);
    abrigo--;
    for (int i = 0; i < max_bichos; i++)
    {
        if (dados[i][abrigo].codigo ==0 && qtd[abrigo]<= max_bichos)
        {
            dados[i][abrigo]=dado;
            dados[i][abrigo].codigo= i+(60)*abrigo;
            qtd[abrigo]++;
            (*qtdtot)++;
            printf("\n Animal Registrado!, o código dele é %d !",dados[i][abrigo].codigo);
        }
        
        
    }
}

int mostrar(Pet dados [60][3], int qtd[3])
{
    printf("\n \n Em cada Abrigo...");
    for (int i = 0; i < 3; i++)
    {
        printf("\n\n Abrigo %d ====== ",i+1);
        for (int j = 0; j < qtd[i]; j++)
        {
            printf("\n Pet %d",j+1);
            printf("\nCódigo: %d",dados[j][i].codigo);
            printf("\nTipo: %d",dados[j][i].tipo);
            printf("\nSexo: %d",dados[j][i].sexo);
            printf("\nIdade: %d",dados[j][i].idade);
            if (dados[j][i].tutor== 1)
            {
                printf("\nNome do Titular: %s",dados[j][i].nome);
            }
            else
            {
                printf("\nNome do Titular: não possue");
            }
            
            
            printf("\n\n");
        }
        
    }
    
}

int main()
{
    Pet dados [60][3]={0};
    int qtd[3]={0},qtdtot=0;

    printf("\n -- Resgate de Animais --");
    for (int i = 0; i < 3; i++)
    {
        printf("\n Quantos animais foram resgatados no abrigo %d? ",i+1);
        scanf("%d",&qtd[i]);
    }
    
    for (int j = 0; j < 3; j++)
    {
        printf("\n Abrigo %d ",j+1);
         for (int i = 0; i < qtd[j]; i++)
        {
            printf("\n - Pet %d",i+1);
            printf("\n Qual o Tipo do animal? (1 -  gato 2- cachorro pequeno  3 - cachorro médio 4 - cachorro grande): ");
            scanf("%d",&dados[i][j].tipo);
            printf("\n Qual o sexo dele? (1- Masculino 2- Feminino): ");
            scanf("%d",&dados[i][j].sexo);
            printf("\n Qual a idade? (1- Filhote 2 - Adulto): ");
            scanf("%d",&dados[i][j].idade);
            printf("\n Tem tutor? (1- sim  2 - não) ");
            scanf("%d",&dados[i][j].tutor);
            if (dados[i][j].tutor== 1)
            {
                printf("\n Qual o nome do tutor? (Caso não tenha coloque 'sem nome'): ");
                scanf("%s",&dados[i][j].nome);
            }
            dados[i][j].codigo= i+(60)*j;
            printf("\n Animal Lido!, o código dele é %d !",dados[i][j].codigo);

        }
    }
    
    int resposta=0;
    while (resposta != -1)
    {
        printf("\n== Menu ==");
        printf("\n [1] Cadastrar pet: cadastra um novo animal em determinado abrigo, se houver espaço na matriz Dados. Obs.: Chama a função “ler”, depois a função “registrar” e depois a função “mostrar”. \n [2] Busca pet para adoção: dado o tipo do animal, mostrar todos destes que não tem tutor. \n [3] Adotar: dado o código do animal, inserir o nome do tutor. Obs.: Parar a busca quando encontrar o código. Se não encontrar o código, informar com uma mensagem na tela. Se o animal já tiver um tutor, perguntar se deseja editar o nome. \n [4] Relatório por abrigo: dado o abrigo, mostrar quantos cachorros e quantos gatos estão registrados, quantos destes são filhotes e qual a porcentagem de animais sem tutor. \n [5] Mostrar: mostrar todos os dados dos animais em cada abrigo. -1 Para sair ");
        scanf("%d",&resposta);
        Pet dado={0};
        int tipo;

        switch (resposta)
        {
        case 1:
            ler(&dado);
            registrar(dados,dado,&qtdtot,qtd);
            mostrar(dados,qtd);
            break;
        

        case 2:
            printf("\n Qual o Tipo do animal deseja adotar? (1 -  gato 2- cachorro pequeno  3 - cachorro médio 4 - cachorro grande): ");
            scanf("%d",&tipo);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < qtd[i] ; j++)
                {
                    if (dados[j][i].tipo== tipo)
                    {
                        printf("\n\n-Pet %d.%d",i+1,j+1);
                        printf("\nCódigo: %d",dados[j][i].codigo);
                        printf("\nTipo: %d",dados[j][i].tipo);
                        printf("\nSexo: %d",dados[j][i].sexo);
                        printf("\nIdade: %d",dados[j][i].idade);
                        printf("\nNome do Titular: não possue");
                    }   
                }
            }
            break;
        default:
            printf("\n Nenhuma opção Válida foi registrada!");
            break;
        }
    }
    
    printf("\n Programa Finalizado!");
    return 0;
}