#ifndef Pins_mBEDed_h
#define Pins_mBEDed_h

#ifndef __LGT8FX8E__
#define	__LGT8FX8E__

//#include "lgtx8e.h"
#include "lgt8fx8d.h"
#endif 

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            20
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 20 : -1)

#if defined(__AVR_ATmega8__)
#define digitalPinHasPWM(p)         ((p) == 9 || (p) == 10 || (p) == 11)
#else
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 10 || (p) == 11)
#endif

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 24;
static const uint8_t SCL = 25;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 20;
static const uint8_t A1 = 21;
static const uint8_t A2 = 22;
static const uint8_t A3 = 23;
static const uint8_t A4 = 24;
static const uint8_t A5 = 25;
static const uint8_t A6 = 26;
static const uint8_t A7 = 27;

static const uint8_t DAC0 = 4;
static const uint8_t DAC1 = 19;

#if defined(__LGT8FX8E__)
#define E0	16
#define E1	26
#define E2	17
#define E3	27
#define E4	18
#define E5	19

static const uint8_t VCCM = 22;
static const uint8_t AOFF = 24;
static const uint8_t AIVR = 28;
static const uint8_t AGND = 29;
#endif


#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+
//
// (PWM+ indicates the additional PWM pins on the ATmega168.)


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD,	/* 0 */
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PB, /* 8 */
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PB,
	PE, /* 16 */
	PE,
	PE,
	PE,
	PC, /* 20 */
	PC,
	PC,
	PC,
	PC,
	PC,
	PE, /* 26 ADC6 - PE1*/
	PE, /* 27 ADC7 - PE3*/
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), /* 0, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 8, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 16, port E */
	_BV(2),
	_BV(4),
	_BV(5),
	_BV(0), /* 20, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(1), /* 26, port E */
	_BV(3), /* 27, port E */ 
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, /* 0 - port D */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	// on the ATmega168, digital pin 3 has hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER,
#else
	TIMER2B,
#endif
#if defined(__LGT8FX8E__)
	LGTDAO0,
#else
	NOT_ON_TIMER,
#endif
	// on the ATmega168, digital pins 5 and 6 have hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER,
	NOT_ON_TIMER,
#else
	TIMER0B,
	TIMER0A,
#endif
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 8 - port B */
	TIMER1A,
	TIMER1B,
#if defined(__AVR_ATmega8__)
	TIMER2,
#else
	TIMER2A,
#endif
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,  /* PB7 */
	NOT_ON_TIMER,  /* PE */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
#if defined(__LGT8FX8E__)
	LGTDAO1,
#else
	NOT_ON_TIMER,
#endif
	NOT_ON_TIMER, /* 16 - port C */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif

#endif
