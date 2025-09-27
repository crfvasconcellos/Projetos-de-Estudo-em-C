#include "Numcplex.h"
#include <stdio.h>
#include <stdlib.h>


struct _complexo
{
    float x; // parte Real
    float y; // parte imaginária
};



Complexo * criarComplexo(float num1, float num2){
    Complexo *c = (Complexo*) malloc(sizeof(Complexo));
    
    if (c!= NULL)
    {
        c->x= num1;
        c->y=num2;
        printf("\n Valores %.2f %.2f passados \n",c->x,c->y);
    }

    return c;
    
}


void destroi(Complexo*c){
    Complexo * a = c;
    free(a);
    c = NULL;
}


Complexo * somaComplexos(Complexo* num1, Complexo* num2){
    if (num1 ==NULL || num2 == NULL) 
    {
        return NULL;
    }

    return criarComplexo(num1->x+num2->x,num2->y+num1->y);
    
}

Complexo * subtraiComplexos(Complexo* num1, Complexo* num2){
    if (num1 ==NULL || num2 == NULL) 
    {
        return NULL;
    }

    return criarComplexo(num1->x-num2->x,num2->y-num1->y);
    
}


void imprimirComplexo(const Complexo* c) {
    if (c != NULL) {
        printf("%.2f + %.2fi\n", c->x, c->y);
    }
}