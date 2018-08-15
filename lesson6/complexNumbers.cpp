#include "complexNumbers.h"
#include <math.h>
#include <complex> 

COMPLEXNUMBERS addition(const COMPLEXNUMBERS *p1, const COMPLEXNUMBERS *p2)
{
	COMPLEXNUMBERS p3;
	p3.a = p1->a + p2->a;
	p3.b = p1->b + p2->b;
	return p3;
}

COMPLEXNUMBERS subtraction(const COMPLEXNUMBERS * p1, const COMPLEXNUMBERS * p2)
{
	COMPLEXNUMBERS p3;
	p3.a = p1->a - p2->a;
	p3.b = p1->b - p2->b;
	return p3;
}

COMPLEXNUMBERS multiplication(const COMPLEXNUMBERS * p1, const COMPLEXNUMBERS * p2)
{
	COMPLEXNUMBERS p3;
	p3.a = (p1->a * p2->a) - (p1->b * p2->b);
	p3.b = (p1->b * p2->a) + (p1->a * p2->b);
	return p3;
}

COMPLEXNUMBERS division(const COMPLEXNUMBERS * p1, const COMPLEXNUMBERS * p2)
{
	COMPLEXNUMBERS p3;
	p3.a = ((p1->a * p2->a) + (p1->b * p2->b)) / ((p2->a*p2->a) + (p2->a*p2->a));
	p3.b = ((p1->b * p2->a) - (p1->a * p2->b)) / ((p2->a*p2->a) + (p2->a*p2->a));
	return p3;
}

double moduleD(const COMPLEXNUMBERS * p1)
{
	double p3;
	p3 = sqrt(pow(p1->a,2) + pow(p1->b,2));
	
	return p3;
}

double phase(const COMPLEXNUMBERS * p1)
{
	
	return atan2(p1->a, p1->b);
}

void printComplex(const COMPLEXNUMBERS * p)
{
	printf("[%.2lf %s %.2lfi]\n", p->a, p->b > 0 ? "+" : "", (*p).b);
}
