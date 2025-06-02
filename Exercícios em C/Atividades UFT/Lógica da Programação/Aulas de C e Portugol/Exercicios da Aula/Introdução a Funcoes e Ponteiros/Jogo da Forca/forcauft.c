/*1) Escreva um programa que tenha, como variáveis locais, uma string (de no máximo 20 caracteres), um caracter e um vetor de inteiros que será a máscara. A string e o caracter serão lidos do teclado.
Baseando-se na função de busca (que você fez na aula passada), faça uma função que preencha a máscara com 1 nas posições do vetor que a string possua a letra correspondente ao caracter lido. A função deve retornar 0 caso não tenha nenhuma letra da string correspondente ao caracter, e retornar 1 caso contrário.

string:  c a s a
caracter:  a
máscara: 0 1 0 1
Obs.: Usar a função de biblioteca strlen para saber a tamanho da string.*/

#include <stdio.h>
#include <string.h>





int main()
{
    
    
    char palavrasecreta[20]= "CARRO",letra;
    int mascara[strlen(palavrasecreta)];
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        mascara[i]= 0;
    }
    

    while (1)
    {
       printf("\n Digite uma letra: ");
       scanf(" %c", &letra);

        for (size_t i = 0; i < strlen(palavrasecreta); i++)
            {
                
                if (letra == palavrasecreta[i])
                {
                    mascara[i] = 1;
                }
                


            }

        for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        printf("%d",mascara[i]);
    }
    }
    
     




}