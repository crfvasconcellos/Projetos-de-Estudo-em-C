#include <stdio.h>

int main(){

    int v[5] = {1,2,3,4,5};

    for (int i = 0; i < 7; i++)
    {
        printf("\n&V[%d] = %d | V[%d] = %d \n\n",i,&v[i],i,v[i]);
    }
    






}