//PICduino code base for PIC10/12/16/18 chips

#include "picduino_config.h"				//configuration words - for XC8
#include "picduino.h"						//PICduino-related definitions / prototypes

//global variables

//global variables
//for time base off TIMER1 @ 1:1 prescaler
//volatile uint32_t timer1_millis = 0;
volatile uint32_t timer_ticks = 0;
//static uint16_t timer1_fract = 0;

//timer1 overflow isr
//void _ISR _T1Interrupt(void) {
void interrupt isr(void) {
	if (T0IF) {
		T0IF = 0;							//_T1IF=0;							//clear tmr1 interrupt flag
		timer_ticks+=0x100ul;				//increment overflow count: 8-bit timer
	}	
}

//declare pins
//ALL PINS ARE MAPPED, WHETHER THEY EXIST OR NOT
//SO MAKE SURE THAT THE PINS YOU PICKED ACTUALLY EXIST FOR YOUR PACKAGE
//Pin  0.. 7 -> GPIOA
//Pin  8..15 -> GPIOB
//Pin 16..23 -> GPIOC
//Pin 24..31 -> GPIOD
//Pin 32..39 -> GPIOE
//Pin 40..47 -> GPIOF
//Pin 48..55 -> GPIOG
//Pin 56..63 -> GPIOH
//Pin 64..71 -> GPIOI
const PIN2GPIO GPIO_PinDef[]={
#if defined(USE_GPIO)
	{&GPIO, &TRISIO, 1<<0},						//PICduino Pin  0 = RP0/PB0/CHIP PIN4
	{&GPIO, &TRISIO, 1<<1},						//PICduino Pin  1 = RP1/PB1/CHIP PIN5
	{&GPIO, &TRISIO, 1<<2},						//PICduino Pin  2 = RP2/PB2/CHIP PIN6
	{&GPIO, &TRISIO, 1<<3},						//PICduino Pin  3 = RP3/PB3/CHIP PIN7
	{&GPIO, &TRISIO, 1<<4},						//PICduino Pin  4 = RP4/PB4/CHIP PIN11
	{&GPIO, &TRISIO, 1<<5},						//PICduino Pin  5 = RP5/PB5/CHIP PIN14
	{&GPIO, &TRISIO, 1<<6},						//PICduino Pin  6 = RP6/PB6/CHIP PIN15
	{&GPIO, &TRISIO, 1<<7},						//PICduino Pin  7 = RP7/PB7/CHIP PIN16
#endif
#if defined(USE_PORTA)
	{&PORTA, &TRISA, 1<<0},						//PICduino Pin 16 = RP0/PB0/CHIP PIN4
	{&PORTA, &TRISA, 1<<1},						//PICduino Pin 17 = RP1/PB1/CHIP PIN5
	{&PORTA, &TRISA, 1<<2},						//PICduino Pin 18 = RP2/PB2/CHIP PIN6
	{&PORTA, &TRISA, 1<<3},						//PICduino Pin 19 = RP3/PB3/CHIP PIN7
	{&PORTA, &TRISA, 1<<4},						//PICduino Pin 20 = RP4/PB4/CHIP PIN11
	{&PORTA, &TRISA, 1<<5},						//PICduino Pin 21 = RP5/PB5/CHIP PIN14
	{&PORTA, &TRISA, 1<<6},						//PICduino Pin 22 = RP6/PB6/CHIP PIN15
	{&PORTA, &TRISA, 1<<7},						//PICduino Pin 23 = RP7/PB7/CHIP PIN16
#endif
#if defined(USE_PORTB)
	{&PORTB, &TRISB, 1<<0},						//PICduino Pin 16 = RP0/PB0/CHIP PIN4
	{&PORTB, &TRISB, 1<<1},						//PICduino Pin 17 = RP1/PB1/CHIP PIN5
	{&PORTB, &TRISB, 1<<2},						//PICduino Pin 18 = RP2/PB2/CHIP PIN6
	{&PORTB, &TRISB, 1<<3},						//PICduino Pin 19 = RP3/PB3/CHIP PIN7
	{&PORTB, &TRISB, 1<<4},						//PICduino Pin 20 = RP4/PB4/CHIP PIN11
	{&PORTB, &TRISB, 1<<5},						//PICduino Pin 21 = RP5/PB5/CHIP PIN14
	{&PORTB, &TRISB, 1<<6},						//PICduino Pin 22 = RP6/PB6/CHIP PIN15
	{&PORTB, &TRISB, 1<<7},						//PICduino Pin 23 = RP7/PB7/CHIP PIN16
#endif
#if defined(USE_PORTC)
	{&PORTC, &TRISC, 1<<0},						//PICduino Pin 32 = RP0/PB0/CHIP PIN4
	{&PORTC, &TRISC, 1<<1},						//PICduino Pin 33 = RP1/PB1/CHIP PIN5
	{&PORTC, &TRISC, 1<<2},						//PICduino Pin 34 = RP2/PB2/CHIP PIN6
	{&PORTC, &TRISC, 1<<3},						//PICduino Pin 35 = RP3/PB3/CHIP PIN7
	{&PORTC, &TRISC, 1<<4},						//PICduino Pin 36 = RP4/PB4/CHIP PIN11
	{&PORTC, &TRISC, 1<<5},						//PICduino Pin 37 = RP5/PB5/CHIP PIN14
	{&PORTC, &TRISC, 1<<6},						//PICduino Pin 38 = RP6/PB6/CHIP PIN15
	{&PORTC, &TRISC, 1<<7},						//PICduino Pin 39 = RP7/PB7/CHIP PIN16
#endif
#if defined(USE_PORTD)
	{&PORTD, &TRISD, 1<<0},						//PICduino Pin 16 = RP0/PB0/CHIP PIN4
	{&PORTD, &TRISD, 1<<1},						//PICduino Pin 17 = RP1/PB1/CHIP PIN5
	{&PORTD, &TRISD, 1<<2},						//PICduino Pin 18 = RP2/PB2/CHIP PIN6
	{&PORTD, &TRISD, 1<<3},						//PICduino Pin 19 = RP3/PB3/CHIP PIN7
	{&PORTD, &TRISD, 1<<4},						//PICduino Pin 20 = RP4/PB4/CHIP PIN11
	{&PORTD, &TRISD, 1<<5},						//PICduino Pin 21 = RP5/PB5/CHIP PIN14
	{&PORTD, &TRISD, 1<<6},						//PICduino Pin 22 = RP6/PB6/CHIP PIN15
	{&PORTD, &TRISD, 1<<7},						//PICduino Pin 23 = RP7/PB7/CHIP PIN16
#endif
};


	
//Arduino Functions: GPIO
//set a pin mode to INPUT or OUTPUT
//no error checking on PIN
void pinMode(PIN_TypeDef pin, uint8_t mode) {
	if (mode==INPUT) IO_IN(*(GPIO_PinDef[pin].ddr), GPIO_PinDef[pin].mask);
	else IO_OUT(*(GPIO_PinDef[pin].ddr), GPIO_PinDef[pin].mask);
}

//set / clear a pin
inline void digitalWrite(PIN_TypeDef pin, uint8_t val) {
	if (val==LOW) IO_CLR(*(GPIO_PinDef[pin].port), GPIO_PinDef[pin].mask);
	else IO_SET(*(GPIO_PinDef[pin].port), GPIO_PinDef[pin].mask);
}

//read a pin
inline uint8_t digitalRead(PIN_TypeDef pin) {
	return (IO_GET(*(GPIO_PinDef[pin].port), GPIO_PinDef[pin].mask))?HIGH:LOW;
}
//end GPIO

//Arduino Functions: Time
//return timer ticks
uint32_t ticks(void) {
	uint32_t m;
	uint8_t f;
	
	do {
		m = timer_ticks;
		f = TMR0;
	} while (m != timer_ticks);
	//now m and f are consistent
	return (m | f) << 8;				//corrected for prescaler
}		

//return microseconds
uint32_t micros(void) {
	uint32_t m;					//stores overflow count
	uint8_t f;					//return the fractions / TMR1 value
	
	//use double reads
	do {
		m = timer_ticks;
		f = TMR0;
	} while (m != timer_ticks);
	//now m and f are consistent
	return ((m | f) / clockCyclesPerMicrosecond()) << 8;
}
	
//return milliseconds
//alternatively, = micros()/1000
uint32_t millis(void) {
	uint32_t m;
	uint8_t f;
	
	//use double reads
	do {
		m = timer_ticks;
		f = TMR0;
	} while (m != timer_ticks);
		
	return ((m | f) / clockCyclesPerMillisecond());	//or shift 10 positions
}

//delay millisseconds
void delay(uint32_t ms) {
	uint32_t start_time = ticks();
	ms *= clockCyclesPerMillisecond();
	while (ticks() - start_time < ms) continue;
}

//delay micros seconds
void delayMicroseconds(uint32_t us) {
	uint32_t start_time = ticks();
	us *= clockCyclesPerMicrosecond();
	while (ticks() - start_time < us) continue;
}
//end Time


//Arduino Functions: Advanced IO
//shift in - from arduino code base / not optimized
uint8_t shiftIn(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder) {
	uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		digitalWrite(clockPin, HIGH);
		if (bitOrder == LSBFIRST)
			value |= digitalRead(dataPin) << i;
		else
			value |= digitalRead(dataPin) << (7 - i);
		digitalWrite(clockPin, LOW);
	}
	return value;
}

//shift out - from arduino code base / not optimized
void shiftOut(PIN_TypeDef dataPin, PIN_TypeDef clockPin, uint8_t bitOrder, uint8_t val) {
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}

//wait for a pulse and return timing
uint32_t pulseIn(PIN_TypeDef pin, uint8_t state) {
	uint32_t tmp;
	state = (state == LOW)?LOW:HIGH;				
	while (digitalRead(pin) == state) continue;		//wait for the pin to opposite
	//now pin is _state
	tmp = micros();
	state = (state == LOW)?HIGH:LOW;				//calculate the state to end the wait
	while (digitalRead(pin) == state) continue;		//wait for the pin to go back to its original state
	tmp = micros() - tmp;							//calculate the pulse width
	return tmp;
}
//end Advanced IO

//reset the mcu
//start timer1 at 1:1 prescaler
void mcu_init(void) {
	//set the clock bits if so desired
	
	//initialize pins into gpio mode
#if 	defined(_12F629)	|| defined(_12F675)
	CMCON = 0x07;						//turn off analog comparator
	ANSEL = 0x00;						//all pins gpio
#elif 	defined(_16F684)
	ANSEL = 0x00;						//porta are digital io
	//ANSELH = 0x00;					//all portB is digital io
	CM2=CM1=CM0=1;						//CMCON0 = 0x07;						//analog comparators off

	IRCF2 = 1, IRCF1 = 0, IRCF0 = 1;	//0b111->16Mhz, 0b101->4Mhz, ircf2..0=0b011 -> 1Mhz
#elif	defined(_16F882)	|| defined(_16F883)	|| defined(_16F884)	|| defined(_16F886)	|| defined(_16F887)

	ANSEL = ANSELH = 0;					//all ports digital
	C1ON = 0;							//CM1CON0 = 0x00;						//turn off comparator 1
	C2ON = 0;							//CM2CON0 = 0x00;						//turn off comparator 2
	IRCF2 = 1, IRCF1 = 1, IRCF0 = 0;	//0b110 = 4Mhz.
#endif

	//initialize timer1 as time base
	//initialize timer_ticks
	timer_ticks=0;
	
	//configure timer0 as time base
	T0CS = 0;							//use internal clock = Fosc / 4
	PSA = 0;						//prescaler assigned to tmr0

//	tmr0 prescaler bits in OPTION_REG - on most chips
	PS2=PS1=PS0=1;					//0b111->prescaler = 256:1

	//tmr0_offset=-period;				//update tmr0_period
	TMR0 = 0;							//tmr0_offset;					//set the period

	T0IF = 0;							//clera the flag
	T0IE = 1;							//enable timer0 interrupt
	
	//enable all interrupts
	interrupts();
}

//templated code for main()
int main(void) {
	mcu_init();							//reset the chip
	setup();							//user-set up the code
	while (1) {
		loop();							//user specified loop
	}
	return 0;
}
