#include <stdio.h>

typedef struct{
    int presidencia;
    int estado;
    int idade;
    int sal;
} pessoas;


void contagem(pessoas p[30][3],int pres1est2,int qtd[3])
{
    int cont[5]={0,0,0,0,0},contot=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < qtd[i]; j++)
        {   
            if (pres1est2==1)
            {
                

                switch (p[j][i].presidencia)
                {
                case 1:
                    cont[0]++;
                    contot++;
                    break;
                case 2:
                    cont[1]++;
                    contot++;
                    break;
                case 3:
                    cont[2]++;
                    contot++;
                    break;
                case 4:
                    cont[3]++;
                    contot++;
                    break;
                
                default:
                    break;
                }


            }
            if (pres1est2==2)
            {
                switch (p[j][i].estado)
                {
                case 1:
                    cont[0]++;
                    contot++;
                    break;
                case 2:
                    cont[1]++;
                    contot++;
                    break;
                case 3:
                    cont[2]++;
                    contot++;
                    break;
                case 4:
                    cont[3]++;
                    contot++;
                    break;
                
                default:
                    break;
                }
            }
            if (pres1est2==3)
            {

            }
        }
    }
    
    if (pres1est2==1)
    {
        float porcentagem17,porcentagem26,porcentagembranc,porcentagemindeci;
        porcentagem17=  ((float)cont[0] / (float)contot) * 100;
        porcentagem26= ((float)cont[1] / (float)contot) * 100;
        porcentagembranc= ((float)cont[2] / (float)contot) * 100;
        porcentagemindeci= ((float)cont[3] / (float)contot) * 100;
        printf("\n A %% de votos de cada foi de %.2f%% para 17 %.2f%% para 26 %.2f%% para branco e %.2f%% para indecisos ",porcentagem17,porcentagem26,porcentagembranc,porcentagemindeci);
    }
}
void menu(pessoas p[30][3],int qtd[3])
{
    printf("\n --- MENU --- \n");
    printf("\n O que você deseja? \n [1] Intenção de votos para Presidência \n [2] Intenção de votos para Governo \n [3] Fidelidade Partidária \n [4] Intenção à Presidência por faixa salarial \n [5] Intenção final dos mais jovens \n [6] Relatório por mês \n R: ");
    int resposta;
    scanf("%d",&resposta);

    switch (resposta)
    {
    case 1:
        contagem(p,1,qtd);

        break;
    case 2:
        contagem(p,2,qtd);
        break;
    default:
        break;
    }
}

int main()
{
    pessoas p[30][3];

    FILE *F= fopen("votos.bin","rb");
    if (F == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int qtd[3];
    fread(qtd, sizeof(int), 3, F);

    for (int i = 0; i < 3; i++)
    {
        for (int j= 0; j < qtd[i]; j++)
        {
            fread(&p[j][i],sizeof(p[j][i]),1,F);
        }
    }   
    
    fclose(F);

    menu(p,qtd);
}