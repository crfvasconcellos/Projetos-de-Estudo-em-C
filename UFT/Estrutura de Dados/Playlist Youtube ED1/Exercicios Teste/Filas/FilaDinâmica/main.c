#include <stdio.h>
#include "Queue.h"

int main() {
    Queue *q = Queue_create();

    printf("\n===== TESTE DA FILA =====\n\n");

    printf("Enfileirando: 10, 20, 30\n");
    Queue_enqueue(q, 10);
    Queue_enqueue(q, 20);
    Queue_enqueue(q, 30);
    Queue_print(q);

    printf("\nDesenfileirando: %d\n", Queue_dequeue(q));
    Queue_print(q);

    printf("\nDesenfileirando: %d\n", Queue_dequeue(q));
    Queue_print(q);

    printf("\nEnfileirando: 40, 50\n");
    Queue_enqueue(q, 40);
    Queue_enqueue(q, 50);
    Queue_print(q);

    printf("\nDesenfileirando tudo...\n");
    while (!Queue_is_empty(q))
        printf("Removed: %d\n", Queue_dequeue(q));

    Queue_print(q);

    Queue_destroy(&q);

    printf("\nFila destruída com sucesso!\n");
    return 0;
}
