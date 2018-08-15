#define _CRT_SECURE_NO_WARNINGS
#define SIZE 256
#include <stdlib.h>
#include "Struct.h"
#include <stdio.h>


void  Alphabet(Elem *alphabet) {

	for (int i = 0; i < SIZE-1; i++) {
		alphabet[i].word = (char)i;
	}

}

void printS(Elem *alphabet) {
	for (int i = 0; i < SIZE; i++) {
		printf(" %c -  %d \n", alphabet[i].word, alphabet[i].count);
	}
}

void readFromFile(Elem * alphabet)
{
	


	FILE *mf;
	int c, counter = 0;
	printf("Открытие файла : ");

	// Открытие файла
	mf = fopen("text.txt", "r");

	// Проверка открытия файла
	if (mf == NULL) printf("ошибка\n");
	else printf("выполнено\n");


	printf("Открытие файла : ");

	// Проверка открытия файла
	if (mf == NULL) printf("ошибка\n");
	else printf("выполнено\n");

	do
	{
		c = fgetc(mf);

		for (int i = 0; i < SIZE; i++) {
			if (c == alphabet[i].word) alphabet[i].count++;

		}


	} while (c != EOF); // пока не конец файла



	// Закрытие файла
	fclose(mf);
	printf("Файл закрыт\n");
}



void sortAndStruct(Elem *mass)
{
	int left = 0, right = SIZE - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
				   // Выполнение цикла пока левая граница не сомкнётся с правой
				   // или пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i<right; i++)  //двигаемся слева направо
		{
			if (mass[i].count>mass[i + 1].count) // если следующий элемент меньше текущего,
			{             // меняем их местами
				Elem t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i>left; i--)  //двигаемся справа налево
		{
			if (mass[i - 1].count>mass[i].count) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				Elem t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}
