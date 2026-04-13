#include "tree.h"


int main(){

    Tree *tree1 = Tree_create();
    Tree *tree2 = Tree_create();
    
    printf("Digite duas arvores \n");
    printf("Ávore 1: ");
    char arvore1[4096];
    fgets(arvore1, 4096, stdin);
    printf("Ávore 2: ");
    char arvore2[4096];
    fgets(arvore2, 4096, stdin);

    int i1 =0;
    int i2 = 0;
    tree1->root = readATree(arvore1,&i1);
    tree2->root = readATree(arvore2,&i2);

    bool mesmo = verificaIdenticos(tree1->root,tree2->root);

    if (mesmo == true)
    {
        printf("Verdadeiro");
    }
    
    if (mesmo == false)
    {
        printf("Falso");
    }
    



}