#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


int main(){


    printf("\nNúmero 1: ");
    int num1, num2;
    scanf("%d",&num1);
    printf("\nNúmero 2: ");
    scanf("%d",&num2);
    
    DoublyLinkedList * BigNumber;
    BigNumber = DoublyLinkedList_BigSum(num1,num2);
    
    if (BigNumber == NULL) {
        
        printf("Erro: A soma retornou um ponteiro nulo");
        
    }
    
    
    
    


}