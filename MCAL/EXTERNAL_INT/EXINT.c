/*
 * EXTERNAL_INT.c
 *
 * Created: 11-Oct-22 3:56:45 PM
 * Author : Mahmoud Ahmed
 */ 

#include "EXINT.h"

void EXINT_enable(u8 pin, u8 mode)
{
	GICR |= (1<<pin);
	MCUCR |= (mode<<((pin-6)*2));
}

void EXINT_disable(u8 pin)
{
	GICR &= ~(1<<pin);
}

u8 EXINT_readFlag(u8 pin)
{
	if ((GIFR & (1<<pin)) == 0x00)
		return 0;
	else
		return 1;
}