/* 9) Elabore um algoritmo que calcule o preço de um terreno de acordo com as seguintes regras: Se estiver na região Sul, R$150,00 por m2 e se estiver na região Norte, R$ 100,00 por m2 . Caso o terreno tenha mais de 400 m2 , este preço terá 25% de acréscimo. Se for um terreno de esquina, acrescenta-se R$ 600,00 no preço. 
*/

#include <stdio.h>


int main() {
    
    int tamanho, custo;
    int regiao;
    int esquina;
    printf("Em qual regiao você mora?\n [1] Sul \n [2] Norte\n R: \n ");
    scanf("%d",&regiao);
    printf("Qual o tamanho do terreno? (em m2) \n");
    scanf("%d", &tamanho);
    
    if (regiao==1){
        
        custo= tamanho * 150;
        
        printf("Na região sul o terreno valerá R$%d \n", custo);
        
}
    else if (regiao==2) {
        custo= tamanho * 100;
        printf("Na região norte o terreno valerá R$%d \n ",custo);
        
    }
    
    if (tamanho>400){
        custo= custo + (custo/4);
        printf("O terreno terá um acréscimo de 25%% por ser maior de 400 m2, passando a custar R$%d \n ",custo);
    }
    printf("O terreno é de esquina? \n [1] Sim \n [2] Não \n ");
    scanf("%d", &esquina);
    
    if(esquina == 1 ){
        custo = custo + 600;
        printf("Por ser de esquina o terreno obteve mais um acréscimo de R$ 600, passando a custar R$%d \n",custo);
    }
    printf("O custo final foi: %d", custo);
}
