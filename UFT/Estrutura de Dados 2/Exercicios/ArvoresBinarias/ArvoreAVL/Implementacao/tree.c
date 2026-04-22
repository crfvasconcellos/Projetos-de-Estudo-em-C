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


int FatorDeBalanceamento(Node * root){
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

Node * rotationRLeft(Node * r){

    r->right = rotationRight(r->right);
    return rotationLeft(r);


}

Node * rotationLRight(Node * r){

    r->left = rotationLeft(r->left);
    return rotationLRight(r);

}

Node * Balancear(Node * root){
    int fb = FatorDeBalanceamento(root);

    if (fb  < -1 && FatorDeBalanceamento(root->right) <= 0)
    {
        return rotationLeft(root);
    }
    
    if (fb > 1 && FatorDeBalanceamento(root->left) >= 0)
    {
        return rotationRight(root);
    }
    
    if (fb > 1 && FatorDeBalanceamento(root->left) < 0)
    {
        return rotationLRight(root);
    }

    if (fb < -1 && FatorDeBalanceamento(root->right) > 0)
    {
        return rotationRLeft(root);
    }
    
    
    return root;
    
}

Node * Tree_Insert(Node * root, int val){
    
    


}