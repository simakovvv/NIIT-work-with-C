#include "Point.h"
#include <math.h>
#include <stdio.h>

#include "Point.h"


double calculate_distance(const POINT *p1, const POINT *p2) {
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}
void printPoint(const POINT * p)
{
	printf("[%.2lf, %.2lf]", p->x, (*p).y);

}