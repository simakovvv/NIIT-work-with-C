#include "Stack.h"

/* �������:
*   gcc -o rpn rpn.c
*
* �������������:
*   ./rpn <���������>
*
* ������:
*   ./rpn 3 5 +
*
* ���������: ���� ��������� `*' ������� �� `x', �.�. ������ `*' ������������
* ��������� ���������.
**/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define STKDPTH 32 /* ������� ����� */

/* ��������, ������������ �������� parse */
#define VAL  0  /* � ���� �������� ����� �������� */
#define ADD  1  /* �������� */
#define SUB  2  /* ��������� */
#define MUL  3  /* ��������� */
#define DIV  4  /* ������� */
#define SOF -1  /* ������������ ����� */
#define SUF -2  /* � ����� ������������ ��������� */
#define UNK -3  /* ������������ �������� */

/* ���������� ���������� */
int scount;
double stack[STKDPTH];

/* ������� ������������� ���������� */
int parse(char *);

/* ����� ����� */
int main(int argc, char **argv)
{
	/* ���������� ���� ��� �������� ���������� ��������� ������ */
	while (*++argv) {

		/* �������� ���������� ������� �������� ��� ����� ���
		* ������ �������������� �������� */
		switch (parse(*argv)) {
		case VAL: continue;

			/* ��������� */
		case ADD:
			stack[scount - 1] += stack[scount];
			break;

		case SUB:
			stack[scount - 1] -= stack[scount];
			break;

		case MUL:
			stack[scount - 1] *= stack[scount];
			break;

		case DIV:
			if (stack[scount] != 0) {
				stack[scount - 1] /= stack[scount];
				break;
			}
			else {
				fprintf(stderr, "������� �� ����!\n");
				return(1);
			}

			/* ��������� ������ */
		case SUF:
			fprintf(stderr, "������������ ���������!\n");
			return(1);

		case SOF:
			fprintf(stderr, "������������ �����!\n");
			return(1);

		case UNK:
			fprintf(stderr, "������������ ��������!\n");
			return(1);
		}
	}

	/* ������� ��������� */
	int i;
	for (i = 0; i < scount; i++) printf("%0.3f\n", stack[i]);

	return(0);
}

int parse(char *s)
{
	double tval = 0;
	char * endptr;

	/* ���������� ����� �������������� �������� */
	switch (*s) {
	case '-':
		/* ���� ����� �������� ������ � �� ��������� �������� ���������,
		* ������ ������������ ���� ������������� ����� � ���������� ���
		* ��� �������� ��������� �� ����� */
		if (*(s + 1) != '\0') break;
		if (scount >= 2) {
			scount -= 1;
			return(SUB);
		}
		else return(SUF);

	case '+':
		if (scount >= 2) {
			scount -= 1;
			return(ADD);
		}
		else return(SUF);

	case 'x':
		if (scount >= 2) {
			scount -= 1;
			return(MUL);
		}
		else return(SUF);

	case '/':
		if (scount >= 2) {
			scount -= 1;
			return(DIV);
		}
		else return(SUF);
	}

	errno = 0;

	/* �������� ��������������� ��������� �������� � ����� */
	tval = strtod(s, &endptr);

	/* ������� ������ `������������ ��������' � ������ ������� */
	if (errno != 0 || *endptr != '\0') return(UNK);

	/* ���������, ���� �� ��������� ����� � �����
	* � ��������� � ��� �������, ����� ���������� ������ ������������ */
	if (scount < STKDPTH) stack[scount++] = tval;
	else return(SOF);

	return(VAL);
}
