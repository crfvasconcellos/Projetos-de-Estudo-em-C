#include "tree.h"


int main(){

    printf("Árvore: ");
    char arvore[4096];
    fgets(arvore,4096,stdin);

    int contador = 0;
    Node * root = readATree(arvore,&contador);

    int bst =IsBalanced(root);
    
    if (bst == -1)
    {
        printf("Falso");
    }
    else{
        printf("\n%d\n",bst);
        printf("Verdadeiro");
    }
    


}