#include "mediana.h"

Node * Node_create(int val){
    Node * node = malloc(sizeof(Node));
    node->key = val;
    node->high = 0;
    node->left = NULL;
    node->right = NULL;

    return node;

}



Node * Build_median(int numbers[],int start, int end){
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2 ;

    Node * root = Node_create(numbers[mid]);
    root->left = Build_median(numbers,start,mid - 1);
    root->right = Build_median(numbers,mid + 1, end);

    return root;

    
}

int Node_high(Node * node){
    if (node == NULL)
    {
        return -1;
    }
    
    return node->high;

}

int Node_FB(Node * root){

    if (root == NULL)
    {
        return 0;
    }
    
    return (Node_high(root->left) - Node_high(root->right));

}

int max(int a, int b){

    return (a > b ? a : b);

}

Node * rotationLeft(Node * r){
    Node * y = r->right;
    Node * f = y->left;

    y->left = r;
    r->right = f;

    r->high = max(Node_high(r->left),Node_high(r->right)) + 1;
    y->high = max(Node_high(y->left),Node_high(y->right)) + 1;

    return y;

}

Node * rotationRight(Node * r){
    Node * y = r->left;
    Node * f = y->right;

    y->right = r;
    r->left = f;

    r->high = max(Node_high(r->left),Node_high(r->right)) + 1;
    y->high = max(Node_high(y->left),Node_high(y->right)) + 1;

    return y;

}

Node * Root_Balanceamento(Node * root){
    
    int fb = Node_FB(root);

    if (fb > 1 && Node_FB(root->left) >= 0)
    {
        return rotationRight(root);
    }
    
    if (fb < -1 && Node_FB(root->right) <= 0)
    {
        return rotationLeft(root);
    }
    
    if (fb > 1 && Node_FB(root->left) < 0)
    {
        root->left = rotationLeft(root->left);
        return rotationRight(root);
    }
    
    if (fb < -1 && Node_FB(root->right) > 0)
    {
        root->right = rotationRight(root->right);
        return rotationLeft(root);
    }
    
    return root;

}


Node * Avl_Insert(Node * root, int val){

    if (root == NULL)
    {
        return Node_create(val);
    }

    if (val < root->key)
    {
        root->left = Avl_Insert(root->left,val);
    }
    else{
        root->right = Avl_Insert(root->right,val);
    }    
    
    root->high = max(Node_high(root->left),Node_high(root->right)) + 1;
    root = Root_Balanceamento(root);

    return root;


}

Node * Build_AVL(int numbers[],int qtd){

    Node * root = NULL;

    for (int i = 0; i < qtd; i++)
    {
        if (i == 0)
        {
            root = Avl_Insert(NULL,numbers[i]);
        }
        else{
            root =Avl_Insert(root,numbers[i]);
        }


        
    }
    
    return root;


}

int iguais(Node* a, Node* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;

    return (a->key == b->key &&
            iguais(a->left, b->left) &&
            iguais(a->right, b->right));
}

void printTree(Node *root, int space) {
    if (root == NULL)
        return;

    // aumenta o espaço entre níveis
    space += 5;

    // imprime primeiro a direita (vai ficar em cima)
    printTree(root->right, space);

    // imprime o nó atual
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // imprime a esquerda (vai ficar embaixo)
    printTree(root->left, space);
}