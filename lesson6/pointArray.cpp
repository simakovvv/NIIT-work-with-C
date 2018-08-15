#include "Point.h"
#include "pointArray.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 50

POINT arr[SIZE];

void initArray() {
	srand(time(0));
	
	for (int i = 0; i < SIZE; i++) {
		arr[i].x = rand() % 101 - 50;
		arr[i].x = rand() % 101 - 50;
	}
}
void printArray() {
	for (int i = 0; i < SIZE; i++) {
		printPoint(arr + i);
		printf(" \n");
	}
}