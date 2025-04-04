/*5) Uma agência bancária possui dois tipos de investimentos, conforme o quadro abaixo. Faça um algoritmo 
que receba o tipo do investimento e o valor do investimento e que calcule e mostre o valor corrigido de acordo com 
o tipo de investimento. Tipo Descrição Rendimento mensal 1 Poupança 4% 2 Renda Fixa 25% Médio*/

#include <stdio.h>

int main() {
    int tipo;
    float val, valdps;
    char descricao[15], porcent[5];

    printf("Qual o seu tipo de investimento? \n [1] Poupança \n [2] Renda Fixa \n");
    scanf("%d", &tipo);
    printf("Qual o valor do investimento? \n ");
    scanf("%f", &val);

    if (tipo == 1) {
        snprintf(porcent, sizeof(porcent), "4%%");
        snprintf(descricao, sizeof(descricao), "Poupança");
        valdps = val * 1.04;  // 4% de rendimento
    } 
    else if (tipo == 2) {
        snprintf(porcent, sizeof(porcent), "25%%");
        snprintf(descricao, sizeof(descricao), "Renda Fixa");
        valdps = val * 1.25;  // 25% de rendimento
    } 
    else {
        printf("Opção inválida!\n");
        return 1; // Encerra o programa com erro
    }

    printf("Você escolheu o investimento em %s, com valor inicial de R$%.2f. Após um mês, com rendimento de %s, o valor será R$%.2f\n",
           descricao, val, porcent, valdps);

    return 0;
}
