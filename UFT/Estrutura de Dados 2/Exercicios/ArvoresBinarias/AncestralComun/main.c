
#include "tree.h"



int main(){

    printf("Árvore: ");
    char arvore[4096];
    fgets(arvore,4096,stdin);

    int contador = 0;
    Node * root = read_ATree(arvore,&contador);

    Node * node1 = root->left->right->left;
    Node * node2 = root->left->right->right;

    Node * ancestor = LowestCommonAcestor(root,node1,node2);

    printf("\n O Antecessor em comum de %d e %d é %d ",node1->key,node2->key,ancestor->key);

}