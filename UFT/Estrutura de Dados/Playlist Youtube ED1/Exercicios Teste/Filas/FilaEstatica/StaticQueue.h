#ifndef STATICQUEUE_h
#define STATICQUEUE_h


typedef struct _staticqueue StaticQueue;


StaticQueue * StaticQueue_create();


void StaticQueue_destroy(StaticQueue** q);
void StaticQueue_print(StaticQueue* q);

int StaticQueue_enqueue(StaticQueue* q, int val);
int StaticQueue_dequeue(StaticQueue* q);


#endif