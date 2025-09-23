#include <stdio.h>
#include <stdlib.h>

int main(){

    int** m = NULL; //nrows = 2; //ncols = 3

    m = (int**) calloc(2, sizeof(int*));
    
    for (int i = 0; i < 2; i++)
    {
        m[i]= (int*) calloc(3,sizeof(int*));
    }
    
}