#define SIZE 256  //сделать доступ из одного файла
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

void in(Node *root) //инфиксная запись
{
	if (root)
	{
		in(root->left);
		printf("%d , %c\n", root->count, root->word);
		in(root->right);

	}
}

void pre(Node *root)//префиксная
{
	if (root)
	{
		printf("%d , %c\n", root->count, root->word);
		pre(root->left);
		pre(root->right);

	}
}

void post(Node *root)//постфиксная
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
//  mass -содержит частоты символов, отсортированные по возрастанию
//  root -ссылка на начало дерева

// создание дерева
// aa, ab, bb -суммы частот двух текущих узлов или листьев
// k -индекс для поиска родителя по частоте
// i -индекс выбора элементов листьев
// f -индекс текущей частоты
// first - индексб в который мы будем перезаписывать новые элементы


Node *parseMassToTree(Node *root, Elem *massStruct) {
	int k, i = 0, f = 1;
	static Node massTree[SIZE] = { 0 };
	static Node *temp[SIZE] = { 0 };
	int first = 0;
	convertToMassTree(massTree, massStruct);

	while (i < (SIZE-1)) {//выбор потомков
		int selectParent = 0;// обнуляем флаг поиска родителя
		int first = 0;

		if (massTree[i].count > 0) {
			int countParent = (massTree[i].count + massTree[i + 1].count);
			
			
			for (k = i; k < SIZE; k++) {// поиск элемента родителя с подходящей встречаемостью

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
					selectParent = 1; //если мы нашли родителя с нужной частотой, создавать пустую не будем
					//root = &massTree[i];
					break;
				}



			}
			if (selectParent == 0) {// если не нашли, создаём пустую
				
				
				

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
