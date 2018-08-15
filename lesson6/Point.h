#ifndef POINT_H
#define POINT_H




typedef struct point
{
	double x, y;
}POINT;

double calculate_distance(const POINT *p1, const POINT *p2);
void printPoint(const POINT *p);
#endif // !POINT_H
