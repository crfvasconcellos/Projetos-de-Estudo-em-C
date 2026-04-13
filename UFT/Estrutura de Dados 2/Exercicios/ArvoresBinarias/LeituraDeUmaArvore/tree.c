#include "tree.h"

Node * Node_create(int val){
    Node * node = malloc(sizeof(Node));
    node->key = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node * read_ATree(char tree[],int *i){

    if (tree[*i] == '(' && tree[*i + 1] == ')')
    {
        *i = *i + 2;
        return NULL;
    }
    
    if (tree[*i] != '(')
    {
        return NULL;
    }
    
    (*i)++;

    int val = 0;

    while (tree[*i] >= '0' && tree[*i] <= '9')
    {
        val = val * 10 + (tree[*i] - '0');
        (*i)++;
    }
    
    Node * node = Node_create(val);


    if (tree[*i] == '(')
    {
        node->left = read_ATree(tree,i);
    }
    if (tree[*i] == '(')
    {
        node->right = read_ATree(tree,i);
    }
    
    (*i)++;

    return node;

}


void printTree_preOrder(Node * root){

    printf(" %d,",root->key);

    if (root->left != NULL)
    {
        printTree_preOrder(root->left);
    }
    
    if (root->right != NULL)
    {
        printTree_preOrder(root->right);
    }
    


}

void printTree_inOrder(Node * root){

    printTree_inOrder(root->left);
    printf(" %d,",root->key);
    printTree_inOrder(root->right);
    

}
