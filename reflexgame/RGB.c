#include "../pre_emptive_os/api/osapi.h"
#include "../pre_emptive_os/api/general.h"
#include <printf_P.h>
#include <lpc2xxx.h>

/*****************************************************************************
 *
 *    A process entry function. 
 *
 ****************************************************************************/
void testRGB(tU8 r, tU8 g, tU8 b)
{
	PINSEL0 &= 0xfff03fff;  //Enable PWM2 on P0.7, PWM4 on P0.8, and PWM6 on P0.9
	PINSEL0 |= 0x000a8000;  //Enable PWM2 on P0.7, PWM4 on P0.8, and PWM6 on P0.9

	//PULSE WIDTH MODULATION INIT*********************************************
	PWM_PR  = 0x00;    // Prescale Register
	PWM_MCR = 0x02;    // Match Control Register
	PWM_MR0 = 0x1000;    // TOTAL PERIODTID   T
	PWM_MR2 = r;    // H�G SIGNAL        t
	PWM_MR4 = b;    // H�G SIGNAL        t
	PWM_MR6 = g;    // H�G SIGNAL        t
	PWM_LER = 0x55;    // Latch Enable Register
	PWM_PCR = 0x5400;  // Prescale Counter Register PWMENA2, PWMENA4, PWMENA6
	PWM_TCR = 0x09;    // Counter Enable och PWM Enable
	//************************************************************************ 
}
