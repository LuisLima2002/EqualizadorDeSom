/*
 * filter.c
 *
 *  Created on: 15/09/2017
 *      Author: waner
 */
#include "ft.h"

void ft_calc(ft *v){
	v->y0 = v->b0*v->x0 + v->b1*v->x1 + v->b2*v->x2 + v->b3*v->x3 - (v->a1*v->y1 + v->a2*v->y2 + v->a3*v->y3);
	
	v->x3 = v->x2;
	v->x2 = v->x1;	
	v->x1 = v->x0;
	
	v->y3 = v->y2;
	v->y2 = v->y1;
	v->y1 = v->y0;
}
void ft_reset(ft *v){
	v->x0 = 0;
	v->x1 = 0;
	v->x2 = 0;
	v->x3 = 0;

	v->y0 = 0;
	v->y1 = 0;
	v->y2 = 0;
	v->y3 = 0;
}

