#include "tree.h"



Node * Node_create(int val){

    Node * node = malloc(sizeof(Node));

    node->key = val;
    node->left = NULL;
    node->right = NULL;

    return node;

}



Node * readATree(char trees[],int * cont){
    
    if (trees[*cont] == '(' && trees[*cont + 1] == ')')
    {
        *cont = *cont + 2;
        return NULL;
    }

    if (trees[*cont] != '(')
    {
        return NULL;
    }
    
    (*cont)++;

    int val = 0;
    
    while (trees[*cont] >= '0' && trees[*cont] <= '9')
    {
        val = val*10 + (trees[*cont] - '0');
        (*cont)++;
    }
    
    Node * root = Node_create(val);


    if (trees[*cont] == '(')
    { 
        root->left = readATree(trees,cont);
    }
    
    if (trees[*cont] == '(')
    {
        root->right = readATree(trees,cont);
    }
    
    (*cont)++;

    return root;


    
}

int IsBalanced(Node * root){

    if (root == NULL)
    {
        return 0;
    }
    
    int left = IsBalanced(root->left);
    int right = IsBalanced(root->right);
    
    if (left == -1 || right == -1)
    {
        return -1;
    }
    

    if (abs(left - right) > 1)
    {
        return -1;
    }

    return 1 + (left > right ? left : right);
    


}