/*
 * TIMER0_Program.c
 *
 * Created: 11-Dec-22 9:54:31 AM
 *  Author: Mahmoud Ahmed Ibrahim
 */ 

#include "TIMER0_Registers.h"
#include "TIMER0_Interface.h"

uint32_t rest;

void TIMER0_init(uint8_t mode)
{
	switch (mode)
	{
		case NORMAL_MODE:
			TCCR0 &= ~(1<<3);
			TCCR0 &= ~(1<<6);
			break;
		case CLEAR_TIMER_ON_COMPARE_MATCH_MODE:
			TCCR0 |= (1<<3);
			TCCR0 &= ~(1<<6);
			break;
		case FAST_PWM_MODE: 
			TCCR0 |= (1<<3);
			TCCR0 |= (1<<6);
			break;
		case PHASE_CORRECT_MODE:
			TCCR0 &= ~(1<<3);
			TCCR0 |= (1<<6);
			break;
	}
}

void TIMER0_setInitialValue(uint8_t initial_Value)
{
	TCNT0 = initial_Value;
}

void TIMER0_setPrescaler(uint8_t prescaler)
{
	switch(prescaler)
	{
		case prescaler1:
		TCCR0 |= 0x01;
		break;
		case prescaler8:
		TCCR0 |= 0x02;
		break;
		case prescaler64:
		TCCR0 |= 0x03;
		break;
		case prescaler256:
		TCCR0 |= 0x04;
		break;
		case prescaler1024:
		TCCR0 |= 0x05;
		break;
	}
}

void TIMER0_delay_ms(uint32_t miliSeconds)
{
	TIMER0_init(NORMAL_MODE);
	rest = miliSeconds;
	while(rest > 0)
	{
		TIMER0_setInitialValue(0x83);
		TIMER0_setPrescaler(prescaler8);
		while(read_Flag(TOV0)==0);
		TIFR |= (1<<TOV0);
		rest--;
	}
}


uint8_t read_Flag(uint8_t flag) // flag is TOV0 or OCF0
{
	uint8_t flag_Value;
	if ((TIFR & (1<<flag)) == 0x00)
	{
		flag_Value = 0;
	}
	else
	{
		flag_Value = 1;
	}
	return flag_Value;
}

void TIMER0_compOut(uint8_t mode, uint8_t value)
{	
	/* 
	 * These four modes are suitable for PWM and NON-PWM Modes, but they are named by NON-PWM Modes names.
	 * For example if You pass NON_INVERTIG_MODE to this function it will enter case 2 which is named by CLR_MODE. 
	 */
	OCR0 = value;
	switch(mode)
	{
		case NORMAL_MODE:
		TCCR0 &= ~(1<<4);
		TCCR0 &= ~(1<<5);
		break;
		case TOGGLE_MODE:
		TCCR0 |= (1<<4);
		TCCR0 &= ~(1<<5);
		break;
		case CLR_MODE:
		TCCR0 &= ~(1<<4);
		TCCR0 |= (1<<5);
		break;
		case SET_MODE:
		TCCR0 |= (1<<4);
		TCCR0 |= (1<<5);
		break;
	}
}

void TIMER0_setDutyCycle(uint8_t compare_Value)
{
	OCR0 = compare_Value;
}