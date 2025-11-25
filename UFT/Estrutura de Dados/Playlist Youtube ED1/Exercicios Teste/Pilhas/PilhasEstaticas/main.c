#include "stackestatic.h"


int main(){

    StaticStack * stack = StaticStack_create(30);

    StaticStack_push(stack, 10);
    StaticStack_push(stack, 20);
    
    StaticStack_push(stack,30);
    
    StaticStack_push(stack,40);
    
    StaticStack_print(stack);
    
    
    int valortirado = StaticStack_pop(stack);
    
    printf("\nRetirando o %d",valortirado);
    
    
    StaticStack_push(stack,50);
    StaticStack_push(stack,60);


    StaticStack_print(stack);


}