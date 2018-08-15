#include "list.h"
#include "operations.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
	Node *phead = 0;
	Node *phead1 = 0;
	srand(time(0));

	for (int i = 0; i < 10; ++i) {
		add2list(&phead, rand() % 100);
		add2listSort(&phead1, rand() % 100);
	}
	printf("Elements of the list1 (not sort): \n");
	print(phead);
	printf("Sum of elements: %d \n", summ(phead));
	printf("Maximum element: %d \n", maxElem(phead));
	printf("The sum of the maximum and minimum elements: %d \n", summMinMax(phead));
	printf("Mass Sort Indicator: %s \n", (hasSort(phead)) ? "Not sort":"Sort");

	printf("Elements of the list2 (sort): \n");
	print(phead1);
	printf("Sum of elements: %d \n", summ(phead1));
	printf("Maximum element: %d \n", maxElem(phead1));
	printf("The sum of the maximum and minimum elements: %d \n", summMinMax(phead1));
	printf("Mass Sort Indicator: %s \n", (hasSort(phead1)) ? "Not sort" : "Sort");

	deleteList(phead);
	deleteList(phead1);
}