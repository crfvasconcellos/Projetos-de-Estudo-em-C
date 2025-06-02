/* Função retornando um vetor: Cálculo das raízes

Escreva uma função em linguagem C que calcule as raízes de uma equação de 2° grau usando a fórmula de Bhaskara e retorne em um vetor.
Lembre-se:
se a = 0, não é equação do 2° grau.
se ∆ > 0, a equação possui duas raízes reais e distintas.
se ∆ = 0, a equação possui uma raiz.
se ∆ < 0, a equação não possui raízes reais.
*/


#include <stdio.h>
#include <math.h>

int raiz(double a, double b,double c, double*resultado, double*resultado2)
{
    double delta;

     if (a==0)
    {
        
        return 0;
    }

    delta= pow(b,2) - (4*a*c);
    printf("Delta é %.2lf ",delta);

   if (delta==0)
   {
    *resultado= (-1*b) / (2*a);
    *resultado2= 0;

    
    return 1; 
   }

   else if (delta>0)
   {

    *resultado= (-1*b + sqrt(delta)) / (2*a);
    *resultado2= (-1*b - sqrt(delta)) / (2*a);

    return 2;
   }

   else if (delta<0)
   {
    return 3;
   }
   
}



int main()
{
    printf("Me dê os valores de a,b,c de uma equação de 2º grau \n");
    double a,b,c,x1,x2;

    printf("A: ");
    scanf("%lf",&a);
    printf("B: ");
    scanf("%lf",&b);
    printf("C: ");
    scanf("%lf",&c);

    int resultado= raiz(a,b,c,&x1,&x2);

if (resultado== 0)
{
    printf("Não é uma equação de 2º grau \n");
}


else if (resultado== 1)
{
    printf("\n Possui apenas uma raíz");
    printf("\n O valor de X é %.2lf ",x1);

}

else if (resultado== 2)
{
     printf("\n O valor de X1 é %.2lf e de X2 é %.2lf ",x1,x2);
}

else if (resultado== 3)
{
    printf("\n a equação não possui raízes reais");
}


}