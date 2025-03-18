#include <stdio.h>

int main(){
    int x;
    double valor;
    scanf("%d %lf",&x,&valor);
    if  ( x < 13) {
        valor= valor + 5;
        printf("Valor: %.2lf \n",valor);
    } else {
        printf("Valor: %d \n",x);
    
        if (x > 15){
            valor= valor - 5;   
            printf("Valor: %.2lf \n", valor);
        }else {
            printf("Valor: %d \n ",x);
        }
        return 0; }
}