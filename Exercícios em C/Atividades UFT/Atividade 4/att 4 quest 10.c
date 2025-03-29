/*11) Calcule o preço a ser pago por uma compra pela internet com as seguintes condições. 
Dada a soma dos preços dos itens da compra, o frete será 10% deste valor para a região sul e
 sudeste e 20% para as demais regiões, mas se a compra for feita em dia de promoção, o frete será grátis. 
 Se o cliente for um cliente vip, receberá R$ 100,00 de desconto no valor da compra.*/

 #include <stdio.h>

 int main() {
    int itens,valt,valuni,reg,frete,vip;
    valt=0;
    printf("Quantos itens você comprou?\n");
    scanf("%d",&itens);

    printf("Diga o valor de cada um dos itens!!\n");
   

    for(int i=1;i<=itens;i++){

        printf("Valor do Item %d: \n ",i);
        scanf("%d",&valuni);
        valt= valt + valuni;



    }
    printf("O valor total das suas compras foi: R$%d \n",valt);
    printf("Onde você mora? \n [1] Sul \n [2] Sudeste \n [3] Norte \n [4] Centro-Oeste \n [5] Nordeste \n");
    scanf("%d",&reg);

    if (reg==1 || reg==2){
        frete = valt/10;
    }
    else if (reg>2 && reg<6){
        frete = valt/5;
    }
    printf("o seu frete custará R$%d, que somado a sua compra dará um total de R$%d \n", frete, frete + valt);
    valt= valt + frete;

    printf("Você é um cliente vip? \n [1] SIM \n [2] NÃO \n ");
    scanf("%d",&vip);

    if (vip==1)
    {
         printf("Você Recebeu um desconto de R$ 100, R$%d - R$100 = R$%d \n",valt,valt-100);
        valt= valt - 100;
    }

    printf("O seu custo total foi: R$%d",valt);

 }