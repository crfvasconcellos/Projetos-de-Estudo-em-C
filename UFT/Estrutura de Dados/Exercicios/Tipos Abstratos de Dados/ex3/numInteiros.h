#ifndef NUMINTEIROS_H
#define NUMINTEIROS_H

typedef struct _numInteiros Inteiros;

Inteiros * Inteiros_create();
Inteiros * Inteiros_intersec(Inteiros * in1, Inteiros * in2);
Inteiros * Inteiros_dif(Inteiros * in1, Inteiros * in2);
Inteiros * Inteiros_uni(Inteiros * in1, Inteiros * in2);

int Inteiros_insert(Inteiros * in, int val );
int Inteiros_remove(Inteiros * in, int val );
int Inteiros_maior(Inteiros * in);


void printInteiros(Inteiros *in);

#endif