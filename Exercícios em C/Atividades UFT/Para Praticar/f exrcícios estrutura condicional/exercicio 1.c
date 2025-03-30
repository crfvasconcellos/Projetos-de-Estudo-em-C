#include <stdio.h> 

int main() {
    float n1,n2,n3,n4;
    float med;
    printf("Digite 4 notas: \n");
    scanf("%f %f %f %f",&n1,&n2,&n3,&n4);

    med= (n1+n2+n3+n4)/4;

    printf("SUa média foi %.2f \n",med);

    if (med>=7){
        printf("Parabéns!! Você foi aprovado!!");
    }

    else{
        printf("Infelizmente, você reprovou!!");
    }
    return 0;
}