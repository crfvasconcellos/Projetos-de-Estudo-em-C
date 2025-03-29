/* 6) Elabore um algoritmo que mostre se os índices de glicemia e de HDL de um paciente estão normais ou não. 
Considere que a glicemia normal está abaixo de 110mg/dl e os limites normais de HDL são, para homens, 
de 30 à 65 mg /dl e para mulheres, de 35 à 80 mg/dl*/

#include <stdio.h>
#include <string.h>

int main() {
    int sexo, glicemia, colesterol;
    char estadog[10], estadoc[10];

    printf("*********** \n Avaliação dos Índices de Glicemia e HDL \n *********** \n");

    printf("Qual é o sexo do paciente? \n [1] Masculino \n [2] Feminino \n ");
    scanf("%d", &sexo);

    // Validação do sexo
    if (sexo != 1 && sexo != 2) {
        printf("Erro: Sexo inválido! Digite 1 para Masculino ou 2 para Feminino.\n");
        return 1;
    }

    printf("Qual é a glicemia do paciente? (mg/dL) \n");
    scanf("%d", &glicemia);

    printf("Quanto está o colesterol HDL do Paciente? (mg/dL) \n");
    scanf("%d", &colesterol);

    // Validação de valores negativos
    if (glicemia < 0 || colesterol < 0) {
        printf("Erro: Os valores de glicemia e colesterol não podem ser negativos.\n");
        return 1;
    }

    // Verificação da glicemia
    if (glicemia < 110) {
        snprintf(estadog, sizeof(estadog), "Normal");
    } else {
        snprintf(estadog, sizeof(estadog), "Alterada");
    }

    // Verificação do colesterol baseado no sexo
    if ((sexo == 1 && colesterol >= 30 && colesterol <= 65) || 
        (sexo == 2 && colesterol >= 35 && colesterol <= 80)) {
        snprintf(estadoc, sizeof(estadoc), "Normal");
    } else {
        snprintf(estadoc, sizeof(estadoc), "Alterado");
    }

    // Exibição dos resultados
    printf("\nResultados do Exame:\n");
    printf("Glicemia: %d mg/dL - Estado: %s\n", glicemia, estadog);
    printf("Colesterol HDL: %d mg/dL - Estado: %s\n", colesterol, estadoc);

    return 0;
}
