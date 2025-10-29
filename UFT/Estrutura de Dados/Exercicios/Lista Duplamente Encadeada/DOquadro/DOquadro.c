#include "DOquadro.h"
#include <stdlib.h> 
#include <stdio.h>  

TNo* TNo_createFill(int val) {
    TNo* novo = (TNo*) malloc(sizeof(TNo));
    if (novo != NULL) {
        novo->info = val;
        novo->ant = NULL;
        novo->prox = NULL;
    }
    return novo;
}

TOList* TOList_create() {
    TOList* lista = (TOList*) malloc(sizeof(TOList));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

bool TOList_ins_inicio(TOList *list, int val) {

    if (list == NULL) {
        return false;
    }

   TNo* new = TNo_createFill(val);
    if (new == NULL) {
        return false; 
    }

    
    if (list->inicio == NULL) {
        list->inicio = new;
        list->fim = new;
    } else {
        
        new->prox = list->inicio;
        list->inicio->ant = new;
        list->inicio = new;
    }

    return true;
}


bool TOList_ins_fim(TOList *list, int val) {

    if (list == NULL) {
        return false;
    }


    TNo* new = TNo_createFill(val);
    if (new == NULL) {
        return false; 
    }

   
    if (list->inicio == NULL) { 
        list->inicio = new;
        list->fim = new;
    } else {
        
        list->fim->prox = new;
        new->ant = list->fim;
        list->fim = new;
    }

    return true;
}