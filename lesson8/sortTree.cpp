#define SIZE 256  //������� ������ �� ������ �����
#include "sortTree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"


Node* add(Node* root, int a, char b)
{
	if (!root)
	{
		static Node *pnew = (Node*)malloc(sizeof(Node));

		pnew->count = a;
		pnew->word = b;
		pnew->left = NULL;
		pnew->right = NULL;
		root = pnew;
		
	}
	else if (root->count < a)
		root->right = add(root->right, a, b);
	else
		root->left = add(root->left, a, b);
	
	return root;
}

void in(Node *root) //��������� ������
{
	if (root)
	{
		in(root->left);
		printf("%d , %c\n", root->count, root->word);
		in(root->right);

	}
}

void pre(Node *root)//����������
{
	if (root)
	{
		printf("%d , %c\n", root->count, root->word);
		pre(root->left);
		pre(root->right);

	}
}

void post(Node *root)//�����������
{
	if (root)
	{
		
		post(root->left);
		post(root->right);
		printf("%d , %c\n", root->count, root->word);

	}
}

void print(Node* root, int level)
{
	if (root->right)
		print(root->right, level + 1);
	for (int i = 0; i<level; i++)
		printf("   ");
	if (root)
		printf("%d -- %c --  %d\n", root->count, root->word, level);
	else
		printf("#\n");
	if (root->left)
		print(root->left, level + 1);
}


Node* del(Node* root, int a) {
	if (!root) {
		printf("No such element!\n");
		return NULL;
	}
	else if (root->count == a) {
		root = delNode(root);
		return root;
	}
	else if (root->count < a) {
		root->right = del(root->right, a);
		return root;
	}
	else {
		root->left = del(root->left, a);
		return root;
	}
}

Node* delNode(Node* elem) {
	if (!elem->left && !elem->right) {
		free(elem);
		return NULL;
	}
	else if ((elem->left && !elem->right) || (!elem->left&&elem->right)) {
		Node *p = elem;
		if (elem->left) {
			elem = elem->left;
			p->left = NULL;
		}
		else {
			elem = elem->right;
			p->right = NULL;
		}
		free(p);
		return elem;
	}
	else {
		int a;
		replace(&(elem->right), &a);
		elem->count = a;
		return elem;
	}
}

void replace(Node** elem, int* a)
{
	if ((*elem)->left)
		replace(&((*elem)->left), a);
	else
	{
		*a = (*elem)->count;
		Node *p = *elem;
		*elem = (*elem)->right;
		p->right = NULL;
		free(p);
	}
}



void convertToMassTree(Node *massTree, Elem *mass) {
	for (int i = 0; i < SIZE; i++) {
		
			massTree[i].count = mass[i].count;
			massTree[i].word = mass[i].word;
			//printf("---%c \n", massTree[i].word);
		
	}
	
}
//  mass -�������� ������� ��������, ��������������� �� �����������
//  root -������ �� ������ ������

// �������� ������
// aa, ab, bb -����� ������ ���� ������� ����� ��� �������
// k -������ ��� ������ �������� �� �������
// i -������ ������ ��������� �������
// f -������ ������� �������
// first - ������� � ������� �� ����� �������������� ����� ��������


Node *parseMassToTree(Node *root, Elem *massStruct) {
	int k, i = 0, f = 1;
	static Node massTree[SIZE] = { 0 };
	static Node *temp[SIZE] = { 0 };
	int first = 0;
	convertToMassTree(massTree, massStruct);

	while (i < (SIZE-1)) {//����� ��������
		int selectParent = 0;// �������� ���� ������ ��������
		int first = 0;

		if (massTree[i].count > 0) {
			int countParent = (massTree[i].count + massTree[i + 1].count);
			
			
			for (k = i; k < SIZE; k++) {// ����� �������� �������� � ���������� ��������������

				if (countParent == massTree[k].count) {
					root = &massTree[k];
					if (massTree[i].count < massTree[i + 1].count) {
						root->left = &massTree[i];
						root->right = &massTree[i + 1];
					}
					else {
						root->right = &massTree[i];
						root->left = &massTree[i + 1];
					}

					
					
					i += 2;
					selectParent = 1; //���� �� ����� �������� � ������ ��������, ��������� ������ �� �����
					//root = &massTree[i];
					break;
				}



			}
			if (selectParent == 0) {// ���� �� �����, ������ ������
				
				
				

				temp[first] = add(temp[first], massTree[i + 1].count, massTree[i + 1].word);
				
				
				root = &massTree[i + 1];
				root->count = countParent;
				root->word = '\0';
				
				
				if (massTree[i].count > temp[first]->count) {
					root->right = &massTree[i];
					root->left = temp[first];
				}
				else {
					root->right = temp[first];
					root->left = &massTree[i];
				}
				i++;

				first++;
			}
		} 
		else {
			i++;
			
		}
	}
	
 	return root;
}
