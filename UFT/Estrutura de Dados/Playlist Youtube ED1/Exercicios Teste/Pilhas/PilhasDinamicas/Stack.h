#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct _stack Stack;
typedef struct _snode SNode;


SNode * SNode_create(int val);
Stack * Stack_create();

void Stack_push(Stack* s, int val);
void Stack_destroy(Stack ** s);

int Stack_pop(Stack * s1);
int Stack_peek(Stack* s);

bool Stack_is_empty(Stack * s); 





#endif