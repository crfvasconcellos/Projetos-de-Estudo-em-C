#include "tree.h"



int main(){

    printf("Árvore: ");
    char arvore[4096];
    fgets(arvore,4096,stdin);

    int contador = 0;
    Node * root = read_ATree(arvore,&contador);

    printf("\nINORDER: ");
    printTree_inOrder(root);

    Node* number = root->right;

    Node * suces = SucessorInOrder(root,number,NULL);
    
    if (suces == NULL)
    {
        printf("\n O sucessor de %d é null",number->key);
    }
    else{
        printf("\n O sucessor de %d é %d ",number->key,suces->key);

    }




}