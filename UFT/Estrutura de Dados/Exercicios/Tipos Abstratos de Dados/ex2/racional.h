#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>


typedef struct _racional Racional;




Racional * createRacional(int numer,int denomin); 
void destruirRacional(Racional * num);
Racional * somaRacional(const Racional * num1, const Racional * num2);
Racional * multiplicaRacional(const Racional * num1, const Racional * num2);
bool testaIgualRacio(const Racional * num1, const Racional * num2);
void imprimirRacional(const Racional* r);