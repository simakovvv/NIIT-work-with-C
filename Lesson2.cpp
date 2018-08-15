#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 10
#define HEIGTH 20
#include <stdlib.h> //для юзания рандмных чисел
#include <stdio.h>
#include <locale.h>

//void random(int p[][LENGTH]) {
//	
//	srand(time(NULL));     // инициализация функции rand значением функции time
//	
//	for (int i = 1; i <= LENGTH; i++) {
//		for (int j = 1; j <= LENGTH; j++) {
//			p[i][j] = rand() % (1 - 5); // Разименовывание
//		}	
//	}
//	
//}
//
//void print(int p[][LENGTH]) {
//	for (int i = 1; i <= LENGTH; i++) {
//		for (int j = 1; j <= LENGTH; j++) {
//			printf("%d, ",p[i][j]); // Печать
//		}
//		printf("\n");
//	}
//}
//
//void summ(int p[][LENGTH],int *summDigit) {
//	for (int i = 0; i <= LENGTH-1; i++) {
//		
//		*summDigit += p[i][i+1]; // 
//			
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int summDigit = 0; 
//	int squareArr[LENGTH][LENGTH] = { 0 };
//	random(squareArr);
//	print(squareArr);
//	summ(squareArr, &summDigit);
//	printf("Произведение положительных элементов, лежащих выше главной диагонали: %d ", summDigit); // Печать
//	getch();
//}


// задача 2
//void random(int p[][HEIGTH]) {
//	
//	srand(time(NULL));     // инициализация функции rand значением функции time
//	
//	for (int i = 0; i < LENGTH; i++) {
//		for (int j = 0; j < HEIGTH; j++) {
//			p[i][j] = rand() % (1 - 100); // Разименовывание
//		}	
//	}
//	
//}
//
//void print(int p[][HEIGTH]) {
//	for (int i = 0; i < LENGTH; i++) {
//		for (int j = 0; j < HEIGTH; j++) {
//			printf("%d, ",p[i][j]); // Печать
//		}
//		printf("\n");
//	}
//}
//
//
//int multiples(int p[][HEIGTH]) {
//	int quantity = 0;
//	printf("Количество столбцов матрицы: %d\n", LENGTH);
//	for (int i = 0; i < LENGTH; i++) {
//		for (int j = 0; j < HEIGTH; j++) {
//			if (p[i][j] % 2 == 0 && p[i][j] % LENGTH == 0) {
//				printf(" - %d\n", p[i][j]);
//				quantity++;
//			}
//		}
//	
//	}
//	return quantity;
//}
//
//int main(){
//	setlocale(LC_ALL, "Russian");
//	int squareArr[LENGTH][HEIGTH] = { 0 };
//	random(squareArr);
//	print(squareArr);
//	printf("Kоличество четных элементов, кратных количеству столбцов матрицы: %d ", multiples(squareArr)); // Печать
//}




