#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 28 
#define HEIGTH 60
#define STRENGHT 3
#include <stdlib.h> //��� ������ �������� �����
#include <stdio.h>
#include <locale.h>//������� ����
#include <time.h>
#include "Population.h"
#include "windows.h"// ��� sleep

int main() {
	setlocale(LC_ALL, "Russian");

	int universe[LENGTH][HEIGTH] = { 0 };
	int universeNext[LENGTH][HEIGTH] = { 0 };
	int count = 0;//������� ���������


	int f1 = 1;
	int f2 = 1;
	int i = 1;
	randomPopulation(universe);



	while (i == 1) {

		nextGeneration(universe, universeNext);



		system("cls");
		print(universe);

		Sleep(1000);
		copyArr(universe, universeNext, &f1, &f2);
		if (f1 == 0) {
			i = 0;
			printf(" ����������� ������ �� %d ���������\n", count);
		}
		if (f2 == 0) {
			i = 0;
			printf(" ����������� ������ � ������������ �� %d ���������\n", count);
		}

	}

	



}