#include <stdio.h>
#include "StaticQueue.h"

int main(void){

    /* ============================
       1) CRIAÇÃO DA FILA
       ============================ */
    StaticQueue *q = StaticQueue_create();   // Reserva memória e zera a fila
    if (!q) {
        printf("Erro ao criar fila!\n");
        return 1;
    }

    printf("\n==== ESTADO INICIAL ====\n");
    StaticQueue_print(q);

    /* ============================
       2) ENQUEUE NORMAL
       ============================ */
    printf("\n\n-- Enfileirando: 10, 20, 30 --\n");
    StaticQueue_enqueue(q, 10);
    StaticQueue_enqueue(q, 20);
    StaticQueue_enqueue(q, 30);
    StaticQueue_print(q);

    /* ============================
       3) DEQUEUE (remoção)
       ============================ */
    printf("\n\n-- Desenfileirando 1 elemento --\n");
    StaticQueue_dequeue(q);   // remove o 10 (begin avança)
    StaticQueue_print(q);

    /* ============================
       4) TESTANDO WRAP-AROUND + OVERFLOW
       ============================ */
    printf("\n\n-- Enfileirando: 40, 50, 60 (inclui wrap + overflow) --\n");
    StaticQueue_enqueue(q, 40);
    StaticQueue_enqueue(q, 50);

    // Aqui deve dar cheio → não aceita 60
    if (StaticQueue_enqueue(q, 60) != 0)
        printf("❌ Fila cheia ao tentar enfileirar 60 (overflow detectado)\n");

    StaticQueue_print(q);

    /* ============================
       5) DEQUEUE MÚLTIPLO
       ============================ */
    printf("\n\n-- Desenfileirando 2 elementos --\n");
    StaticQueue_dequeue(q);   // remove 20
    StaticQueue_dequeue(q);   // remove 30
    StaticQueue_print(q);

    /* ============================
       6) REUTILIZAÇÃO DO ESPAÇO (wrap funcionando)
       ============================ */
    printf("\n\n-- Enfileirando: 70, 80 (reutiliza espaço) --\n");
    StaticQueue_enqueue(q, 70);
    StaticQueue_enqueue(q, 80);
    StaticQueue_print(q);

    /* ============================
       7) DESTRUIÇÃO E LIMPEZA
       ============================ */
    printf("\n\n-- Destruindo fila --\n");
    StaticQueue_destroy(&q);

    if (q == NULL) printf("Fila removida da memória com sucesso!\n");

    return 0;
}
