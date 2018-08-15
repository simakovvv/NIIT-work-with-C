#define SIZE 50
#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <stdio.h>
void printMass(int *mass) {
	
	for (int i = 0; i < SIZE; i++) {
		if (*mass != 0) {
			printf(" %d, ", *mass);
		}
		*mass++;
	}
}
int* massSum(char* sentence, int mass[SIZE]) {
	int *mass1 = &mass[0];
	int iter = 0;
	int word = 0;
	while (*sentence != '\n') {

		if (*sentence != ' ')
		{
			mass[word] += (int)*sentence;
		}
		else
		{
			word++;
		}
		
		*sentence++;
	}
	return mass1;
}
int main() {
	setlocale(LC_ALL, "Russian");
	char *rstr;
	int mass[SIZE] = { 0 };
	char sentence[SIZE] = { 0 };
	printf("Введите предложение, сумму букв которого вы хотите посчитать:\n");
	fgets(sentence, SIZE, stdin);
	
	


	printf(" Предложение : %s  \n", sentence);
	printf(" Суммы ASCII кодов его слов :");
	printMass(massSum(sentence, mass));

}