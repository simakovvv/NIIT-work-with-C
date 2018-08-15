#define _CRT_SECURE_NO_WARNINGS
#define SIZE 256
#include "sortTree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include < time.h > 
#include "Struct.h"
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");

	/*Node* root = NULL;
	srand(time(0));
	for (int i = 0; i<10; i++) {
		int a = rand() % 101 - 50;
		root = add(root, a);
	}
	print(root, 0);
	int a;
	scanf("%d", &a);
	root = del(root, a);
	printf("\n\n");
	print(root, 0);


	
	printf("\npre\n");
	post(root);
	printf("\nin\n");
	in(root);
	printf("\npost\n");
	pre(root);
	printf("\n");*/
	Elem alphbet[SIZE] = { 0 };
	Node *root = NULL;
	Alphabet(alphbet); //записываем таблицу ASCII
	readFromFile(alphbet);// считываем текст из файла
	
	sortAndStruct(alphbet);//сортируем часто встречающиеся символы
	//printS(alphbet);// - посмотреть таблицу частот символов в тексте
	
	root = parseMassToTree(root, alphbet);
	print(root,0);
	
	return 0;
}
