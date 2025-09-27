#include "racional.h"




struct _racional
{
    int numerador;
    int denominador;

};


Racional * createRacional(int numer,int denomin){
    Racional * r = (Racional*) malloc(sizeof(Racional));

    if (r != NULL)
    {
        r->numerador = numer;
        r->denominador= denomin;
    }

    return r;
    
}


void destruirRacional(Racional * num){
    free(num);
}

Racional * somaRacional(const Racional* num1, const Racional* num2){
    int num = num1->numerador * num2->denominador + num1->denominador * num2->numerador;
    int denomi = num1->denominador * num2->denominador;

    return createRacional(num,denomi);
}


Racional * multiplicaRacional (const Racional * num1, const Racional * num2){
    int num = num1->numerador * num2->numerador;
    int denomi = num1->denominador * num2->denominador;

    return createRacional(num,denomi);
}


bool testaIgualRacio(const Racional * num1, const Racional * num2){
    if (num1->numerador == num2->numerador && num1->denominador == num2->denominador)
    {
        return true;
    }
    else{
        return false;
    }

}

 void imprimirRacional(const Racional* r) {
    if (r != NULL) {
        printf("%d/%d\n", r->numerador, r->denominador);
    }
    }   