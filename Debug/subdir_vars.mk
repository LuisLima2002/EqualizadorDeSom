################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../2837xD_RAM_CLA_lnk_cpu1.cmd \
../F2837xD_Headers_nonBIOS_cpu1.cmd 

CLA_SRCS += \
../CLA_Tasks.cla 

LIB_SRCS += \
../cla1_math_library_datarom_fpu32.lib 

ASM_SRCS += \
../F2837xD_CodeStartBranch.asm \
../F2837xD_usDelay.asm 

C_SRCS += \
../CLA_Config.c \
../Dlog.c \
../F2837xD_Adc.c \
../F2837xD_CpuTimers.c \
../F2837xD_DefaultISR.c \
../F2837xD_GlobalVariableDefs.c \
../F2837xD_Gpio.c \
../F2837xD_PieCtrl.c \
../F2837xD_PieVect.c \
../F2837xD_SysCtrl.c \
../Peripheral_Setup.c \
../ft.c \
../main.c 

CLA_DEPS += \
./CLA_Tasks.d 

C_DEPS += \
./CLA_Config.d \
./Dlog.d \
./F2837xD_Adc.d \
./F2837xD_CpuTimers.d \
./F2837xD_DefaultISR.d \
./F2837xD_GlobalVariableDefs.d \
./F2837xD_Gpio.d \
./F2837xD_PieCtrl.d \
./F2837xD_PieVect.d \
./F2837xD_SysCtrl.d \
./Peripheral_Setup.d \
./ft.d \
./main.d 

OBJS += \
./CLA_Config.obj \
./CLA_Tasks.obj \
./Dlog.obj \
./F2837xD_Adc.obj \
./F2837xD_CodeStartBranch.obj \
./F2837xD_CpuTimers.obj \
./F2837xD_DefaultISR.obj \
./F2837xD_GlobalVariableDefs.obj \
./F2837xD_Gpio.obj \
./F2837xD_PieCtrl.obj \
./F2837xD_PieVect.obj \
./F2837xD_SysCtrl.obj \
./F2837xD_usDelay.obj \
./Peripheral_Setup.obj \
./ft.obj \
./main.obj 

ASM_DEPS += \
./F2837xD_CodeStartBranch.d \
./F2837xD_usDelay.d 

OBJS__QUOTED += \
"CLA_Config.obj" \
"CLA_Tasks.obj" \
"Dlog.obj" \
"F2837xD_Adc.obj" \
"F2837xD_CodeStartBranch.obj" \
"F2837xD_CpuTimers.obj" \
"F2837xD_DefaultISR.obj" \
"F2837xD_GlobalVariableDefs.obj" \
"F2837xD_Gpio.obj" \
"F2837xD_PieCtrl.obj" \
"F2837xD_PieVect.obj" \
"F2837xD_SysCtrl.obj" \
"F2837xD_usDelay.obj" \
"Peripheral_Setup.obj" \
"ft.obj" \
"main.obj" 

C_DEPS__QUOTED += \
"CLA_Config.d" \
"Dlog.d" \
"F2837xD_Adc.d" \
"F2837xD_CpuTimers.d" \
"F2837xD_DefaultISR.d" \
"F2837xD_GlobalVariableDefs.d" \
"F2837xD_Gpio.d" \
"F2837xD_PieCtrl.d" \
"F2837xD_PieVect.d" \
"F2837xD_SysCtrl.d" \
"Peripheral_Setup.d" \
"ft.d" \
"main.d" 

CLA_DEPS__QUOTED += \
"CLA_Tasks.d" 

ASM_DEPS__QUOTED += \
"F2837xD_CodeStartBranch.d" \
"F2837xD_usDelay.d" 

C_SRCS__QUOTED += \
"../CLA_Config.c" \
"../Dlog.c" \
"../F2837xD_Adc.c" \
"../F2837xD_CpuTimers.c" \
"../F2837xD_DefaultISR.c" \
"../F2837xD_GlobalVariableDefs.c" \
"../F2837xD_Gpio.c" \
"../F2837xD_PieCtrl.c" \
"../F2837xD_PieVect.c" \
"../F2837xD_SysCtrl.c" \
"../Peripheral_Setup.c" \
"../ft.c" \
"../main.c" 

ASM_SRCS__QUOTED += \
"../F2837xD_CodeStartBranch.asm" \
"../F2837xD_usDelay.asm" 


