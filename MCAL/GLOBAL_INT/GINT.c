/*
 * GLOBAL_INT.c
 *
 * Created: 08-Oct-22 2:40:38 PM
 * Author : Mahmoud Ahmed
 */ 

#include "GINT.h"

void GINT_Enable()
{
	SREG |= (1<<7);
}

void GINT_Disable()
{
	SREG &= ~(1<<7);
}