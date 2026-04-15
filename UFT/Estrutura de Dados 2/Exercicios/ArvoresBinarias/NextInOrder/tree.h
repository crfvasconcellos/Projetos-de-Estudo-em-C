#ifndef TREE_H
#define TREE_H

#include <stdio.h> 
#include <stdlib.h>


typedef struct _node{
    int key;
    struct  _node * left;
    struct  _node * right;
}Node;

Node * Node_create(int val);
Node * read_ATree(char tree[],int *i);

void printTree_inOrder(Node * root);
Node * SucessorInOrder(Node * root,Node * target, Node* sucessor);

#endif