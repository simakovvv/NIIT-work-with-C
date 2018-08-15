#pragma once
#define LENGTH 28
#define HEIGTH 60

void randomPopulation(int p[][HEIGTH]);
int cellEnviorment(int lastGen[][HEIGTH], int i, int j);
void nextGeneration(int lastGen[][HEIGTH], int nextGen[][HEIGTH]);
void print(int p[][HEIGTH]);
void copyArr(int p[][HEIGTH], int p1[][HEIGTH], int *false1, int *false2);
