/*
*******************************  C HEADER FILE  **********************************
** filename  : LGT8FX8D.H
** version  : 1.0 	
** date     : June 12, 2018
** 			  
**********************************************************************************
** All rights reserved.       
**********************************************************************************
VERSION HISTORY:
----------------
Version 	: 1.0
Date 		: June 12, 2013
Revised by 	: mBEDed µSystems.
*/

#ifndef _IOLGT8FX8D_H_
#define _IOLGT8FX8D_H_

#define AC1SR (*((volatile unsigned char *)0x2F))
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define AC1BG 6
#define AC1D 7

#define AFTCNT1 (*((volatile unsigned char *)0x30))
#define DAL1 (*((volatile unsigned char *)0x31))

#define OP1CRA (*((volatile unsigned char *)0x32))
#define CH0EN 0
#define CH1EN 1
#define CH0IM 2 
#define CH1IM 3
#define ACFEN 5
#define ACCH  6
#define OP1EN 7

#define OP1CRB (*((volatile unsigned char *)0x33))
#define OPTEN 7

#define OP1TCNT (*((volatile unsigned char *)0x34))

//PCIFR 
#define PCIF3 3

//EECR 
#define EEPM2 7

//SPSR 
#define DUAL 2

//Defining AC0SR for LGT8FX8D
#define AC0SR ACSR

#define AFTCNT0 (*((volatile unsigned char *)0x51))
#define DAL0	(*((volatile unsigned char *)0x52))

//MCUSR
#define OCDRF 4
#define SWDD 7

//MCUCR
#undef BODSE
#undef BODS
#define FPDEN 6
#define FWKEN 7

#define ECCR (*((volatile unsigned char *)0x56))
#define EC0 0
#define EC1 1
#define EEN 6
#define WEN 7

#define OP0CRA (*((volatile unsigned char *)0x58))
#define OP0CRB (*((volatile unsigned char *)0x59))
#define OP0TCNT (*((volatile unsigned char *)0x5A))

//CLKPR
#define CKOEN0 5
#define CKOEN1 6

#define VDTCR (*((volatile unsigned char *)0x62))
#define VDTEN   0
#define LVREN   1
#define VDTSEL0 2
#define VDTSEL1 3
#define SWRSTN  6
#define VDTCE   7

#define PRR1 (*((volatile unsigned char *)0x65))
#define PRPCI 1
#define PREFL 2
#define PRTIM3 3
#define PRWDT 5

//PCICR
#define PCIE3 3

//PCMSK1
#define PCINT15 7

#define PCMSK3 (*((volatile unsigned char *)0x73))
#define PCINT24 0
#define PCINT25 1
#define PCINT26 2
#define PCINT27 3
#define PCINT28 4
#define PCINT29 5
#define PCINT30 6

#define IVBASE (*((volatile unsigned char *)0x75))

//LGT8FX8D has multiple ACME
#if defined(ADCSRB) && defined(ACME)
#undef ACME
#define ACME10 4
#define ACME11 5
#define ACME00 6
#define ACME01 7
#endif


#define ADTMR (*((volatile unsigned char *)0x7D))
#define ADTM 0

//DIDR0
#define ADC6D 6
#define ADC7D 7

//DIDR1
#define AIN2D 2
#define AIN3D 3
#define OPA0D 4
#define OPA1D 5
#define OPA2D 6
#define OPA3D 7

#define PINE (*((volatile unsigned char *)0xA7))
#define PINE0 0
#define PINE1 1
#define PINE2 2
#define PINE3 3
#define PINE4 4
#define PINE5 5
#define PINE6 6
#define PINE7 7

#define DDRE (*((volatile unsigned char *)0xA8))
#define DDE0 0
#define DDE1 1
#define DDE2 2
#define DDE3 3
#define DDE4 4
#define DDE5 5
#define DDE6 6
#define DDE7 7

#define PORTE (*((volatile unsigned char *)0xA9))
#define PORTE0 0
#define PORTE1 1
#define PORTE2 2
#define PORTE3 3
#define PORTE4 4
#define PORTE5 5
#define PORTE6 6 
#define PORTE7 7

#define	VCAL (*((volatile unsigned char *)0xC8))
#define	VCAL1 (*((volatile unsigned char *)0xCD))
#define VCAL2 (*((volatile unsigned char *)0xCE))

#define LDOCR (*((volatile unsigned char *)0xCF))
#define VSEL0 0
#define VSEL1 1
#define VSEL2 2
#define PDEN 3
#define WEN 7

#define PSSR (*((volatile unsigned char *)0xE2))
#define PSR1 0
#define PSS1 7

#define TCKSR (*((volatile unsigned char *)0xEC))
#define TC2XS0 0
#define TC2XS1 1
#define AFCKS 3
#define TC2XF0 4
#define TC2XF1 5
#define F2XEN 6

#define PMXCR (*((volatile unsigned char *)0xEE))

#define IOCR (*((volatile unsigned char *)0xF0))
#define RSTIOEN 0
#define REFIOEN 1
#define XIEN 2
#define DACEN0 3
#define DACEN1 4
#define STOSC0 5
#define STOSC1 6
#define IOCE 7

#define PMCR (*((volatile unsigned char *)0xF2))
#define RCMEN 0
#define RCKEN 1
#define OSCMEN 2
#define OSCKEN 3
#define WCLKS 4
#define CLKSS 5
#define CLKFS 6
#define PMCE 7

#define GUID0 (*((volatile unsigned char *)0xF3))
#define GUID1 (*((volatile unsigned char *)0xF4))
#define GUID2 (*((volatile unsigned char *)0xF5))
#define GUID3 (*((volatile unsigned char *)0xF6))

#endif





