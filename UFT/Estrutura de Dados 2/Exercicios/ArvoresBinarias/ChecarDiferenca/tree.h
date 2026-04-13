#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int key;
    struct _node * left;
    struct _node * right;

}Node;

typedef struct _tree
{
    Node* root;
}Tree;

Tree * Tree_create();
Node * Node_create(int val);

Node * readATree(char tree[],int *i);


bool verificaIdenticos(Node * root1, Node* root2);

int kmenor(Node * root,int k, int *contador);


#endif