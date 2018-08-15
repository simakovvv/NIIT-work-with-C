
#pragma once

#include"Struct.h"
struct Node
{
	char word;
	int count;
	Node* left;
	Node* right;
};

Node* add(Node* root, int a, char b);
void in(Node *root);
void pre(Node *root);
void post(Node *root);
void print(Node* root, int level);
Node* del(Node* root, int a);
Node* delNode(Node* elem);
void replace(Node** elem, int* a);

Node *parseMassToTree(Node* root, Elem *massStruct);
void convertToMassTree(Node *massTree, Elem *mass);