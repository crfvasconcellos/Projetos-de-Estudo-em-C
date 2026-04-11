#include "tree.h"
#include <limits.h>


int main(){

    printf("\nDIGITE A ÁRVORE: ");
    char arvore[4096];
    scanf("%s",arvore);
    
    Tree * tree = Tree_create();
    int inteiro = 0;
    tree->root = readATree(arvore,&inteiro);

    bool is = IsBst(tree->root,INT_MIN,INT_MAX);

    if (is == true)
    {
        printf("Bst");
    }
    else{
        printf("notBSt");
    }
    

}