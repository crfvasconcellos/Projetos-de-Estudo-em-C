#ifndef MEDIANA_H
#define MEDIANA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
    double key;
    int high;
    struct _node * left;
    struct _node * right;

}Node;

Node * Node_create(int val);

Node * Build_median(int numbers[],int start, int end);
Node * Build_AVL(int numbers[],int qtd);

int iguais(Node* a, Node* b);

void printTree(Node *root, int space);

#endif