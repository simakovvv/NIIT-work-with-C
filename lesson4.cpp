//#define _CRT_SECURE_NO_WARNINGS
//#define LENGTH 11
//
//#include <stdlib.h> //для юзания рандмных чисел
//#include <stdio.h>
//#include <locale.h>
//
//void random(int p[LENGTH]) {
//	
//	srand(time(NULL));     // инициализация функции rand значением функции time
//	
//	for (int i = 1; i <= LENGTH; i++) {
//	
//		p[i] = rand() % (1 - 100); // Разименовывание
//			
//	}
//	
//}
//
//void bubbleSort(int p[LENGTH], int size)
//{
//	int x;
//	for (int i = 1; i <= LENGTH; i++) {
//		for (int j = 1; j <= LENGTH; j++) {
//			if (p[j - 1] > p[j]) {
//				x = p[j - 1];
//				p[j - 1] = p[j];
//				p[j] = x;
//			}
//		}
//	}
//
//}
//
//
//
//int binarysearch(int a, int mass[], int low, int high)
//	{
//		int middle = 0;
//		
//		if (low <= high)
//		{
//			middle = (low + high) / 2;
//			printf(" middle %d\n", mass[middle]);
//			if (a == mass[middle]) 
//				return middle;
//			
//			else if (a < mass[middle]) 
//				return binarysearch(a, mass, low, (middle - 1));
//			else if (a > mass[middle])
//				return binarysearch(a, mass, (middle + 1), high);
//			
//		}
//		return -1;
//	}
//
//void print(int p[LENGTH]) {
//	for (int i = 0; i < LENGTH; i++) {
//		
//			printf("%d, ",p[i]); // Печать
//		
//	}
//	printf("\n");
//}
//
//void main() {
//	setlocale(LC_ALL, "Russian");
//	int arrDigit[LENGTH] = { 0 };
//	printf("%d, ", arrDigit[0]);
//
//
//	int num, numAdr;
//	random(arrDigit);
//	bubbleSort(arrDigit, LENGTH);
//	print(arrDigit);
//
//	printf("Введите число. которое хотите найти: \n");
//
//	scanf("%d", &num);
//
//	numAdr = binarysearch(num, arrDigit, 0, (LENGTH-1));
//
//	(numAdr != -1) ? printf("Ваше число находится на %d позиции: \n", numAdr) : printf(" Такого числа здесь нет");
//
//	getch();
//}