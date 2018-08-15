#ifndef COLORPOINT_H
#define COLORPOINT_H
#include "Point.h"
typedef struct colorPoint
{
	char* color;
	POINT xy;
} COLORPOINT;

void init(COLORPOINT * pcb, const char * s, double x, double y);
void destroy(COLORPOINT* pcb);


void printColorPoint(const COLORPOINT *xy);

#endif // !COLORPOINT_H
