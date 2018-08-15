#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 28
#define HEIGTH 60

#include <stdlib.h> //��� ������� ������
#include < string.h  >   //��� memccpy
#include <time.h>
#include <stdio.h>

int cellEnviorment(int lastGen[][HEIGTH], int i, int j) {
	int neighborsCount = 0; //���������� ������� 
	int neighbors = 0; // ���������� ����� �������  lastGen[i][((j + 1) % HEIGTH)]  

	while (neighborsCount != 8) { //(j + 1) == HEIGTH ? lastGen[i][0] : lastGen[i][j + 1]
		if ((j + 1) == HEIGTH ? lastGen[i][0] : lastGen[i][j + 1]) { // ����� ������   
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}
		if ((i + 1) == LENGTH ? lastGen[0][j] : lastGen[i + 1][j]) { // ����� �����   
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}
		if ((j - 1) == -1 ? lastGen[i][HEIGTH] : lastGen[i][j - 1]) { // ����� �����   
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}
		if ((i - 1) == -1 ? lastGen[LENGTH][j] : lastGen[i - 1][j]) { // ����� ������   
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}

		if ((j + 1) == HEIGTH ? lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][0] : lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][j + 1]) { // ����� ������ �����
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}

		if ((j + 1) == HEIGTH ? lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][0] : lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][j + 1]) { // ����� ������ ������
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}

		if ((j - 1) == -1 ? lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][HEIGTH] : lastGen[(i - 1) == -1 ? LENGTH : (i - 1)][j - 1]) { // ����� ����� ������
			neighborsCount++;
			neighbors++;
		}
		else {
			neighborsCount++;
		}
		if ((j - 1) == -1 ? lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][HEIGTH] : lastGen[(i + 1) == LENGTH ? 0 : (i + 1)][j - 1]) { // ����� ����� �����
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
			if (lastGen[i][j] == 1) {  // �������� �� ������� �����
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
	srand(time(NULL));     // ������������� ������� rand ��������� ������� time

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < HEIGTH; j++) {
			

			p[i][j] = rand() % 2; // ���������������

			strengthNext = cellEnviorment(p, i, j);// ����� �������
			if (strengthNext < 2) {
				p[i][j] = 1;
			}
		}

	}

}

void print(int p[][HEIGTH]) {


	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < HEIGTH; j++) {

			printf("%s ", (p[i][j] == 1) ? "*" : " "); // ������

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
				false1 = 0;
			}
			if (p[i][j] != p1[i][j]) {
				false2 = 0;
			}
			p[i][j] = p1[i][j];
		}
	}
}

