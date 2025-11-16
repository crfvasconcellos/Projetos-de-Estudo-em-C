#ifndef CIRCLIST_H
#define CIRCLIST_H

#include <stdbool.h>


typedef struct _cnode CNode;
typedef struct _circlist CircList;

CNode * CNode_create(int );

CircList * CircList_create();


void CircList_addFirst(CircList * L, int val);
void CircList_destroy(CircList** L);
void CircList_printf(CircList* L);
void CircList_invertedprintf(CircList* L);


bool CircList_isempty(CircList* L);

#endif