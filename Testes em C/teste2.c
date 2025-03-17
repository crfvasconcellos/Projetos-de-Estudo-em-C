#include <stdio.h>

int main() {
    double num1, num2, resultado;
    
    // Solicita ao usuário que insira dois números
    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%lf", &num2);
    
    // Realiza a soma
    resultado = num1 + num2;
    
    // Exibe o resultado
    printf("O resultado da soma é: %.2lf\n", resultado);
    
    return 0;
}   