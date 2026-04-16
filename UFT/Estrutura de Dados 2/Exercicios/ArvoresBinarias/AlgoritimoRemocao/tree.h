#ifndef TREE_H
#define TREE_H


#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int key;
    int height;
    struct _node * left;
    struct _node * right;

}Node;

Node * Node_create(int val);

Node * Tree_Insert(Node* root, int val);

#endif


