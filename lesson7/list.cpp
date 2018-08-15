#include "list.h"
#include <stdlib.h>
#include <stdio.h>


void add2listSort(Node ** pphead, int val)
{
	Node **pp = pphead, *pnew;
	while (*pp)
	{
		if (val < (*pp)->value)
			break;
		else
			pp = &((*pp)->pnext);
	}
	pnew = (Node*)malloc(sizeof(Node));
	pnew->value = val;
	pnew->pnext = *pp;
	*pp = pnew;

}

void add2list(Node ** pphead, int val)
{
	Node **pp = pphead, *pnew;
	while (*pp)
	{
	  pp = &((*pp)->pnext);
	}
	pnew = (Node*)malloc(sizeof(Node));
	pnew->value = val;
	pnew->pnext = *pp;
	*pp = pnew;
}

void print(Node *phead)
{
	Node* p = phead;
	while (p) {
		printf("%d ", p->value);
		p = p->pnext;
	}
	printf("\n");
}

void deleteList(Node * phead)
{
	if (phead)
	{
		deleteList(phead->pnext);
		if (phead)
			free(phead);
	}
}
