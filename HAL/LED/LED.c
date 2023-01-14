/*
 * LED.c
 *
 * Created: 11-Dec-22 9:55:33 AM
 *  Author: Mahmoud Ahmed Ibrahim
 */ 

#include "LED.h"
#include "../../MCAL/DIO/DIO_Interface.h"

uint8_t LED_init (ST_Led_t* LED)
{
	return DIO_initPin(LED->port, LED->pin, OUTPUT);
}

uint8_t LED_turnON (ST_Led_t* LED)
{
	return DIO_setPinValue(LED->port, LED->pin, HIGH);
}

uint8_t LED_turnOFF (ST_Led_t* LED)
{
	return DIO_setPinValue(LED->port, LED->pin, LOW);	
}

uint8_t LED_toggle (ST_Led_t* LED)
{
	return DIO_togglePin(LED->port, LED->pin);	
}

uint8_t LED_read(ST_Led_t* LED, uint8_t* value)
{
	return DIO_readPin(LED->port, LED->pin, value);
}
