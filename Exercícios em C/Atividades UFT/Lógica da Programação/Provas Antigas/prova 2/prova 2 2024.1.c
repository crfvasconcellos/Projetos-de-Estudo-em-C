/*Uma importadora possui dois pontos de recebimento (um em Curitiba o outro em São Paulo) e
deseja analisar a movimentação de pacotes recebidos nos últimos 4 anos. Faça um algoritmo que
receba como entrada o número de pacotes recebidos em cada mês para cada ponto de recebimento.
Após as leituras dos dados de entrada, disponibilize os seguintes relatórios para que o usuário
escolha aquele que deseja:
[1] Relatório por mês (dados o mês, o ano e o ponto de recebimento, mostre o número de pacotes
recebidos no referido mês, naquele ponto de recebimento).
[2] Relatório por ano (dado o ano e o ponto de recebimento, mostre o número de pacotes recebidos
no referido ano, naquele ponto de recebimento).
[3] Relatório Média mensal (Mostre, para cada ano, a média de recebimento mensal e uma das
mensagens: “Média acima de 500 pacotes”, “Média abaixo de 90 pacotes ou “Média dentro do
esperado”).
[4] Relatório Geral
Mostre a quantidade total recebida no período em cada ponto de recebimento.
Mostre os meses em que não tiveram pacotes recebidos em nenhum dos pontos, ou mostre a
mensagem “Houve recebimento em todos os meses”.
* Obs.: Após cada relatório, perguntar ao usuário se deseja imprimir outro*/

#include <stdio.h>

int main()
{
    int npacotes[12][4][2]; // [mes][ano][ponto]
    int escolhaderelatorio, meszerados = 0;
    int ano, ponto, mes, somameses;
    int continuar = 1;

    printf("Recebendo Dados dos Últimos 4 anos --- \n");

    for (int i = 0; i < 2; i++) {
        printf("\n--- Ponto de Recebimento %d ---\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("  - Ano %d - \n", j + 1);
            for (int k = 0; k < 12; k++) {
                printf("    Mês %d: ", k + 1);
                scanf("%d", &npacotes[k][j][i]);
            }
        }
    }

    while (continuar) {
        printf("\n --- O que você deseja? --- \n");
        printf(" [1] - Relatório por mês\n");
        printf(" [2] - Relatório por ano\n");
        printf(" [3] - Relatório Média mensal\n");
        printf(" [4] - Relatório Geral\n");
        printf(" [5] - Encerrar programa\n");
        printf("R: ");
        scanf("%d", &escolhaderelatorio);

        switch (escolhaderelatorio) {
        case 1:
            printf("\n Qual o ponto que deseja avaliar? (1 ou 2): ");
            scanf("%d", &ponto);
            ponto--;

            printf(" Qual o ano? (1 a 4): ");
            scanf("%d", &ano);
            ano--;

            printf(" Qual o mês? (1 a 12): ");
            scanf("%d", &mes);
            mes--;

            if (ponto >= 0 && ponto < 2 && ano >= 0 && ano < 4 && mes >= 0 && mes < 12) {
                printf("\n--- No Ponto %d, Ano %d e Mês %d foram recebidos %d pacotes ---\n",
                       ponto + 1, ano + 1, mes + 1, npacotes[mes][ano][ponto]);
            } else {
                printf("Valores inválidos.\n");
            }
            break;

        case 2:
            printf("\n Qual o ponto que deseja avaliar? (1 ou 2): ");
            scanf("%d", &ponto);
            ponto--;

            printf(" Qual o ano? (1 a 4): ");
            scanf("%d", &ano);
            ano--;

            somameses = 0;

            if (ponto >= 0 && ponto < 2 && ano >= 0 && ano < 4) {
                for (int i = 0; i < 12; i++) {
                    somameses += npacotes[i][ano][ponto];
                }
                printf("\n--- Total de pacotes no Ano %d, Ponto %d: %d ---\n",
                       ano + 1, ponto + 1, somameses);
            } else {
                printf("Valores inválidos.\n");
            }
            break;

        case 3:
            printf("\n Qual o ano? (1 a 4): ");
            scanf("%d", &ano);
            ano--;

            if (ano >= 0 && ano < 4) {
                somameses = 0;
                for (int j = 0; j < 2; j++) {
                    for (int i = 0; i < 12; i++) {
                        somameses += npacotes[i][ano][j];
                    }
                }

                float media = somameses / 24.0; // 12 meses x 2 pontos
                printf("\n--- Média de recebimentos no Ano %d: %.2f pacotes ---\n", ano + 1, media);

                if (media > 500)
                    printf("Média acima de 500 pacotes.\n");
                else if (media < 90)
                    printf("Média abaixo de 90 pacotes.\n");
                else
                    printf("Média dentro do esperado.\n");

            } else {
                printf("Ano inválido.\n");
            }
            break;

        case 4:
            somameses = 0;
            meszerados = 0;

            for (int j = 0; j < 2; j++) {
                int totalPonto = 0;
                for (int i = 0; i < 4; i++) {
                    for (int k = 0; k < 12; k++) {
                        totalPonto += npacotes[k][i][j];
                        if (npacotes[k][i][j] == 0) {
                            meszerados++;
                        }
                    }
                }
                printf("\n--- Total de pacotes recebidos no Ponto %d: %d ---\n", j + 1, totalPonto);
            }

            if (meszerados > 0) {
                printf("\n--- Meses sem recebimento em algum ponto ---\n");
                for (int j = 0; j < 2; j++) {
                    for (int i = 0; i < 4; i++) {
                        for (int k = 0; k < 12; k++) {
                            if (npacotes[k][i][j] == 0) {
                                printf("Ponto %d - Ano %d - Mês %d\n", j + 1, i + 1, k + 1);
                            }
                        }
                    }
                }
            } else {
                printf("\nHouve recebimento em todos os meses.\n");
            }
            break;

        case 5:
            continuar = 0;
            break;

        default:
            printf("\nValor Inválido, tente novamente!\n");
            break;
        }

        if (continuar) {
            printf("\nDeseja imprimir outro relatório?\n [1] - SIM\n [0] - NÃO\nR: ");
            scanf("%d", &continuar);
        }
    }

    return 0;
}
