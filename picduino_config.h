#ifndef __PICDUINO_CONFIG_H
#define	__PICDUINO_CONFIG_H

//#include <p32xxxx.h>							//p32xxxx.h included here
#include <xc.h>

//configuration settings
//PIC12F629, PIC12F675
//PIC16F684
//PIC16f882, PIC16f883, PIC16F884, PIC16F886, PIC16F887
//PIC18f2455/2550/4455/4550
//PIC18f2458/2553/4458/4553

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

//18f2455/2550/4455/4550
//18f2458/2553/4458/4553
#elif	defined(_18F2455) || defined(_18F2550) || defined(_18F4455) || defined(_18F4550) || \
		defined(_18F2458) || defined(_18F2553) || defined(_18F4458) || defined(_18F4553)

#pragma config CPUDIV = OSC1_PLL2
#pragma config PLLDIV = 5
#pragma config USBDIV = 2
#pragma config IESO = OFF
#pragma config FOSC = XT_XT
#pragma config FCMEN = OFF
/*
Register: CONFIG1L @ 0x300000

CPUDIV =	System Clock Postscaler Selection bits
OSC2_PLL3	[Primary Oscillator Src: /2][96 MHz PLL Src: /3]
OSC4_PLL6	[Primary Oscillator Src: /4][96 MHz PLL Src: /6]
OSC3_PLL4	[Primary Oscillator Src: /3][96 MHz PLL Src: /4]
OSC1_PLL2	[Primary Oscillator Src: /1][96 MHz PLL Src: /2]
PLLDIV =	PLL Prescaler Selection bits
1	No prescale (4 MHz oscillator input drives PLL directly)
5	Divide by 5 (20 MHz oscillator input)
12	Divide by 12 (48 MHz oscillator input)
2	Divide by 2 (8 MHz oscillator input)
6	Divide by 6 (24 MHz oscillator input)
3	Divide by 3 (12 MHz oscillator input)
10	Divide by 10 (40 MHz oscillator input)
4	Divide by 4 (16 MHz oscillator input)
USBDIV =	USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1)
1	USB clock source comes directly from the primary oscillator block with no postscale
2	USB clock source comes from the 96 MHz PLL divided by 2
Register: CONFIG1H @ 0x300001

IESO =	Internal/External Oscillator Switchover bit
OFF	Oscillator Switchover mode disabled
ON	Oscillator Switchover mode enabled
FOSC =	Oscillator Selection bits
INTOSC_EC	Internal oscillator, CLKO function on RA6, EC used by USB (INTCKO)
ECPLLIO_EC	EC oscillator, PLL enabled, port function on RA6 (ECPIO)
XT_XT	XT oscillator (XT)
INTOSC_HS	Internal oscillator, HS oscillator used by USB (INTHS)
ECPLL_EC	EC oscillator, PLL enabled, CLKO function on RA6 (ECPLL)
INTOSC_XT	Internal oscillator, XT used by USB (INTXT)
EC_EC	EC oscillator, CLKO function on RA6 (EC)
ECIO_EC	EC oscillator, port function on RA6 (ECIO)
XTPLL_XT	XT oscillator, PLL enabled (XTPLL)
HSPLL_HS	HS oscillator, PLL enabled (HSPLL)
HS	HS oscillator (HS)
INTOSCIO_EC	Internal oscillator, port function on RA6, EC used by USB (INTIO)
FCMEN =	Fail-Safe Clock Monitor Enable bit
OFF	Fail-Safe Clock Monitor disabled
ON	Fail-Safe Clock Monitor enabled
*/
#pragma config VREGEN = OFF
#pragma config BOR = OFF
#pragma config BORV = 3
#pragma config PWRT = ON
#pragma config WDTPS = 32768
#pragma config WDT = OFF
/*
Register: CONFIG2L @ 0x300002

VREGEN =	USB Voltage Regulator Enable bit
OFF	USB voltage regulator disabled
ON	USB voltage regulator enabled
BOR =	Brown-out Reset Enable bits
SOFT	Brown-out Reset enabled and controlled by software (SBOREN is enabled)
OFF	Brown-out Reset disabled in hardware and software
ON	Brown-out Reset enabled in hardware only (SBOREN is disabled)
ON_ACTIVE	Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
BORV =	Brown-out Reset Voltage bits
1	
2	
3	Minimum setting
0	Maximum setting
PWRT =	Power-up Timer Enable bit
OFF	PWRT disabled
ON	PWRT enabled
Register: CONFIG2H @ 0x300003

WDTPS =	Watchdog Timer Postscale Select bits
8	1:8
1	1:1
32768	1:32768
1024	1:1024
2	1:2
32	1:32
16	1:16
16384	1:16384
128	1:128
4096	1:4096
64	1:64
8192	1:8192
2048	1:2048
512	1:512
256	1:256
4	1:4
WDT =	Watchdog Timer Enable bit
OFF	WDT disabled (control is placed on the SWDTEN bit)
ON	WDT enabled
*/
#pragma config CCP2MX = OFF
#pragma config PBADEN = OFF
#pragma config LPT1OSC = OFF
#pragma config MCLRE = OFF
/*
Register: CONFIG3H @ 0x300005

CCP2MX =	CCP2 MUX bit
OFF	CCP2 input/output is multiplexed with RB3
ON	CCP2 input/output is multiplexed with RC1
PBADEN =	PORTB A/D Enable bit
OFF	PORTB<4:0> pins are configured as digital I/O on Reset
ON	PORTB<4:0> pins are configured as analog input channels on Reset
LPT1OSC =	Low-Power Timer 1 Oscillator Enable bit
OFF	Timer1 configured for higher power operation
ON	Timer1 configured for low-power operation
MCLRE =	MCLR Pin Enable bit
OFF	RE3 input pin enabled; MCLR pin disabled
ON	MCLR pin enabled; RE3 input pin disabled
*/
#pragma config DEBUG = OFF
#pragma config STVREN = OFF
#if	defined(_18F4455) || defined(_18F4550) || defined(_18F4458) || defined(_18F4553)
#pragma config ICPRT = OFF			//only for 18F4xxx chips
#endif
#pragma config XINST = OFF
#pragma config LVP = OFF
/*
Register: CONFIG4L @ 0x300006

DEBUG =	Background Debugger Enable bit
OFF	Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
ON	Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
STVREN =	Stack Full/Underflow Reset Enable bit
OFF	Stack full/underflow will not cause Reset
ON	Stack full/underflow will cause Reset
ICPRT =	Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit
OFF	ICPORT disabled
ON	ICPORT enabled
XINST =	Extended Instruction Set Enable bit
OFF	Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
ON	Instruction set extension and Indexed Addressing mode enabled
LVP =	Single-Supply ICSP Enable bit
OFF	Single-Supply ICSP disabled
ON	Single-Supply ICSP enabled
*/
#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF
#pragma config CPD = OFF
#pragma config CPB = OFF
/*
Register: CONFIG5L @ 0x300008

CP0 =	Code Protection bit
OFF	Block 0 (000800-001FFFh) is not code-protected
ON	Block 0 (000800-001FFFh) is code-protected
CP1 =	Code Protection bit
OFF	Block 1 (002000-003FFFh) is not code-protected
ON	Block 1 (002000-003FFFh) is code-protected
CP2 =	Code Protection bit
OFF	Block 2 (004000-005FFFh) is not code-protected
ON	Block 2 (004000-005FFFh) is code-protected
CP3 =	Code Protection bit
OFF	Block 3 (006000-007FFFh) is not code-protected
ON	Block 3 (006000-007FFFh) is code-protected
Register: CONFIG5H @ 0x300009

CPD =	Data EEPROM Code Protection bit
OFF	Data EEPROM is not code-protected
ON	Data EEPROM is code-protected
CPB =	Boot Block Code Protection bit
OFF	Boot block (000000-0007FFh) is not code-protected
ON	Boot block (000000-0007FFh) is code-protected
*/
#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF
#pragma config WRTB = OFF
#pragma config WRTC = OFF
#pragma config WRTD = OFF
/*
Register: CONFIG6L @ 0x30000A

WRT0 =	Write Protection bit
OFF	Block 0 (000800-001FFFh) is not write-protected
ON	Block 0 (000800-001FFFh) is write-protected
WRT1 =	Write Protection bit
OFF	Block 1 (002000-003FFFh) is not write-protected
ON	Block 1 (002000-003FFFh) is write-protected
WRT2 =	Write Protection bit
OFF	Block 2 (004000-005FFFh) is not write-protected
ON	Block 2 (004000-005FFFh) is write-protected
WRT3 =	Write Protection bit
OFF	Block 3 (006000-007FFFh) is not write-protected
ON	Block 3 (006000-007FFFh) is write-protected
Register: CONFIG6H @ 0x30000B

WRTB =	Boot Block Write Protection bit
OFF	Boot block (000000-0007FFh) is not write-protected
ON	Boot block (000000-0007FFh) is write-protected
WRTC =	Configuration Register Write Protection bit
OFF	Configuration registers (300000-3000FFh) are not write-protected
ON	Configuration registers (300000-3000FFh) are write-protected
WRTD =	Data EEPROM Write Protection bit
OFF	Data EEPROM is not write-protected
ON	Data EEPROM is write-protected
*/
#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF
#pragma config EBTRB = OFF
/*
Register: CONFIG7L @ 0x30000C

EBTR0 =	Table Read Protection bit
OFF	Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks
ON	Block 0 (000800-001FFFh) is protected from table reads executed in other blocks
EBTR1 =	Table Read Protection bit
OFF	Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks
ON	Block 1 (002000-003FFFh) is protected from table reads executed in other blocks
EBTR2 =	Table Read Protection bit
OFF	Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks
ON	Block 2 (004000-005FFFh) is protected from table reads executed in other blocks
EBTR3 =	Table Read Protection bit
OFF	Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks
ON	Block 3 (006000-007FFFh) is protected from table reads executed in other blocks
Register: CONFIG7H @ 0x30000D

EBTRB =	Boot Block Table Read Protection bit
OFF	Boot block (000000-0007FFh) is not protected from table reads executed in other blocks
ON	Boot block (000000-0007FFh) is protected from table reads executed in other blocks
*/
#else                               //no chip identified
//no header file found
#warning no device header file specified in config.h
#endif

#endif	/* CONFIG_H */

