#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 10
#define HEIGTH 20
#include <stdlib.h> //��� ������ �������� �����
#include <stdio.h>
#include <locale.h>

//void random(int p[][LENGTH]) {
//	
//	srand(time(NULL));     // ������������� ������� rand ��������� ������� time
//	
//	for (int i = 1; i <= LENGTH; i++) {
//		for (int j = 1; j <= LENGTH; j++) {
//			p[i][j] = rand() % (1 - 5); // ���������������
//		}	
//	}
//	
//}
//
//void print(int p[][LENGTH]) {
//	for (int i = 1; i <= LENGTH; i++) {
//		for (int j = 1; j <= LENGTH; j++) {
//			printf("%d, ",p[i][j]); // ������
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
//	printf("������������ ������������� ���������, ������� ���� ������� ���������: %d ", summDigit); // ������
//	getch();
//}


// ������ 2
//void random(int p[][HEIGTH]) {
//	
//	srand(time(NULL));     // ������������� ������� rand ��������� ������� time
//	
//	for (int i = 0; i < LENGTH; i++) {
//		for (int j = 0; j < HEIGTH; j++) {
//			p[i][j] = rand() % (1 - 100); // ���������������
//		}	
//	}
//	
//}
//
//void print(int p[][HEIGTH]) {
//	for (int i = 0; i < LENGTH; i++) {
//		for (int j = 0; j < HEIGTH; j++) {
//			printf("%d, ",p[i][j]); // ������
//		}
//		printf("\n");
//	}
//}
//
//
//int multiples(int p[][HEIGTH]) {
//	int quantity = 0;
//	printf("���������� �������� �������: %d\n", LENGTH);
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
//	printf("K��������� ������ ���������, ������� ���������� �������� �������: %d ", multiples(squareArr)); // ������
//}




