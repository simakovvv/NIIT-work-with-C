#include "Point.h"
#include <stdio.h>
#include "pointArray.h"
#include "colorPoint.h"
#include "complexNumbers.h"
int main() {
	/*POINT p1 = { 0,0 };
	POINT p2 = { 5,5 };
	printPoint(&p1);
	printPoint(&p2);
	printf("%.2lf\n", calculate_distance(&p1, &p2));
*/
	

	//initArray();
	//printArray();


	/*COLORPOINT p1;
	init(&p1, "red", 5, 5);
	printColorPoint(&p1);*/


	COMPLEXNUMBERS p1 = { 1, 1 };
	COMPLEXNUMBERS p2 = { 2, 2 };
	printf("First digit:\n");
	printComplex(&p1);
	printf("Second digit:\n");
	printComplex(&p2);

	printf("addition:");
	printComplex(&addition(&p1, &p2));
	printf("subtraction:");
	printComplex(&subtraction(&p1, &p2));
	printf("multiplication:");
	printComplex(&multiplication(&p1, &p2));
	printf("division:");
	printComplex(&division(&p1, &p2));

	printf("module:");
	printf("%.2lf\n", moduleD(&p1));
	
	printf("phase:");
	printf("%.2lf\n", phase(&p1));
	

	return 0;
	
};