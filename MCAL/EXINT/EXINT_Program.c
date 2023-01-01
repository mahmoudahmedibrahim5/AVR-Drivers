/*
 * EXINT_Program.c
 *
 * Created: 11-Dec-22 1:27:11 PM
 *  Author: Mahmoud Ahmed
 */ 

#include "EXINT_Interface.h"

uint8_t EXINT_enable(uint8_t pin, uint8_t mode)
{
	// Set the mode
	if (pin == INT0 || pin == INT1)
		MCUCR |= (mode<<((pin-6)*2));
	else if(pin == INT2)
	{
		if (mode == FALLING_EDGE)
			MCUCSR &= ~(1<<6);
		else if(mode == RISING_EDGE)
			MCUCSR |= (1<<6);
		else
			return ERROR;
	}
	else
		return ERROR;
	// Enable the interrupt
	GICR |= (1<<pin);
	return OK;
}

uint8_t EXINT_disable(uint8_t pin)
{
	if (pin == INT0 || pin == INT1 || pin == INT2)
	{
		GICR &= ~(1<<pin);
		return OK;
	}
	else
		return ERROR;
}

uint8_t EXINT_readFlag(uint8_t pin, uint8_t *value)
{
	if (pin == INT0 || pin == INT1 || pin == INT2)
	{
		*value = (GIFR & (1<<pin))>>pin;
		return OK;
	}
	else
		return ERROR;
}


//void EXINT_setInterruptFunction(void (*func)(void))
//{
	//interruptFunction = func;
//}

//ISR(INT0_vect)
//{
	//interruptFunction();
//}