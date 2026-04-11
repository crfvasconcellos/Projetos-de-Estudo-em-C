#include "tree.h"

Node * Node_create(int val){
    Node * node = malloc(sizeof(Node));
    node->key = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree * Tree_create(){
    Tree * tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node * readATree(char tree[], int *i){
    
    if (tree[*i] == '(' && tree[*i+1] == ')')
    {
        *i = *i + 2;
        return NULL;
    }

     if (tree[*i] != '(') return NULL;

    (*i)++;

    int val = 0;
    while (tree[*i] >= '0' && tree[*i]<= '9')
    {
        val = val * 10 + (tree[*i] - '0');
        (*i)++;
    }

    Node * node = Node_create(val);

    if (tree[*i] == '(')
        node->left = readATree(tree, i);

    if (tree[*i] == '(')
        node->right = readATree(tree, i);

    (*i)++;
    
    return node;
    

}

bool IsBst(Node * root, int min, int max){

    if (root == NULL)
    {
        return true;
    }
    
    bool teste = true;

    if (root->key <= min || root->key >= max)
    {
        return false;
    }
    
    return IsBst(root->left, min, root->key) && IsBst(root->right,root->key,max);
    
}

