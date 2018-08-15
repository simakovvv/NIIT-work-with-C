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
	printf("�������� ����� : ");

	// �������� �����
	mf = fopen("text.txt", "r");

	// �������� �������� �����
	if (mf == NULL) printf("������\n");
	else printf("���������\n");


	printf("�������� ����� : ");

	// �������� �������� �����
	if (mf == NULL) printf("������\n");
	else printf("���������\n");

	do
	{
		c = fgetc(mf);

		for (int i = 0; i < SIZE; i++) {
			if (c == alphabet[i].word) alphabet[i].count++;

		}


	} while (c != EOF); // ���� �� ����� �����



	// �������� �����
	fclose(mf);
	printf("���� ������\n");
}



void sortAndStruct(Elem *mass)
{
	int left = 0, right = SIZE - 1; // ����� � ������ ������� ����������� ������� �������
	int flag = 1;  // ���� ������� �����������
				   // ���������� ����� ���� ����� ������� �� �������� � ������
				   // ��� ���� � ������� ������� �����������
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i<right; i++)  //��������� ����� �������
		{
			if (mass[i].count>mass[i + 1].count) // ���� ��������� ������� ������ ��������,
			{             // ������ �� �������
				Elem t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;      // ����������� � ���� ����� ����
			}
		}
		right--; // �������� ������ ������� �� ���������� �������
		for (int i = right; i>left; i--)  //��������� ������ ������
		{
			if (mass[i - 1].count>mass[i].count) // ���� ���������� ������� ������ ��������,
			{            // ������ �� �������
				Elem t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;    // ����������� � ���� ����� ����
			}
		}
		left++; // �������� ����� ������� �� ��������� �������
	}
}
