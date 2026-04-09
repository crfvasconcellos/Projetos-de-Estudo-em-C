#include "tree.h"

typedef struct _node
{
    int key;
    struct _node* left;
    struct _node* right;

}Node;

typedef struct _tree
{
    Node* root;
}Tree;

Node * Node_create(int val){
    Node * node = malloc(sizeof(Node));
    node->key = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


Tree * readATree(char tree[], int *i){
    
    if (tree[*i] == '(' && tree[*i+1] == ')')
    {
        return NULL;
    }

    (*i)++;

    int val = 0;
    while (tree[*i] >= '0' && tree[*i]<= '9')
    {
        val = val * 10 + (tree[*i] - '0');
        (*i)++;
    }

    Node * node = Node_create(val);

    node->left = readATree(tree,i);
    node->right = readATree(tree,i);

    (*i)++;
    
    return node;
    

}


