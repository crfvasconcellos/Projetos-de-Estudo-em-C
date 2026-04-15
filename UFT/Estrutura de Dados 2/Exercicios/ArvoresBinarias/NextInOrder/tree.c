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

void printTree_inOrder(Node * root){

    if (root == NULL)
        return;

    printTree_inOrder(root->left);
    printf(" %d,",root->key);
    printTree_inOrder(root->right);
}

Node* SucessorInOrder(Node* root, Node* target, Node* sucessor) {
    // 1. Proteção básica: se a raiz é nula ou o alvo é nulo
    if (root == NULL || target == NULL) {
        return sucessor;
    }

    if (target->key < root->key) {
        // Se o alvo é menor, o 'root' atual é um candidato a sucessor
        // (ele está à direita do alvo no percurso in-order)
        return SucessorInOrder(root->left, target, root);
    }
    else if (target->key > root->key) {
        // Se o alvo é maior, o sucessor continua sendo o que veio de cima
        return SucessorInOrder(root->right, target, sucessor);
    }
    else {
        // 2. Achamos o nó alvo!
        // Se ele tem subárvore direita, o sucessor é o valor mais à esquerda dela
        if (root->right != NULL) {
            Node* temp = root->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            return temp;
        }
        // Se não tem subárvore direita, o sucessor é o ancestral que guardamos
        return sucessor;
    }
}