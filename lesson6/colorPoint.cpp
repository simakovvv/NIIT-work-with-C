#define _CRT_SECURE_NO_WARNINGS
#include "colorPoint.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void init(COLORPOINT * pcb, const char * s, double x, double y)
{
	pcb->color = (char*)malloc((strlen(s) + 1) * sizeof(char));
	strcpy(pcb->color, s);
	pcb->xy = { x,y };
}

void destroy(COLORPOINT * pcb)
{
	if (pcb->color)
		free(pcb->color);

}

void printColorPoint(const COLORPOINT *p)
{
	printPoint(&p->xy);
	printf(", %s \n", p->color);
}
