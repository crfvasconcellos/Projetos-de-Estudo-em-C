#include "redblack.h"
#include <stdio.h>
#include <stdlib.h>

/*
========================================
CRIAÇÃO DA ÁRVORE
========================================
*/

RBTree *RBTree_create()
{
    RBTree *rbtree = malloc(sizeof(RBTree));

    // nó sentinela NIL
    rbtree->Nil = malloc(sizeof(Node));

    rbtree->Nil->color = Black;
    rbtree->Nil->key = 0;

    rbtree->Nil->f = rbtree->Nil;
    rbtree->Nil->left = rbtree->Nil;
    rbtree->Nil->right = rbtree->Nil;

    // raiz começa apontando para NIL
    rbtree->root = rbtree->Nil;

    return rbtree;
}

/*
========================================
CRIAÇÃO DE NÓ
========================================
*/

Node *Node_create(RBTree *tree, int val)
{
    Node *node = malloc(sizeof(Node));

    node->key = val;

    // novo nó sempre vermelho
    node->color = Red;

    node->left = tree->Nil;
    node->right = tree->Nil;
    node->f = tree->Nil;

    return node;
}

/*
========================================
RETORNA A COR
========================================
*/

int cor(Node *node)
{
    if (node == NULL)
        return Black;

    return node->color;
}

/*
========================================
ROTAÇÃO ESQUERDA

        x                 y
         \               /
          y     ->      x
         /               \
        T                 T
========================================
*/

Node *LeftRotation(RBTree *tree, Node *x)
{
    Node *y = x->right;

    // subárvore esquerda de y vira direita de x
    x->right = y->left;

    if (y->left != tree->Nil)
    {
        y->left->f = x;
    }

    // pai de y vira pai de x
    y->f = x->f;

    // x era raiz
    if (x->f == tree->Nil)
    {
        tree->root = y;
    }

    // x era filho esquerdo
    else if (x == x->f->left)
    {
        x->f->left = y;
    }

    // x era filho direito
    else
    {
        x->f->right = y;
    }

    // x vira filho esquerdo de y
    y->left = x;
    x->f = y;

    return y;
}

/*
========================================
ROTAÇÃO DIREITA

            y              x
           /                \
          x       ->         y
           \                /
            T              T
========================================
*/

Node *RightRotation(RBTree *tree, Node *y)
{
    Node *x = y->left;

    // subárvore direita de x vira esquerda de y
    y->left = x->right;

    if (x->right != tree->Nil)
    {
        x->right->f = y;
    }

    // pai de x vira pai de y
    x->f = y->f;

    // y era raiz
    if (y->f == tree->Nil)
    {
        tree->root = x;
    }

    // y era filho esquerdo
    else if (y == y->f->left)
    {
        y->f->left = x;
    }

    // y era filho direito
    else
    {
        y->f->right = x;
    }

    // y vira filho direito de x
    x->right = y;
    y->f = x;

    return x;
}

/*
========================================
FIX INSERT
========================================
*/

void FixInsert(RBTree *t, Node *z)
{
    while (z->f->color == Red)
    {

        /*
        ========================================
        PAI À ESQUERDA
        ========================================
        */
        if (z->f == z->f->f->left)
        {
            Node *tio = z->f->f->right;

            /*
            CASO 1
            tio vermelho
            */
            if (tio->color == Red)
            {
                z->f->color = Black;
                tio->color = Black;

                z->f->f->color = Red;

                z = z->f->f;
            }

            else
            {

                /*
                CASO 2
                triângulo
                */
                if (z == z->f->right)
                {
                    z = z->f;

                    LeftRotation(t, z);
                }

                /*
                CASO 3
                linha
                */
                z->f->color = Black;

                z->f->f->color = Red;

                RightRotation(t, z->f->f);
            }
        }

        /*
        ========================================
        CASOS ESPELHADOS
        ========================================
        */
        else
        {
            Node *tio = z->f->f->left;

            /*
            CASO 1
            tio vermelho
            */
            if (tio->color == Red)
            {
                z->f->color = Black;
                tio->color = Black;

                z->f->f->color = Red;

                z = z->f->f;
            }

            else
            {

                /*
                CASO 2
                triângulo
                */
                if (z == z->f->left)
                {
                    z = z->f;

                    RightRotation(t, z);
                }

                /*
                CASO 3
                linha
                */
                z->f->color = Black;

                z->f->f->color = Red;

                LeftRotation(t, z->f->f);
            }
        }
    }

    // raiz sempre preta
    t->root->color = Black;
}

/*
========================================
INSERÇÃO
========================================
*/

RBTree *RBTree_insert(RBTree *t, int val)
{
    Node *z = Node_create(t, val);

    Node *x = t->root;
    Node *y = t->Nil;

    /*
    procura posição
    */
    while (x != t->Nil)
    {
        y = x;

        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    /*
    define pai
    */
    z->f = y;

    /*
    árvore vazia
    */
    if (y == t->Nil)
    {
        t->root = z;
    }

    /*
    esquerda
    */
    else if (z->key < y->key)
    {
        y->left = z;
    }

    /*
    direita
    */
    else
    {
        y->right = z;
    }

    /*
    corrige violações
    */
    FixInsert(t, z);

    return t;
}

/*
========================================
IMPRESSÃO INORDER
========================================
*/

void inorder(RBTree *t, Node *r)
{
    if (r != t->Nil)
    {
        inorder(t, r->left);

        printf("%d (%s)\n",
               r->key,
               r->color == Red ? "RED" : "BLACK");

        inorder(t, r->right);
    }
}