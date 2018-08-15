#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 28
#define HEIGTH 60
#define STRENGHT 3
#include <stdlib.h> //для юзания рандмных чисел
#include <stdio.h>
#include <locale.h>//русский язык
#include "windows.h"// для sleep
#include <stdlib.h> //для очистки экрана
#include < string.h  >   //Для memccpy


int cellEnviorment(int lastGen[][HEIGTH], int i, int j) {
	int neighborsCount = 0; //количество соседей 
	int neighbors = 0; // количество живых соседей  lastGen[i][((j + 1) % HEIGTH)]  
	
			while (neighborsCount != 8) { //(j + 1) == HEIGTH ? lastGen[i][0] : lastGen[i][j + 1]
				if ((j + 1) == HEIGTH ? lastGen[i][0] : lastGen[i][j + 1]) { // сосед справа   
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}
				if ((i + 1) == LENGTH ? lastGen[0][j] : lastGen[i + 1][j]) { // сосед снизу   
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}
				if ((j - 1) == -1 ? lastGen[i][HEIGTH] : lastGen[i][j -1]) { // сосед слева   
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}
				if ((i - 1) == -1 ? lastGen[LENGTH][j] : lastGen[i - 1][j]) { // сосед сверху   
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}
				
				if ((j + 1) == HEIGTH ? lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][0] : lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][j + 1]) { // сосед справа снизу
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}

				if ((j + 1) == HEIGTH ? lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][0] : lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][j + 1]) { // сосед справа сверху
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}

				if ((j - 1) == -1 ? lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][HEIGTH] : lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][j - 1]) { // сосед слева сверху
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}
				if ((j - 1) == -1 ? lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][HEIGTH] : lastGen[(i + 1) == LENGTH ? 0 : (i + 1)  ][j - 1]) { // сосед слева снизу
					neighborsCount++;
					neighbors++;
				}
				else {
					neighborsCount++;
				}
			}
		
	return neighbors;
}

void nextGeneration(int lastGen[][HEIGTH], int nextGen[][HEIGTH]) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < HEIGTH; j++) {
			if (lastGen[i][j] == 0) {  // проверка на наличие жизни
				if (cellEnviorment(lastGen, i, j) == 2 || cellEnviorment(lastGen, i, j) == 3) {
					nextGen[i][j] = 1;
				}
				else
				{
					nextGen[i][j] = 0;
				}
			}
			else {
				if (cellEnviorment(lastGen, i, j) == 3) {
					nextGen[i][j] = 1;
				}
				else
				{
					nextGen[i][j] = 0;
				}
			}
		}
	}
}

void randomPopulation(int p[][HEIGTH]) {
	int strengthNext = 0;
	srand(time(NULL));     // инициализация функции rand значением функции time
	
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < HEIGTH; j++) {
			strengthNext++;
		
				p[i][j] = rand() % 2; // Разименовывание
				
			
		}	
		
	}
	
}

void print(int p[][HEIGTH]) {
	
	
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < HEIGTH; j++) {
			
			printf("%s ",(p[i][j] == 1) ? "*" : " " ); // Печать

		}
		printf("\n");
	}
}

void copyArr(int p[][HEIGTH], int p1[][HEIGTH], int *false1, int *false2) {
	false1 = 0;
	false2 = 0;
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < HEIGTH; j++) {
			if (p1[i][j] == 1) {
				false1 += 1;
			}
			if (p[i][j] != p1[i][j]) {
				false2 += 1;
			}
			p[i][j] = p1[i][j];
		}
	}
}


void main(){
	setlocale(LC_ALL, "Russian");
	
	int universe[LENGTH][HEIGTH] = { 0 };
	int universeNext[LENGTH][HEIGTH] = { 0 };
	int count = 0;//счётчик поколений

	
	int f1 = 1;
	int f2 = 1;
	int i = 1;
	randomPopulation(universe);

	
	
	while (  i == 1) {
		
		nextGeneration(universe, universeNext);



		system("cls");
		print(universe);
		
		Sleep(1000);
		copyArr(universe, universeNext, &f1, &f2);
		if (f1 == 0) {
			i = 0;
			printf(" Цивилизация умерла на %d поколении\n", count);
		}
		if (f2 == 0) {
			i = 0;
			printf(" Цивилизация пришла к стабильности на %d поколении\n", count);
		}
		
	}
	
	getch();


	
}