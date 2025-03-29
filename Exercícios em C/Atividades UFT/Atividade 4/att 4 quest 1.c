/*1) Elabore um algoritmo que receba como entrada nome, peso e idade de três pessoas e mostre os três nomes, a média das idades e diga se a média dos pesos ultrapassa 55 kg. */

#include <stdio.h>
int main() {

    int idade[3];
    float peso[3];
    char nome[3] [30];
    int contador;

    for(int c=1;c<=3;c++)
    {

    printf("Digite o primeiro nome%d:  \n", c );
    scanf("%s",nome[c]);
    
    printf("Digite o seu peso, %s: \n ",nome[c]);
    scanf("%f",&peso[c]);
    
    printf("Digite a sua idade: \n");
    scanf("%d",&idade[c]);
}
printf("Os nomes das pessoas são %s, %s e %s \n ", nome[1],nome[2],nome[3]);
double media= (idade[1] + idade[2] + idade[3])/3;
double mediap= (peso[1] + peso[2] + peso[3] )/3;
printf("A média das sua idades é %2.f \n",media);
if ( mediap>55) {
    printf("A média dos pesos é maior que 55\n");
}
else {
    printf("A média dos pesos não é maior que 55\n");
}
}
