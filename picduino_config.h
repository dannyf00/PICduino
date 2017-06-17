/* 
 * File:   config.h
 * Author: Ken
 *
 * Created on March 29, 2014, 4:32 PM
 */

#ifndef __PICDUINO_CONFIG_H
#define	__PICDUINO_CONFIG_H

//#include <p32xxxx.h>							//p32xxxx.h included here
#include <xc.h>

//configuration settings
//PIC12F629, PIC12F675
//PIC16F684
//PIC16f882, PIC16f883, PIC16F884, PIC16F886, PIC16F887

//pic12f629/675
#if		defined(_12F629)	|| defined(_12F675)
//configuration bits
#pragma config BOREN = OFF
#pragma config CPD = OFF
#pragma config FOSC = INTRCIO
#pragma config MCLRE = OFF
#pragma config WDTE = OFF
#pragma config CP = OFF
#pragma config PWRTE = OFF

/*
BOREN =	Brown-out Detect Enable bit
OFF	BOD disabled
ON	BOD enabled
CPD =	Data Code Protection bit
OFF	Data memory code protection is disabled
ON	Data memory code protection is enabled
FOSC =	Oscillator Selection bits
EXTRCCLK	RC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, RC on GP5/OSC1/CLKIN
INTRCIO	INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN
XT	XT oscillator: Crystal/resonator on GP4/OSC2/CLKOUT and GP5/OSC1/CLKIN
LP	LP oscillator: Low power crystal on GP4/OSC2/CLKOUT and GP5/OSC1/CLKIN
INTRCCLK	INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN
EXTRCIO	RC oscillator: I/O function on GP4/OSC2/CLKOUT pin, RC on GP5/OSC1/CLKIN
EC	EC: I/O function on GP4/OSC2/CLKOUT pin, CLKIN on GP5/OSC1/CLKIN
HS	HS oscillator: High speed crystal/resonator on GP4/OSC2/CLKOUT and GP5/OSC1/CLKIN
MCLRE =	GP3/MCLR pin function select
OFF	GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD
ON	GP3/MCLR pin function is MCLR
WDTE =	Watchdog Timer Enable bit
OFF	WDT disabled
ON	WDT enabled
CP =	Code Protection bit
OFF	Program Memory code protection is disabled
ON	Program Memory code protection is enabled
PWRTE =	Power-Up Timer Enable bit
OFF	PWRT disabled
ON	PWRT enabled
*/

//PIC16F684
#elif 	defined(_16F684)
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config FOSC = INTOSCIO
#pragma config FCMEN = OFF
#pragma config MCLRE = OFF
#pragma config WDTE = OFF
#pragma config CP = OFF
#pragma config PWRTE = OFF

/*
CPD =	Data Code Protection bit
OFF	Data memory code protection is disabled
ON	Data memory code protection is enabled
BOREN =	Brown Out Detect
OFF	BOR disabled
ON	BOR enabled
NSLEEP	BOR enabled during operation and disabled in Sleep
SBODEN	BOR controlled by SBOREN bit of the PCON register
IESO =	Internal External Switchover bit
OFF	Internal External Switchover mode is disabled
ON	Internal External Switchover mode is enabled
FOSC =	Oscillator Selection bits
EXTRCCLK	EXTRC oscillator: External RC on RA5/OSC1/CLKIN, CLKOUT function on RA4/OSC2/CLKOUT pin
INTOSCCLK	INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
XT	XT oscillator: Crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKINT
LP	LP oscillator: Low-power crystal on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
EXTRCIO	EXTRCIO oscillator: External RC on RA5/OSC1/CLKIN, I/O function on RA4/OSC2/CLKOUT pin
EC	EC: I/O function on RA4/OSC2/CLKOUT pin, CLKIN on RA5/OSC1/CLKIN
INTOSCIO	INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN
HS	HS oscillator: High-speed crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN
FCMEN =	Fail-Safe Clock Monitor Enabled bit
OFF	Fail-Safe Clock Monitor is disabled
ON	Fail-Safe Clock Monitor is enabled
MCLRE =	MCLR Pin Function Select bit
OFF	MCLR pin function is digital input, MCLR internally tied to VDD
ON	MCLR pin function is MCLR
WDTE =	Watchdog Timer Enable bit
OFF	WDT disabled
ON	WDT enabled
CP =	Code Protection bit
OFF	Program memory code protection is disabled
ON	Program memory code protection is enabled
PWRTE =	Power-up Timer Enable bit
OFF	PWRT disabled
ON	PWRT enabled
*/

//16f882/883/884/886/887
#elif 	defined(_16F882)	|| defined(_16F883)	|| defined(_16F884)	|| defined(_16F886)	|| defined(_16F887)
//configuration bits
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config DEBUG = OFF
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config FCMEN = OFF
#pragma config MCLRE = OFF
#pragma config WDTE = OFF
#pragma config CP = OFF
#pragma config LVP = OFF
#pragma config PWRTE = OFF
#pragma config BOR4V = BOR21V
#pragma config WRT = OFF
/*
Register: CONFIG1 @ 0x2007

CPD =	Data Code Protection bit
OFF	Data memory code protection is disabled
ON	Data memory code protection is enabled
BOREN =	Brown Out Reset Selection bits
OFF	BOR disabled
ON	BOR enabled
NSLEEP	BOR enabled during operation and disabled in Sleep
SBODEN	BOR controlled by SBOREN bit of the PCON register
IESO =	Internal External Switchover bit
OFF	Internal/External Switchover mode is disabled
ON	Internal/External Switchover mode is enabled
DEBUG =	In-Circuit Debugger Mode bit
OFF	In-Circuit Debugger disabled, RB6/ICSPCLK and RB7/ICSPDAT are general purpose I/O pins
ON	In_Circuit Debugger enabled, RB6/ICSPCLK and RB7/ICSPDAT are dedicated to the debugger
FOSC =	Oscillator Selection bits
INTRC_NOCLKOUT	INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN
XT	XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN
LP	LP oscillator: Low-power crystal on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN
INTRC_CLKOUT	INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN
EXTRC_CLKOUT	RC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN
EXTRC_NOCLKOUT	RCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN
EC	EC: I/O function on RA6/OSC2/CLKOUT pin, CLKIN on RA7/OSC1/CLKIN
HS	HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN
FCMEN =	Fail-Safe Clock Monitor Enabled bit
OFF	Fail-Safe Clock Monitor is disabled
ON	Fail-Safe Clock Monitor is enabled
MCLRE =	RE3/MCLR pin function select bit
OFF	RE3/MCLR pin function is digital input, MCLR internally tied to VDD
ON	RE3/MCLR pin function is MCLR
WDTE =	Watchdog Timer Enable bit
OFF	WDT disabled and can be enabled by SWDTEN bit of the WDTCON register
ON	WDT enabled
CP =	Code Protection bit
OFF	Program memory code protection is disabled
ON	Program memory code protection is enabled
LVP =	Low Voltage Programming Enable bit
OFF	RB3 pin has digital I/O, HV on MCLR must be used for programming
ON	RB3/PGM pin has PGM function, low voltage programming enabled
PWRTE =	Power-up Timer Enable bit
OFF	PWRT disabled
ON	PWRT enabled
Register: CONFIG2 @ 0x2008

BOR4V =	Brown-out Reset Selection bit
BOR40V	Brown-out Reset set to 4.0V
BOR21V	Brown-out Reset set to 2.1V
WRT =	Flash Program Memory Self Write Enable bits
HALF	0000h to 0FFFh write protected, 1000h to 1FFFh may be modified by EECON control
OFF	Write protection off
1FOURTH	0000h to 07FFh write protected, 0800h to 1FFFh may be modified by EECON control
256	0000h to 00FFh write protected, 0100h to 1FFFh may be modified by EECON control
*/

#else                               //no chip identified
//no header file found
#warning no device header file specified in config.h
#endif

#endif	/* CONFIG_H */

