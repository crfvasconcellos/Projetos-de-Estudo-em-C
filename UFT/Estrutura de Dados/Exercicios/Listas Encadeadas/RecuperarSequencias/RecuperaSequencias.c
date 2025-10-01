#include <stdio.h>
#include "RecuperaSequencias.h"
#include<stdlib.h>




typedef struct _tno
{
    int id;
    float val;
    int id_prox;
    struct _tno * next;
}TNo;


struct _listadetriplas
{
    TNo * begin;
    TNo * end;   
};


TNo * Tno_create(int id, float val, int proximoid){
    TNo * no = (TNo*) calloc(1,sizeof(TNo));

    no->id = id;
    no->id_prox = proximoid;
    no->val = val;

    return no;

}


void ListaDeTriplas_destroir(ListaDeTriplas ** L){

    TNo* proc = (*L)->begin;
    TNo* aux = NULL;

    while (proc != NULL)
    {
        aux = proc;
        proc = proc->next;
        free(aux);

    }

    free(*L);
    *L = NULL;

}



ListaDeTriplas * ListaDeTriplas_criar(){
    ListaDeTriplas * L = (ListaDeTriplas*) calloc(1,sizeof(ListaDeTriplas));
    L->begin = NULL;
    L->end = NULL;

    return L;

}

void ListaDeTriplas_inserir(ListaDeTriplas* L, int id, float val, int proximoid){

    TNo * no = Tno_create(id, val, proximoid);

    if (L->begin == NULL)
    {
        L->begin = no;
        L->end = no;
    }

    else
    {
        L->end->next = no;
        L->end= no;
    }
    
    
}

void ListaDeTriplas_organizar(ListaDeTriplas** L){

     if (*L == NULL || (*L)->begin == NULL) {
        return; // nada pra organizar
    }


    ListaDeTriplas * outralista = ListaDeTriplas_criar();
    int idaponta;
    TNo* noatual;
    TNo* noapontado;

    ListaDeTriplas_inserir(outralista,(*L)->begin->id,(*L)->begin->val,(*L)->begin->id_prox);

    

    idaponta = (*L)->begin->id_prox;

    noatual = (*L)->begin->next;
    noapontado = (*L)->begin;

    while (idaponta != 0)
    {
        noatual = (*L)->begin->next;
        noapontado = (*L)->begin;

        while (1)
        {
            if (noatual->id == idaponta)
            {
                ListaDeTriplas_inserir(outralista, noatual->id,noatual->val,noatual->id_prox);
                idaponta = outralista->end->id_prox;
                break;
            }
            else if (idaponta == 0 || noatual == NULL)
            {
                break;
            }
            
           
            
            
            
            noatual = noatual->next;
            noapontado = noapontado->next;

        }

        


    }
    
    ListaDeTriplas_destroir(L);

    *L = outralista;

}



void ListaDeTriplas_print(ListaDeTriplas * L ){

    TNo * proc = L->begin;
    printf("\n");

    while (proc != NULL)
    {
        printf("%.1f,",proc->val);
        proc = proc->next;
    }
    
    printf("\n");

}

void ListaDeTriplas_recebetriplas(ListaDeTriplas** L){

    TNo resposta;

    while (1)
    {
        scanf("%d",&resposta.id);
        scanf("%f",&resposta.val );
        scanf("%d",&resposta.id_prox);

        if (resposta.id == 0 && resposta.id_prox == 0 && resposta.val == 0)
        {
            break;
        }

        ListaDeTriplas_inserir(*L,resposta.id,resposta.val,resposta.id_prox);

        
        

    }


    ListaDeTriplas_organizar(L);

    ListaDeTriplas_print(*L);

}

