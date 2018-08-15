#pragma once

struct Node {
	int value;
	Node* pnext;
};

void add2listSort(Node **pphead, int val);
void add2list(Node **pphead, int val);
void print(Node *phead);
void deleteList(Node *phead);
