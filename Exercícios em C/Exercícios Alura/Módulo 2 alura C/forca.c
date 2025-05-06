#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void adicionapalavra()
{
    char resposta1=' ';
    printf("\nVocê deseja adicionar uma nova palavra no game? [s/n] \n");
    scanf(" %c",&resposta1);

    if (resposta1== 's' || resposta1=='S')
    {

        char novapalavra[TAMANHO_PALAVRA];
        while (1)
        {
            
        printf("\n QUal a nova palavra? \n");
        scanf(" %s",novapalavra);
        
        char pergunta= ' ';
        printf("\n Deseja adicionar \"%s\" no jogo da forca? [s/n] ",novapalavra);
        scanf(" %c",&pergunta);

            if (pergunta== 's' || pergunta=='S')
            {
                break;
            }
            
        
        }
        

        FILE * f;
        f= fopen("../palavras.txt","r+");

        if (f == NULL)
        {
            printf("\n ERRO AO ABRIR O ARQUIVO, FINALIZANDO PROGRAMA!");
            exit(1);
        }
        

        
        int qtd;

        fscanf(f,"%d",&qtd);
        qtd++;

        fseek(f,0,SEEK_SET);
        fprintf(f,"%d",qtd);
        
        fseek(f,0,SEEK_END);
        fprintf(f,"\n%s",novapalavra);

        fclose(f);

    }
    
}

void escolhepalavra() {

    FILE* f;
    f = fopen("../palavras.txt", "r");
    if (f == NULL) 
    {
    printf("Erro ao abrir o arquivo palavras.txt\n");
    exit(1);
    }
    

    int qtdpal; 
    fscanf(f,"%d",&qtdpal);
    

    srand(time(0));
    int randomico= rand() % qtdpal;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f,"%s",palavrasecreta);
    }


    fclose(f);
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
    chute= toupper(chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca() {

    int chuteserrado= chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n",(chuteserrado>=1 ? '(' : ' '),(chuteserrado>=1 ? '_' : ' '),(chuteserrado>=1 ? ')': ' '));
    printf(" |      %c%c%c  \n",(chuteserrado>=2 ? '\\' : ' ') ,(chuteserrado>=2 ? '|' : ' '),(chuteserrado>=2 ? '/' : ' '));
    printf(" |       %c     \n",(chuteserrado>=3 ? '|' :  ' '));
    printf(" |      %c %c   \n",(chuteserrado>=4 ? '/' : ' ') ,(chuteserrado>=5 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");


    printf("Você já deu %d chutes\n", chutesdados);

    for(size_t i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

int chuteserrados()
{
    int erros=0;

    for (int i = 0; i < chutesdados; i++)
    {
        int existe=0;
        for (size_t j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i]== palavrasecreta[j])
            {
                existe=1;
                break;
            }
                
        }

        if (!existe)
        {
            erros++;
        }
        
    }
    return erros;
}

int contadordefalhas(){

    return chuteserrados()>=5;
    
}

int ganhou(){
    for (size_t i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
           return 0;
        }
    }
    
    return 1;
}

void finalizacao (){
    printf("\n Jogo FInalizado com Sucesso! ");
    
}

void comentario(){
    if (ganhou())
    {
        printf("\n PARABÉNS, VOCê GANHHOU!!!!! \n A palavra secreta era %s \n",palavrasecreta);
    }
    else
    {
        printf("\n Infelizmente você perdeu, a palavra secreta era %s \n",palavrasecreta);
    }
    
}

int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

        

    } while (!ganhou() && !contadordefalhas());

    
    comentario();
    adicionapalavra();
    finalizacao();

}