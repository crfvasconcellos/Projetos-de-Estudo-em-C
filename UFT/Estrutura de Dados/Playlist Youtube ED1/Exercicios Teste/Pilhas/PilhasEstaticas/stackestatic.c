#include "stackestatic.h"


typedef struct _stackstatic{

    int top;
    long capacity;
    long *data;



} StaticStack;

StaticStack * StaticStack_create(int capacity){

    StaticStack * s = (StaticStack*) calloc(1,sizeof(StaticStack));
    
    s->capacity = capacity;
    s->top = -1;
    s->data = (int*) calloc(capacity,sizeof(int));

    
    return s;

}

void StaticStack_destroy(StaticStack ** s){

    StaticStack * s1 = *s;

    free(s1->data);
    free(s1);
    *s = NULL;



}

bool StaticStack_is_empety(StaticStack * s){

    if (s->top == -1)
    {
        return true;
    }
    else{
        return false;
    }

}

bool StaticStack_is_full(StaticStack* s){
    if ((s->top + 1) == s->capacity )
    {
        return true;
    }
    else{
        return false;
    }
}


void StaticStack_push(StaticStack * s,int val){

    if (! StaticStack_is_full(s))
    {
        s->data[s->top+1] = val;
        s->top++;
        
    }
    else{

        printf("\nA pilha está cheia!");

    }
    


}

int StaticStack_peek(StaticStack * s){
    if (!StaticStack_is_empety(s))
    {
        return s->data[s->top];
    }
    else{
        printf("\nA lista esta vazia");
    }
    

}
int StaticStack_pop(StaticStack * s){

    if (! StaticStack_is_empety(s))
    {
        int val = s->data[s->top];
        s->top--;
        return val;

    }
    else{

        printf("\nA lista esta vazia");
    }
        


}

void StaticStack_print(const StaticStack * s){

    printf("\nCapacity = %d",s->capacity);
    printf("\ntop = %d",s->top);

    printf("\nStack = ");

    for (int i = 0; i <= s->top; i++)
    {
        printf("%d",s->data[i]);
        if (i != s->top)
        {
            printf(" -> ");
        }
        
    }
    
    printf(" <-Top\n\n\n");

}