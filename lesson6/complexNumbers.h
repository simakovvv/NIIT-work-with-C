#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

typedef struct complexnumbers
{
	double a, b;
	
}COMPLEXNUMBERS;

COMPLEXNUMBERS addition(const COMPLEXNUMBERS *p1, const COMPLEXNUMBERS *p2);
COMPLEXNUMBERS subtraction(const COMPLEXNUMBERS *p1, const COMPLEXNUMBERS *p2);
COMPLEXNUMBERS multiplication(const COMPLEXNUMBERS *p1, const COMPLEXNUMBERS *p2);
COMPLEXNUMBERS division(const COMPLEXNUMBERS *p1, const COMPLEXNUMBERS *p2);
double moduleD(const COMPLEXNUMBERS *p1);
double phase(const COMPLEXNUMBERS *p1);


void printComplex(const COMPLEXNUMBERS *p);

#endif // ! COMPLEXNUMBERS_H
