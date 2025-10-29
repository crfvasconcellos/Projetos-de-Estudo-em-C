#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h> 
typedef struct no {
    int info;
    struct no *ant;
    struct no *prox;
} TNo;


typedef struct list {
    TNo *inicio;
    TNo *fim;
} TOList;


TNo* TNo_createFill(int val);


TOList* TOList_create();

bool TOList_ins_inicio(TOList *list, int val);

bool TOList_ins_fim(TOList *list, int val);

#endif 