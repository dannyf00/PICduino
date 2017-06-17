//PICduino GPIO functions for PIC10/12/16/18-family chips
//compiler: XC8 (developed and tested under v1.12)
//
//version: 0.10
//6/17/2017: initial release, based on PIC32duino v0.11
//supported device list: 
//PIC10: 
//PIC12: 12F629/12F675, 
//PIC16: 16F684, 16F882/883/884/886/887
//PIC18: 
//
//arduino functions supported:
//GPIO: pinMode(), digitalWrite(), digitalRead()
//Timing: millis(), micros(), delay(), delayMicroseconds()
//Advanced IO: shiftOut(), shiftIn()
//Math: min(), max(), abs(), constrain(), map(), pow(), sqrt()
//Trigonometry: sin(), cos(), tan()
//Bits and Bytes: lowByte(), highByte(), bitRead(), bitWrite(), bitSet(), bitClear(), bit()
//Interrupts: interrupts(), noInterrupts()
//Random Numbers: randomSeed(), random(max). random(min, max) mapped to random2(min, max)
//Characters: isAlphaNumeric(), isAlpha(), isAscii(), isWhitespace(), isControl(), isDigit(), isGraph(), isLowerCase(), isPrintable(), isPunct(), isSpace(), isUpperCase(), isHexadeimalDigit()
//
//not yet implemented
//External Interrupts: attachInterrupt(), detachInterrupt()
//Advanced IO: tone(), noTone(), pulseIn()
//AnalogIO: analogReference(), analogRead(), analogWrite()

#ifndef __PICDUINO_H
#define __PICDUINO_H

#include <xc.h>										//we use XC16
#include <stdint.h>									//standard types
#include <stdlib.h>									//we use rand()

//PICduino configuration
#define USE_GPIO									//uncomment if GPIO is available / used
//#define USE_PORTA									//uncomment if PORTA is available / used
//#define USE_PORTB									//uncomment if PORTA is available / used
//#define USE_PORTC									//uncomment if PORTA is available / used
//#define USE_PORTD									//uncomment if PORTA is available / used
//end PIC32duino configuration

//global definitions
#ifndef F_CPU										//allows user specified F_CPU in the IDE
#define F_CPU					(8000000ul/4)			//cpu runs at 8Mhz and F_CPU = 8Mhz / 4
#endif

//port manipulation macros for PIC.
//port manipulation macros - register-based
#define IO_SET(port, bits)	port |= (bits)			//set bits on port
#define IO_CLR(port, bits)	port &=~(bits)			//clear bits on port
#define IO_FLP(port, bits)	port ^= (bits)			//flip bits on port
#define IO_GET(port, bits)	((port) & (bits))		//return bits on port
#define IO_OUT(ddr, bits)	ddr &=~(bits)			//set bits as output
#define IO_IN(ddr, bits)	ddr |= (bits)			//set bits as input

//gpio definitions - GPIO-based
#define GIO_SET(gpio, bits)	IO_SET(gpio->LAT, bits)		//gpio->LAT |= (bits)			//set bits on gpio
#define GIO_CLR(gpio, bits)	IO_CLR(gpio->LAT, bits)		//gpio->LAT &=~(bits)			//clear bits on gpio
#define GIO_FLP(gpio, bits)	IO_FLP(gpio->LAT, bits)		//gpio->LAT ^= (bits)			//flip bits on gpio
#define GIO_GET(gpio, bits)	IO_GET(gpio->PORT, bits)	//((gpio->PORT) & (bits))		//return bits on gpio
#define GIO_OUT(gpio, bits)	IO_OUT(gpio->TRIS, bits)	//ddr->TRIS &=~(bits)			//set bits as output
#define GIO_IN(gpio, bits)	IO_IN(gpio->TRIS, bits)		//ddr->TRIS |= (bits)			//set bits as input


#ifndef NOP
	#define NOP()			asm("nop")				//nop()
#endif
#define NOP2()				{NOP(); NOP();}
#define NOP4()				{NOP2(); NOP2();}
#define NOP8()				{NOP4(); NOP4();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP16()				{NOP8(); NOP8();}
#define NOP24()				{NOP16(); NOP8();}
#define NOP32()				{NOP16(); NOP16();}
#define NOP40()				{NOP32(); NOP8();}

//interrupts
#ifndef ei
	#define ei()			{GIE=1;}				//enable interrupt
#endif

#ifndef di
	#define di()			{GIE=0;}				//disable interrupt
#endif

//reset the mcu
void mcu_init();									//reset the mcu



//pin enum - matches GPIO_PinDef[]
typedef enum {
#if defined(USE_GPIO)
	PIO0, PIO1, PIO2, PIO3, PIO4, PIO5, PIO6, PIO7, //PIO8, PIO9, PIO10, PIO11, PIO12, PIO13, PIO14, PIO15,
#endif
#if defined(USE_PORTA)
	PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, //PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
#endif
#if defined(USE_PORTB)
	PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, //PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
#endif
#if defined(USE_PORTC)
	PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, //PC8, PC9, PC10, PC11, PC12, PC13, PC14, PC15,
#endif
#if defined(USE_PORTD)
	PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7, //PD8, PD9, PD10, PD11, PD12, PD13, PD14, PD15,
#endif
	PMAX
} PIN_TypeDef;

//map pin number to GPIOx
typedef struct {
	volatile uint8_t *port;				//gpio for a pin
	volatile uint8_t *ddr;				//trisio register
	uint8_t mask;						//pin mask - 16-bit port
} PIN2GPIO;
	
#define INPUT				0
#define OUTPUT				1			//(!INPUT)
#define INPUT_PULLUP		2

#define LOW					0
#define HIGH				1			//(!LOW)

#define PI 					3.1415926535897932384626433832795
#define HALF_PI 			(PI / 2)							//1.5707963267948966192313216916398
#define TWO_PI 				(PI + PI)							//6.283185307179586476925286766559
#define DEG_TO_RAD 			(TWO_PI / 360)						//0.017453292519943295769236907684886
#define RAD_TO_DEG 			(360 / TWO_PI)						//57.295779513082320876798154814105
#define EULER 				2.718281828459045235360287471352	//Euler's number

#define SERIAL  			0x0
#define DISPLAY 			0x1

#define LSBFIRST 			0
#define MSBFIRST 			1									//(!LSBFIRST)							//1

#define CHANGE 				1
#define FALLING 			2
#define RISING 				3

#ifndef min
#define min(a,b) 			((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) 			((a)>(b)?(a):(b))
#endif
#define abs(x) 				((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     		((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) 		((deg)*DEG_TO_RAD)
#define degrees(rad) 		((rad)*RAD_TO_DEG)
#define sq(x) 				((x)*(x))

#define interrupts() 		ei()
#define noInterrupts() 		di()

#define clockCyclesPerMillisecond() 	( F_CPU / 1000L )
#define clockCyclesPerMicrosecond() 	( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) 	( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) 	( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) 			((uint8_t) ((w) & 0xff))
#define highByte(w) 		((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) 	((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(n)				(1ul<<(n))

#define false				0
#define true				(!false)

//characters
#define isAlphaNumeric(c)	isalnum(c)
#define isAlpha(c)			isalpha(c)
#define isAscii(c)			isascii(c)
#define isWhitespace(c)		isblank(c)
#define isControl(c)		iscntrl(c)
#define isDigit(c)			isdigit(c)
#define isGraph(c)			isgraph(c)
#define isLowerCase(c)		islower(c)
#define isPrintable(c)		isprint(c)
#define isPunct(c)			ispunct(c)
#define isSpace(c)			isspace(c)
#define isUpperCase(c)		isupper(c)
#define isHexadecimalDigit(c)	isxdigit(c)

//external setup/loop - defined by user
extern void setup(void);
extern void loop(void);

//random number
#define randomSeed(seed)	srand(seed)
#define random(max)			random2(0, max)
#define random2(min, max)	((min) + (int32_t) ((max) - (min)) * rand() / 32768)

//GPIO
void pinMode(PIN_TypeDef pin, uint8_t mode);
inline void digitalWrite(PIN_TypeDef pin, uint8_t mode);
inline uint8_t digitalRead(PIN_TypeDef pin);

//time base
uint32_t ticks(void);
uint32_t millis(void);
uint32_t micros(void);
void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);

//advanced IO
//void tone(void);									//tone frequency specified by F_TONE in STM8Sduino.h
//void noTone(void);
//shiftin/out: bitOrder = MSBFIRST or LSBFIRST
uint8_t shiftIn(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder);
void shiftOut(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder, uint8_t val);
uint32_t pulseIn(PIN_TypeDef pin, uint8_t state);		//wait for a pulse and return timing

//pwm output
//dc = 0x00..0x0fff for pwm2/3/4/5, 0x00..0xffff for pwm1
//RP4=PWM1, RP12=PWM2, RP13=PWM3, RP14=PWM4, RP15=PWM5
//void analogWrite(uint8_t pin, uint16_t dc);

//analog read on ADC1
//read DRL first for right aligned results
//uint16_t analogRead(uint8_t pin);

//analog reference - default to AVdd-AVss
//Vref sources: 0->Vref = AVdd-AVss, 1->Vref+-AVss, 2->AVdd-Vref-, 3->Vref+ - Vref-
//void analogReference(uint8_t Vref);

//interrupts
//install external interrupt handler
//mode 1: falling edge, 0: rising edge
//void attachInterrupt(uint8_t intx, void (*isrptr) (void), uint8_t mode);
//void detachInterrupt(uint8_t intx);

//change notification interrupts
//install user CN interrupt handler
//void attachCNInterrupt(void (*isrptr) (void));
//void detachCNInterrupt(void);
//void activateCNInterrupt(uint8_t cnx, uint8_t pue);
//void deactivateCNInterrupt(uint8_t cnx);

#endif //gpio_h_
