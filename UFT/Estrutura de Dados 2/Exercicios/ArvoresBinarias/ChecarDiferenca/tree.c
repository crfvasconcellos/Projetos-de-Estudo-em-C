    #include "tree.h"


    Node * Node_create(int val){
        Node * node = malloc(sizeof(Node));
        node->key = val;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    Tree * Tree_create(){
        Tree * tree = malloc(sizeof(Tree));
        tree->root = NULL;
        return tree;
    }

    Node * readATree(char tree[], int *i){
        
        if (tree[*i] == '(' && tree[*i+1] == ')')
        {
            *i = *i + 2;
            return NULL;
        }

        if (tree[*i] != '(') return NULL;

        (*i)++;

        int val = 0;
        while (tree[*i] >= '0' && tree[*i]<= '9')
        {
            val = val * 10 + (tree[*i] - '0');
            (*i)++;
        }

        Node * node = Node_create(val);

        if (tree[*i] == '(')
            node->left = readATree(tree, i);

        if (tree[*i] == '(')
            node->right = readATree(tree, i);

        (*i)++;
        
        return node;
        

    }


    bool verificaIdenticos(Node * root1, Node* root2){

        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }

        if (root1 == NULL || root2 == NULL)
        {
            return false;
        }

        if (root1->key != root2->key)
        {
            return false;
        }
        

        return verificaIdenticos(root1->left,root2->left) && verificaIdenticos(root1->right,root2->right);


    }


    int kmenor(Node * root,int k, int *contador){

        if (root == NULL)
        {
            return -1;
        }
        
        int val = kmenor(root->left,k,contador);

        if (*contador >= k)
        {
            return val;
        }
        
        (*contador)++;

        if (*contador == k)
        {
            return root->key;
        }
        
        return kmenor(root->right,k,contador);



    }
