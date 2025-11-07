#ifndef STACK_H
#define STACK_H


typedef struct _node SNode;
typedef struct _stack Stack;

SNode * SNode_create(int val);

Stack * Stack_create();

void Stack_push(Stack * S ,int val);
void Stack_printf(Stack * S);
void Stack_destroy(Stack ** S);


int Stack_pop(Stack * S, int *recebeval);


#endif