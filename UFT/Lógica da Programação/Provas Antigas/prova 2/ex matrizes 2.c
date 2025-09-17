/*Ler as notas finais de 3 turmas de no máximo 30 alunos (não perguntar o número de alunos).
Disponibilizar as seguintes relatórios:
- Nota individual: Dados número do aluno e número da turma, mostre a nota.
- Média da turma: Dado número da turma, mostre a média de notas da turma.
- Alunos acima da média: Dado número da turma, mostre quais alunos tiveram nota maior
que a média de sua turma.
- Maior média: Mostre a turma com maior média*/

#include <stdio.h>

int main() {
    int notas[30][3], contadorloop[3];
    
    // Leitura das notas
    for (int i = 0; i < 3; i++) {
        contadorloop[i] = 0;
        printf("--- Turma %d ---\n", i + 1);
        while (1) {
            if (contadorloop[i] == 30) {
                printf("\nNúmero de alunos por turma chegou ao limite!\n");
                break;
            }

            printf("Nota do %dº aluno [-1 para parar]: ", contadorloop[i] + 1);
            scanf("%d", &notas[contadorloop[i]][i]);

            if (notas[contadorloop[i]][i] == -1) {
                break;
            }

            contadorloop[i]++;
        }
    }

    while (1) {
        int escolha;
        int numaluno, turmaluno;

        printf("\n--- Relatórios ---\n");
        printf("[1] - Nota Individual\n[2] - Média da Turma\n[3] - Alunos Acima da Média\n[4] - Maior Média\nR: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Qual a turma do aluno (1 a 3)? ");
                scanf("%d", &turmaluno);
                printf("Qual o número do aluno (1 a 30)? ");
                scanf("%d", &numaluno);

                if (turmaluno < 1 || turmaluno > 3 || numaluno < 1 || numaluno > contadorloop[turmaluno - 1]) {
                    printf("Dados inválidos.\n");
                } else {
                    printf("A nota do aluno é %d\n", notas[numaluno - 1][turmaluno - 1]);
                }
                break;

            case 2:
                printf("Qual a turma (1 a 3)? ");
                scanf("%d", &turmaluno);
                turmaluno--;

                if (turmaluno < 0 || turmaluno > 2) {
                    printf("Turma inválida.\n");
                    break;
                }

                float soma = 0;
                for (int i = 0; i < contadorloop[turmaluno]; i++) {
                    soma += notas[i][turmaluno];
                }

                float media = soma / contadorloop[turmaluno];
                printf("A média das notas dessa turma foi: %.2f\n", media);
                break;

            case 3:
                printf("Qual a turma (1 a 3)? ");
                scanf("%d", &turmaluno);
                turmaluno--;

                if (turmaluno < 0 || turmaluno > 2) {
                    printf("Turma inválida.\n");
                    break;
                }

                soma = 0;
                for (int i = 0; i < contadorloop[turmaluno]; i++) {
                    soma += notas[i][turmaluno];
                }

                media = soma / contadorloop[turmaluno];

                printf("Alunos com nota acima da média (%.2f):\n", media);
                for (int i = 0; i < contadorloop[turmaluno]; i++) {
                    if (notas[i][turmaluno] > media) {
                        printf("Aluno %d - Nota: %d\n", i + 1, notas[i][turmaluno]);
                    }
                }
                break;

            case 4: {
                int turma_maior = 0;
                float maior_media = 0;

                for (int i = 0; i < 3; i++) {
                    soma = 0;
                    for (int j = 0; j < contadorloop[i]; j++) {
                        soma += notas[j][i];
                    }

                    if (contadorloop[i] > 0) {
                        media = soma / contadorloop[i];
                        if (i == 0 || media > maior_media) {
                            maior_media = media;
                            turma_maior = i;
                        }
                    }
                }

                printf("A turma com maior média foi a turma %d com média %.2f\n", turma_maior + 1, maior_media);
                break;
            }

            default:
                printf("Opção inválida.\n");
        }

        int resposta;
        printf("\nDeseja imprimir outro relatório? [1] - Sim | [2] - Não\nR: ");
        scanf("%d", &resposta);

        if (resposta != 1) {
            break;
        }
    }

    return 0;
}
