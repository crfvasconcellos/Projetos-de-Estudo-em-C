#include "mediana.h"

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){

    int num;
    scanf("%d",&num);

    int numbers[num];

    for (int i = 0; i < num; i++)
    {
       scanf("%d",&numbers[i]); 
    }

    // Cria cópia ordenada para a árvore mediana
    int sorted[num];
    for (int i = 0; i < num; i++) sorted[i] = numbers[i];
    qsort(sorted, num, sizeof(int), compare);

    Node * rootmedian = Build_median(sorted, 0, num - 1);
    Node * rootAvl = Build_AVL(numbers, num);

    int ig = iguais(rootmedian, rootAvl);

    printf("%d\n", ig);

    return 0;
}
