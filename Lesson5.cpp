//1.	�������� ������� ������ ������ ��������� ����� � ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
//
//int lengthWord(char *string){
//	int count = 0;
//	while( *string ){
//		count++;
//		*string++;
//		
//
//	}
//	return count;
//}
//
//void main() {
//	setlocale(LC_ALL, "Russian");
//	char string[] = "Word";
//
//	
//	printf("����� ��������: %d\n ", lengthWord(string));
//	puts(string);
//
//
//	getch();
//}

//1.	�������� ������� ������ ������ ��������� ����� � ������
//char *minWord(char *sentence) {
//	int min = 0, next = 0;
//	char *minW = 0;
//	while (*sentence) {
//		if (*sentence == ' ') {
//			if (next < min) {
//				min = next;
//				minW = sentence;
//				*sentence++;
//			}
//			next = 0;
//		}
//		else {
//			next++;
//			*sentence++;
//		}
//		
//	}
//	return minW;
//}
//int main() {
//	char sentence[] = "howhow how howh hw";
//	printf("����� �������� �����: %s, ��� �������� %d ����", minWord(sentence));//, strlen(minWord(sentence))
//}