/*
 * CLA_Config.h
 *
 *  Created on: 30 de mar de 2020
 *      Author: waner
 */

#ifndef CLA_CONFIG_H_
#define CLA_CONFIG_H_
#include <CLA_Tasks.h>
#include "F28x_Project.h"
void CLA1_ConfigCLAMemory(void);
void CLA1_InitCpu1Cla1(void);
__interrupt void CLA1_isr1(void);
__interrupt void CLA1_isr2(void);
__interrupt void CLA1_isr3(void);
__interrupt void CLA1_isr4(void);
__interrupt void CLA1_isr5(void);
__interrupt void CLA1_isr6(void);
__interrupt void CLA1_isr7(void);
__interrupt void CLA1_isr8(void);

// Run CLA by software
//Cla1ForceTask1andWait();
//Cla1ForceTask1

#endif /* CLA_CONFIG_H_ */
