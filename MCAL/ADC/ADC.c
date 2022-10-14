/*
 * ADC.c
 *
 * Created: 12-Oct-22 11:48:12 PM
 * Author : Mahmoud Ahmed
 */ 

#include "ADC.h"

void ADC_enableInterrupt(void)
{
	ADCSRA |= (1<<ADIE);
}

void ADC_init(u8 pin, u8 source, u8 prescaler)
{
	ADMUX = pin;
	ADCSRA = prescaler;
	switch(source)
	{
		case 0:
		ADMUX |= (3<<6);
		break;
		case 1:
		ADMUX |= (1<<6);
		ADMUX &= ~(1<<7);
		break;
		case 2:
		ADMUX &= ~(3<<6);
		break;
	}
}

void ADC_start(u8 mode)
{
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADSC);
	if (mode == FREE_RUNNING)
	{
		ADCSRA |= (1<<ADATE);
		SFIOR = 0x00;
	}
}

u16 ADC_read(void)
{
	return (ADCH<<7)+(ADCL);
}