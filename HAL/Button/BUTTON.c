/*
 * BUTTON.c
 *
 * Created: 11-Dec-22 9:56:05 AM
 *  Author: Mahmoud Ahmed
 */ 

#include "BUTTON.h"

uint8_t BUTTON_init (ST_Button_t* button)
{
	return DIO_initPin(button->port, button->pin, INPUT);
}

uint8_t BUTTON_read(ST_Button_t* button, uint8_t* value)
{
	return DIO_readPin(button->port, button->pin, value);
}
uint8_t BUTTON_interrupt(uint8_t pin, uint8_t mode)
{
	return EXINT_enable(pin, mode);
}