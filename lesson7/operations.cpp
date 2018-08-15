#include "operations.h"

int summ(Node *phead) {
	
	Node *p = phead;
	int summ = 0;
	while (p) {
		summ += p->value;
		p = p->pnext;
	}
	return summ;
}

int maxElem(Node *phead)
{
	
	Node *p = phead;
	int max = p->value;
	while (p) {
		if (p->value > max)
			max = p->value;
		p = p->pnext;
	}
	return max;
}

int summMinMax(Node *phead)
{
	
	Node *p = phead;
	int min = p->value;
	int max = 0;
	while (p) {
		if (p->value > max)
			max = p->value;
		if (p->value < min)
			min = p->value;

		p = p->pnext;
	}
	return max+min;
}

bool hasSort(Node * phead)
{
	bool flag = 0;
	Node *p = phead;
	while (p->pnext) {
		if (p->value > p->pnext->value)
			flag = 1;
		p = p->pnext;
	}
	return flag;
}
