#include "tree.h"



Node * Node_create(int val){
    Node * root = malloc(sizeof(Node));
    root->key =val;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;

    return root;
}

int heightNode(Node * node){
    if (node == NULL)
    {
        return 0;
    }

    return node->height;

    
}

int maxNode(int node1, int node2){
    return (node1 > node2) ? node1 : node2;
}


Node * rotationLeft (Node * x){
    Node * y = x->right;
    Node * b = y->left;

    y->left = x;
    x->right = b;

    x->height = maxNode(heightNode(x->left),heightNode(x->right)) + 1;
    y->height = maxNode(heightNode(y->left), heightNode(y->right)) + 1;

    return y;

}

Node * rotationRight(Node * y){
    Node * x = y->left;
    Node * b = x->right;

    x->right = y;

    y->left = b;

    y->height = maxNode(heightNode(y->left), heightNode(y->right)) + 1;
    x->height = maxNode(heightNode(x->left),heightNode(x->right)) + 1;

    return x;


}

int getBalance(Node * node){

    if (node == NULL)
    {
        return NULL;
    }
    
    return heightNode(node->left) - heightNode(node->right);


}


Node * Tree_Insert(Node* root, int val){

    if (root == NULL)
    {
        return Node_create(val);
    }
    
    if (val < root->key)
    {
        root->left = Tree_Insert(root->left,val);
    }
    else if (val > root->key)
    {
        root->right = Tree_Insert(root->right,val);
    }
    else{
        return root;
    }

    root->height = 1 + maxNode(heightNode(root->left),heightNode(root->right));

    int balance = getBalance(root);

    // Casos de Rotação

    //LL
    

    if (balance > 1 && val < root->left->key)
    {
        return rotationRight(root);
    }
    
    //RR

    if (balance < -1 && val > root->right->key)
    {
        return rotationLeft(root);
    }

    //LR

    if (balance > 1 && val > root->left->key)
    {
        root->left = rotationLeft(root->left);
        return rotationRight(root);
    }
    
    //RL

    if (balance < -1 && val < root->right->key)
    {
        root->right = rotationRight(root->right);
        return rotationLeft(root);
    }
    
    return root;        


}