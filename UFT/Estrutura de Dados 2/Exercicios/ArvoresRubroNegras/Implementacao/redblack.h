#ifndef REDBLACK_H
#define REDBLACK_H

#include <stdio.h>
#include <stdlib.h>

#define Red 1
#define Black 0


typedef struct _node{
    struct _node * left;
    struct _node * right;
    struct _node * f;

    int key;
    int color;
}Node;


typedef struct _rdbtree
{
    Node * root;
    Node * Nil;
}RBTree;

RBTree * RBTree_create();


RBTree * RBTree_insert(RBTree * t, int val);






#endif