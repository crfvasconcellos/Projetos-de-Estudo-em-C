#include "redblack.h"


RBTree * RBTree_create(){

    RBTree * rbtree = malloc(sizeof(RBTree));

    rbtree->Nil = malloc(sizeof(Node));
    rbtree->root = rbtree->Nil;


    rbtree->Nil->color = Black;
    rbtree->Nil->key = 0;
    rbtree->Nil->f = rbtree->Nil;
    rbtree->Nil->left= rbtree->Nil;
    rbtree->Nil->right = rbtree->Nil;

    return rbtree;


}



Node * Node_create(RBTree * tree,int val){
    
    Node * node = malloc(sizeof(Node));
    
    node->key = val;
    
    node->color = Red;

    node->left = tree->Nil;
    node->right = tree->Nil;
    node->f = tree->Nil;

    return node;

}

Node * LeftRotation(RBTree * tree ,Node * r){
    Node * y = r->right;
    r->right = y->left;

    if (y->left != tree->Nil)
    {
        y->left->f = r;
    }
    
    y->left = r;

    if (r->f == tree->Nil)
    {
        tree->root = y;
    }
    
    y->f = r->f;
    r->f = y;


    return y;

}

Node * RightRotation(RBTree * tree ,Node * r){
    Node * y = r->left;
    r->left = y->right;
    
    if (y->right != tree->Nil)
    {
        y->right->f = r;
    }
    
    y->right = r;

    if (r->f == tree->Nil)
    {
        tree->root = y; 
    }
    

    y->f = r->f;
    r->f = y;
    
    return y;

}

RBTree * RBTree_insert(RBTree * t, int val){

    Node * z = Node_create(t,val);

    Node * x = t->root; //Será o local em que Z vai estar
    Node * y = t->Nil;    // Será o pai de z

    while (x != t->Nil)
    {
        y = x;

        if (z->key < x->key)
        {
            x = x->left;
        }
        else{
            x = x->right;
        }

        z->f = y;

        if (y == t->Nil)
        {
            t->root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else{
            y->right = z;
        }

        //Colocar Fix insert


        return t;



    }
    


}


void FixInsert(RBTree * t, Node * node){
    
}


