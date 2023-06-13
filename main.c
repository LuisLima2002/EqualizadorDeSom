#include "CLA_Config.h"
#include "Peripheral_Setup.h"
#include "Dlog.h"
#include "ft.h"
//
__interrupt void isr_cpu_timer0(void);
__interrupt void isr_adc(void);


float soundin = 0, soundout;
float gain[] = {1.0, 1.0, 2.0, 1.0, 2.0, 1.0, 0, 0, 0, 0};
float global = 1.0;
uint16_t counter = 0;
int16_t dac = 0;
DLOG dlog;

ft band1 = ft_DEFAULTS; //
ft band2 = ft_DEFAULTS; //
ft band3 = ft_DEFAULTS; //
ft band4 = ft_DEFAULTS; //
ft band5 = ft_DEFAULTS; //
ft band6 = ft_DEFAULTS; //
ft band7 = ft_DEFAULTS; //
ft band8 = ft_DEFAULTS; //
ft band9 = ft_DEFAULTS; //
ft band10 = ft_DEFAULTS; //


int main(void){
    InitSysCtrl();                              // Initialize System Control:
    DisablePeripheralClocks();
    DINT;                                       // Disable CPU interrupts
    InitPieCtrl();                              // Initialize the PIE control registers to their default state
    IER = 0x0000;                               // Disable CPU interrupts
    IFR = 0x0000;                               // Clear all CPU interrupt flags:
    InitPieVectTable();                         // Initialize the PIE vector table

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;       // Enable timer clock
    PieVectTable.TIMER0_INT = &isr_cpu_timer0;  // Redirect function to interruption
    PieVectTable.ADCA1_INT = &isr_adc;          // Redirect function to interruption
    EDIS;

    // pg. 102 PIE Channel Mapping spruhm8i.pdf - Technical reference
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;          // Enable PieVector to Timer 0 interrupt
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;          // Enable PieVector to ADCA1 interrupt
    IER |= (M_INT1);                            // Enable lines of interrupt

    InitCpuTimers();                            // Initializae cpu timer
    ConfigCpuTimer(&CpuTimer0, 200, 1000000);   // Configure cpu timer0 with 200MHz and 1s
    CpuTimer0Regs.TCR.all = 0x4000;             // Enable timer 0

    Setup_GPIO();                               // Configure GPIOs
    Setup_ePWM();                               // Configure ePWM
    Setup_ADC_A();                              // Configure ADC A em 12bits
    Setup_DAC_A();

    band1.a1 = -1.999924;
    band1.a2 = 0.999929;
    band1.b0 = 0.356176E-4;
    band1.b2 = -0.356176E-4;

    band2.a1 = -1.999837;
    band2.a2 = 0.999858;
    band2.b0 = 0.712325E-4;
    band2.b2 = -0.712325E-4;

    band3.a1 = -1.999778;
    band3.a2 = 0.999858;
    band3.b0 = 0.712314E-4;
    band3.b2 = -0.712314E-4;

    band4.a1 = -1.999398;
    band4.a2 = 0.999715;
    band4.b0 = 1.424443E-4;
    band4.b2 = -1.424443E-4;

    band5.a1 = -1.997594;
    band5.a2 = 0.998861;
    band5.b0 = 0.569398E-3;
    band5.b2 = -0.569398E-3;

    band6.a1 = -1.993797;
    band6.a2 = 0.998862;
    band6.b0 = 0.568858E-3;
    band6.b2 = -0.568858E-3;

    band7.a1 = -1.977560;
    band7.a2 = 0.997734;
    band7.b0 = 1.132767E-3;
    band7.b2 = -1.132767E-3;

    band8.a1 = -1.918275;
    band8.a2 = 0.997768;
    band8.b0 = 1.115883E-3;
    band8.b2 = -1.115883E-3;

    band9.a1 = -1.696026;
    band9.a2 = 0.995792;
    band9.b0 = 0.210398E-2;
    band9.b2 = -0.210398E-2;

    band10.a1 = -1.015851;
    band10.a2 = 0.993141;
    band10.b0 = 0.342967E-2;
    band10.b2 = -0.342967E-2;

    band1.reset(&band1);
    band2.reset(&band2);
    band3.reset(&band3);
    band4.reset(&band4);
    band5.reset(&band5);
    band8.reset(&band6);
    band7.reset(&band7);
    band8.reset(&band8);
    band9.reset(&band9);
    band10.reset(&band10);

    //CLA1_ConfigCLAMemory();
    //CLA1_InitCpu1Cla1();

    DLOG_Init(&dlog);
    dlog.input_ch1 = &soundin;
    dlog.input_ch2 = &soundout;
    dlog.pre_scalar = 1;

    EINT;                                       // Enable Global interrupt INTM
    ERTM;                                       // Enable Global realtime interrupt DBGM
    GpioDataRegs.GPADAT.bit.GPIO31 = 0;         // Turn off LED

    while(1){

        counter++;
    }// Infinite loop
    return 0;
}

// Interruptions
__interrupt void isr_cpu_timer0(void){
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void isr_adc(void){
    GpioDataRegs.GPASET.bit.GPIO1 = 1;
    soundin =  0.1*((int)AdcaResultRegs.ADCRESULT0 - 0x7FF);

    band1.x0 = soundin;
    band1.calc(&band1);

    band2.x0 = soundin;
    band2.calc(&band2);

    band3.x0 = soundin;
    band3.calc(&band3);

    band4.x0 = soundin;
    band4.calc(&band4);

    band5.x0 = soundin;
    band5.calc(&band5);

    band6.x0 = soundin;
    band6.calc(&band6);

    band7.x0 = soundin;
    band7.calc(&band7);

    band8.x0 = soundin;
    band8.calc(&band8);

    band9.x0 = soundin;
    band9.calc(&band9);

    band10.x0 = soundin;
    band10.calc(&band10);


    soundout = band1.y0*gain[0] + band2.y0*gain[1] + band3.y0*gain[2] + band4.y0*gain[3] + band5.y0*gain[4];
    soundout += band6.y0*gain[5] + band7.y0*gain[6] + band8.y0*gain[7] + band9.y0*gain[8] + band10.y0*gain[9];

    dac = (int)(global*soundout) + 0x7FF;

    if(dac > 4095 ) dac = 4095;
    else if(dac < 0) dac = 0;

    EALLOW;
    DacaRegs.DACVALS.bit.DACVALS = dac; //12 bits
    EDIS;

    DLOG_Func(&dlog);
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;
}


// Definicoes em CLA_Config.h
__interrupt void CLA1_isr1(void){
    asm(" ESTOP0");
    //PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;
}

__interrupt void CLA1_isr2(void){
    asm(" ESTOP0");
}

__interrupt void CLA1_isr3(void){
    asm(" ESTOP0");
}

__interrupt void CLA1_isr4(void){
    asm(" ESTOP0");
}

__interrupt void CLA1_isr5(void){
    asm(" ESTOP0");
}

__interrupt void CLA1_isr6(void){
    asm(" ESTOP0");
}

__interrupt void CLA1_isr7(void){
    //asm(" ESTOP0");
    asm(" ESTOP0");
}

__interrupt void CLA1_isr8(void){
    asm(" ESTOP0");
}
