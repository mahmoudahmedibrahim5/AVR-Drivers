/*
 * TIMER0.c
 *
 * Created: 13-Oct-22 10:42:04 AM
 * Author : Mahmoud Ahmed
 */ 

#include "TIMER0.h"

void TIMER0_enable(u8 Register) // Register is TOIE0 or OCIE0
{
	// Enabling Output compare interrupt without writing in it causes some problems
	// So, don't Enable it if you won't use it 
	TIMSK |= (1<<Register);
}

u8 read_Flag(u8 flag) // flag is TOV0 or OCF0
{
	u8 flag_Value;
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

void TIMER0_init(u8 mode, u8 initial_Value, u8 prescaler)
{
	TCNT0 = initial_Value;
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

void TIMER0_updateInitialValue(u8 initial_Value)
{
	TCNT0 = initial_Value;
}

void TIMER0_compOut(u8 mode, u8 value)
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

void TIMER0_setDutyCycle(u8 compare_Value)
{
	OCR0 = compare_Value;
}

