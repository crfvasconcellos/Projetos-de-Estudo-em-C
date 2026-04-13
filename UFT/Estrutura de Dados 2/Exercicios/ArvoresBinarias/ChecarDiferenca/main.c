#include "tree.h"


int main(){

    Tree *tree1 = Tree_create();
    
    
    printf("Ávore 1: ");
    char arvore1[4096];
    fgets(arvore1, 4096, stdin);
    printf("K: ");
    int k;
    scanf("%d",&k);

    int i1 =0;
    tree1->root = readATree(arvore1,&i1);
    
    int c = 0;

    int kesimo = kmenor(tree1->root,k,&c);
    
    printf("\n%d é o Kesimo ",kesimo);



}