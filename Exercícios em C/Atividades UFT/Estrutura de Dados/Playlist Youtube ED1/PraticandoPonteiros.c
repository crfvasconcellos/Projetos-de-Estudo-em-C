#include <stdio.h>

void calcula(int x,int y, int *soma, int * multiplica, int * subtrai){

    *soma= x + y;
    *multiplica= x*y;
    *subtrai= x -y;


}


int main(){

    int x = 4;
    int y = 4;
    int soma,multiplica,subtrai;


    calcula(x,y,&soma,&multiplica,&subtrai);

    printf("\nA soma é %d, a Multiplicação é %d , a Subtração é %d \n\n", soma,multiplica,subtrai);




}