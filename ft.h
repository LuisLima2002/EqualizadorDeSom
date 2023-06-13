/*
 * filter.h
 *
 *  Created on: 15/09/2017
 *      Author: waner
 */

#ifndef FT_H_
#define FT_H_

typedef struct {		//filtro / ressonante
	float a1;			//a - denominador
	float a2;			//b - numerador
	float a3;			
	float b0;
	float b1;
	float b2;
	float b3;
	float x0;			//entrada atual
	float x1;			//entrada anterior
	float x2;
	float x3;
	float y0;			//saída atual
	float y1;			//saída anterior
	float y2;
	float y3;
	void  (*calc)();	  	// Pointer to calculation function
	void  (*reset)();	  	// Pointer to reset function
} ft;
void ft_calc(ft *v);
void ft_reset(ft *v);
#define ft_DEFAULTS {0, \
                         0, \
						 0, \
                         0, \
						 0, \
						 0, \
						 0, \
						 0, \
                         0, \
						 0, \
                         0, \
                         0, \
						 0, \
                         0, \
                         0, \
                         (void (*)(Uint32))ft_calc,\
						 (void (*)(Uint32))ft_reset,\
};

#define FT_CALC_MACRO(v)\
        v.y0 = v.b0*v.x0 + v.b1*v.x1 + v.b2*v.x2 + v.b3*v.x3 - (v.a1*v.y1 + v.a2*v.y2 + v.a3*v.y3);\
        v.x3 = v.x2;\
        v.x2 = v.x1;\
        v.x1 = v.x0;\
        v.y3 = v.y2;\
        v.y2 = v.y1;\
        v.y1 = v.y0;\

#endif /* FT_H_ */
