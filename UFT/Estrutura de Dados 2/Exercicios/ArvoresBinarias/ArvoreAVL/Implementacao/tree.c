#include "tree.h"


Node * Node_create(int val){
    Node * node = malloc(sizeof(Node));
    node->high = 0;
    node->left = NULL;
    node->right = NULL;
    node->val = val;

    return node;
}

int maior(int a , int b){

    return ((a>b) ? a : b);

}

int altura(Node * node){
    if (node == NULL)
    {
        return -1;
    }
    
    return node->high;

}


int balanceamento(Node * root){
    if (root == NULL)
    {
        return 0;
    }

    return (altura(root->left) - altura(root->right));
    
}

Node * rotationLeft(Node * r){
    Node * y = r->right;
    Node * f = y->left;

    y->left = r;
    r->right = f;

    r->high = maior(altura(r->left),altura(r->right)) + 1;
    y->high = maior(altura(y->left),altura(y->right)) + 1;

    return y;

}

Node * rotationRight(Node * r){
    Node * y = r->left;
    Node * f = y->right;

    y->right = r;
    r->left = f;

    r->high = maior(altura(r->left),altura(r->right)) + 1;
    y->high = maior(altura(r->left), altura(r->right)) + 1;

    return y;

}