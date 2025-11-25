#ifndef STACKESTATIC_h
#define STACKESTATIC_h

#include<stdbool.h>
#include <stdlib.h>
#include<stdio.h>

typedef struct _stackstatic StaticStack;

StaticStack * StaticStack_create(int capacity);


void StaticStack_destroy(StaticStack ** s);
void StaticStack_push(StaticStack * s,int val);
void StaticStack_print(const StaticStack * s);

int StaticStack_pop(StaticStack * s);
int StaticStack_peek(StaticStack * s);

bool StaticStack_is_empety(StaticStack * s);
bool StaticStack_is_full(StaticStack* s);



#endif