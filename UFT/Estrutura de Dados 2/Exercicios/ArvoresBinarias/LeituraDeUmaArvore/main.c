#include "tree.h"



int main(){

    printf("Árvore: ");
    char arvore[4096];
    fgets(arvore,4096,stdin);

    int contador = 0;
    Node * root = read_ATree(arvore,&contador);

    printf("PREORDER: ");
    printTree_preOrder(root);



}