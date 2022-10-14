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
		case AREF:
			ADMUX &= ~(3<<6);
			break;
		case AVCC:
			ADMUX |= (1<<6);
			ADMUX &= ~(1<<7);
			break;
		case INTERNAL_REFERENCE:
			ADMUX |= (3<<6);
			break;
	}
}

void ADC_start(u8 mode)
{
	ADCSRA |= (1<<ADEN);
	if (mode == FREE_RUNNING)
	{
		ADCSRA |= (1<<ADATE);
		SFIOR &= 0x0F;
	}
	else if(mode == SINGLE_CONVERSION)
	{
		ADCSRA &= ~(1<<ADATE);
	}
	ADCSRA |= (1<<ADSC);
}

u16 ADC_read(void)
{
	
	u8 l = ADCL;
	u8 h = ADCH;
	u16 r = (h*256) + l;
	return r;
	
}