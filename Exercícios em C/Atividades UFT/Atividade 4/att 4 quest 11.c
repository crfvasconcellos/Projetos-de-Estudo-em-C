/* 11) Calcule o preço a ser pago por uma compra pela internet com as seguintes condições. Dada a soma dos preços dos itens da compra, o frete será 10% deste valor para a região sul e sudeste e 20% para as demais regiões, mas se a compra for feita em dia de promoção, o frete será grátis. Se o cliente for um cliente vip, receberá R$ 100,00 de desconto no valor da compra
*/

#include <stdio.h>

int main() {
    int itens, valt = 0, valuni, reg, frete, vip;

    printf("Quantos itens você comprou?\n");
    scanf("%d", &itens);

    printf("Diga o valor de cada um dos itens!\n");

    for (int i = 1; i <= itens; i++) {
        printf("Valor do Item %d: ", i);
        scanf("%d", &valuni);
        valt += valuni;
    }

    printf("O valor total das suas compras foi: R$%d\n", valt);

    printf("Onde você mora?\n");
    printf("[1] Sul\n[2] Sudeste\n[3] Norte\n[4] Centro-Oeste\n[5] Nordeste\n");
    scanf("%d", &reg);

    if (reg == 1 || reg == 2) {
        frete = valt / 10;
    } else if (reg >= 3 && reg <= 5) {
        frete = valt / 5;
    } else {
        frete = 0; // Caso inválido, evita um valor indefinido.
    }

    printf("O seu frete custará R$%d, que somado à sua compra dará um total de R$%d\n", frete, valt + frete);
    valt += frete;

    printf("Você é um cliente VIP?\n[1] SIM\n[2] NÃO\n");
    scanf("%d", &vip);

    if (vip == 1) {
        printf("Você recebeu um desconto de R$100. Total: R$%d - R$100 = R$%d\n", valt, valt - 100);
        valt -= 100;
    }

    printf("O seu custo total foi: R$%d\n", valt);

    return 0;
}