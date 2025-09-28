#include <stdlib.h>
#include "linked_list.h"


typedef struct _snode
{
    int val;
    struct _simple_node * next;
   
}SNode;


typedef struct _linked_list
{
    SNode * begin;
}LinkedList;



