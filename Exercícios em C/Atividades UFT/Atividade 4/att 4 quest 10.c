/*
10) Considere um escritório de arquitetura. O preço cobrado por um projeto arquitetônico básico é de R$ 20,00 por m2 . Se o cliente quiser acrescentar os projetos complementares, o preço será de R$ 30,00 por m2 . O cliente pode ainda acrescentar o projeto de decoração e/ou o projeto estrutural. Pelo projeto de decoração é cobrado R$ 100,00 por cômodo e pelo projeto estrutural é cobrado R$ 1200,00. Se o cadastro do cliente tiver sido feito pela internet, o valor total receberá um desconto de 5%. Elabore um algoritmo que mostre o valor a ser pago.
*/

#include <stdio.h>

int main() {

    int tipo,m,deco,val,est,net;

    printf("Quais são os m2 do seu projeto? ");
    scanf("%d",&m);

    printf("Qual Tipo de Projeto Você quer? \n [1] Projeto Básico \n [2] Projeto Complementar?\n");
    scanf("%d",&tipo);

    if (tipo==1)
    {
        val= m*20;
    }
    else if (tipo==2)
    {
        val= m*30;
    }
    
    else{
        printf("Valor inválido!");
        return 0; 
    }

    printf("Deseja adicionar o serviço de decoração? \n [1] SIM \n [2] NÃO \n");
    scanf("%d",&deco);


    if (deco==1)
    {
        int comodos;
        printf("Quantos cômodos deseja decorar? \n");
        scanf("%d",&comodos);
        val=val+comodos*100;
    }

    printf("Deseja um projeto estruturado? \n [1] SIM \n [2] NÃO \n");
    scanf("%d",&est);

    if(est==1){
        val=val+1200;
    }

    printf("Deseja realizar um cadastro pela internet? \n [1] SIM \n [2] NÃO \n");
    scanf("%d",&net);

    if (net==1)
    {
        printf("Você Recebeu um desconto de 5%%! \n");
        val= val-val*0.95;
    }
    

    printf("O valor total do seu projeto é %d",val);
    
}