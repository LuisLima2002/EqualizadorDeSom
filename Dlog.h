/*
 * Dlog.h
 *
 *  Created on: 15 de fev de 2022
 *      Author: wodwa
 */

#ifndef __DLOG_H__
#define __DLOG_H__
#define SIZE_LOG 441
#define WAIT_TRIGER  1
#define TRIGGERED    2
#define NO_TRIGGER   3
//*********** Structure Definition ********//
typedef struct{
    float *input_ch1;
    float *input_ch2;
    float log_ch1[SIZE_LOG];
    float log_ch2[SIZE_LOG];
    float prev_value;
    float trig_value;
    unsigned short int status;
    unsigned short int pre_scalar;
    unsigned short int skip_count;
    unsigned int size;
    unsigned int count;
}DLOG;

//*********** Function Declarations *******//
void DLOG_Init(DLOG *v);
void DLOG_Func(DLOG *v);

//*********** Macro Definition ***********//
#define DLOG_MACRO(v)                                         \
    switch(v.status)                                                \
    {                                                               \
    case 1: /* wait for trigger*/                                   \
        if(*v.input_ch1>v.trig_value && v.prev_value<v.trig_value) \
        {                                                           \
            /* rising edge detected start logging data*/            \
            v.status=2;                                             \
        }                                                           \
        break;                                                      \
    case 2:                                                         \
        v.skip_count++;                                             \
        if(v.skip_count==v.pre_scalar)                              \
        {                                                           \
            v.skip_count=0;                                         \
            v.log_ch1[v.count]=*v.input_ch1;                   \
            v.log_ch2[v.count]=*v.input_ch2;                   \
            v.count++;                                              \
            if(v.count==v.size)                                     \
            {                                                       \
                v.count=0;                                          \
                v.status=1;                                         \
            }                                                       \
        }                                                           \
        break;                                                      \
    default:                                                        \
        v.status=0;                                                 \
    }                                                               \
    v.prev_value=*v.input_ch1;                                     \

#endif /* DLOG_H_ */
