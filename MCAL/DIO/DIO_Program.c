/*
 * DIO_Program.c
 *
 * Created: 09-Dec-22 7:26:24 PM
 *  Author: Mahmoud Ahmed
 */ 
#include "DIO_Interface.h"

/* Initialize the direction of certain pin Output or Input or Input Pull up */
uint8_t DIO_initPin(uint8_t port, uint8_t pin, uint8_t mode)
{
	// Check the mode of the pin Input, Input PullUp, Output
	if (mode == OUTPUT)
	{
		// Check which port
		switch (port)
		{
			// Write 1 in the bit corresponding to this pin in DDRx register
			case PORT_A: DDRA |= (1<<pin); break;
			case PORT_B: DDRB |= (1<<pin); break;
			case PORT_C: DDRC |= (1<<pin); break;
			case PORT_D: DDRD |= (1<<pin); break;
			default: return ERROR;
		}
	}
	else if (mode == INPUT)
	{
		// Check which port
		switch (port)
		{
			// Write 0 in the bit corresponding to this pin in DDRx register
			case PORT_A: DDRA &= ~(1<<pin); break;
			case PORT_B: DDRB &= ~(1<<pin); break;
			case PORT_C: DDRC &= ~(1<<pin); break;
			case PORT_D: DDRD &= ~(1<<pin); break;
			default: return ERROR;
		}
	}
	else if (mode == INPUT_PULLUP)
	{
		// Check which port
		switch (port)
		{
			// Write 1 in the bit corresponding to this pin in DDRx register
			// Write 1 in the bit corresponding to this pin in PORTx register
			case PORT_A: DDRA &= ~(1<<pin);
						 PORTA |= (1<<pin);
						 break;
			case PORT_B: DDRB &= ~(1<<pin);
						 PORTB |= (1<<pin);
						 break;
			case PORT_C: DDRC &= ~(1<<pin);
						 PORTC |= (1<<pin);
						 break;
			case PORT_D: DDRD &= ~(1<<pin);
						 PORTD |= (1<<pin);
						 break;
			default: return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}

/* Initialize the direction of certain port Output or Input or Input Pull up */
uint8_t DIO_initPort(uint8_t port, uint8_t mode)
{
	// Check the mode of the pin Input, Input PullUp, Output
	if (mode == OUTPUT)
	{
		// Check which port
		switch (port)
		{
			// Write 0xFF in DDRx register
			case PORT_A: DDRA = 0xFF; break;
			case PORT_B: DDRB = 0xFF; break;
			case PORT_C: DDRC = 0xFF; break;
			case PORT_D: DDRD = 0xFF; break;
			default: return ERROR;
		}
	}
	else if (mode == INPUT)
	{
		// Check which port
		switch (port)
		{
			// Write 0x00 in DDRx register
			case PORT_A: DDRA = 0x00; break;
			case PORT_B: DDRB = 0x00; break;
			case PORT_C: DDRC = 0x00; break;
			case PORT_D: DDRD = 0x00; break;
			default: return ERROR;
		}
	}
	else if (mode == INPUT_PULLUP)
	{
		// Check which port
		switch (port)
		{
			// Write 0x00 in DDRx register
			// Write 0xFF in PORTx register
			case PORT_A: DDRA = 0x00;
						 PORTA = 0xFF;
						 break;
			case PORT_B: DDRB = 0x00;
						 PORTB = 0xFF;
						 break;
			case PORT_C: DDRC= 0x00;
						 PORTC = 0xFF;
						 break;
			case PORT_D: DDRD = 0x00;
						 PORTD = 0xFF;
						 break;
			default: return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}

/* Output HIGH or LOW on certain pin */
uint8_t DIO_setPinValue(uint8_t port, uint8_t pin, uint8_t value)
{
	// Check the required output on the pin HIGH or LOW
	if (value == HIGH)
	{
		// Check which port
		switch (port)
		{
			// Write 1 in the bit corresponding to this pin in PORTx register
			case PORT_A: PORTA |= (1<<pin); break;
			case PORT_B: PORTB |= (1<<pin); break;
			case PORT_C: PORTC |= (1<<pin); break;
			case PORT_D: PORTD |= (1<<pin); break;
			default: return ERROR;
		}
	}
	else if (value == LOW)
	{
		// Check which port
		switch (port)
		{
			// Write 0 in the bit corresponding to this pin in PORTx register
			case PORT_A: PORTA &= ~(1<<pin); break;
			case PORT_B: PORTB &= ~(1<<pin); break;
			case PORT_C: PORTC &= ~(1<<pin); break;
			case PORT_D: PORTD &= ~(1<<pin); break;
			default: return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}

/* Output HIGH or LOW on certain port */
uint8_t DIO_setPortValue(uint8_t port, uint8_t value)
{
	// Check the required output on the port HIGH or LOW
	if (value == HIGH)
	{
		// Check which port
		switch (port)
		{
			// Write 0xFF in PORTx register
			case PORT_A: PORTA = 0xFF; break;
			case PORT_B: PORTB = 0xFF; break;
			case PORT_C: PORTC = 0xFF; break;
			case PORT_D: PORTD = 0xFF; break;
			default: return ERROR;
		}
	}
	else if (value == LOW)
	{
		// Check which port
		switch (port)
		{
			// Write 0x00 in PORTx register
			case PORT_A: PORTA = 0x00; break;
			case PORT_B: PORTB = 0x00; break;
			case PORT_C: PORTC = 0x00; break;
			case PORT_D: PORTD = 0x00; break;
			default: return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
	return OK;
}

uint8_t DIO_togglePin(uint8_t port, uint8_t pin)
{
	// Check which port
	switch (port)
	{
		// Toggle the bit corresponding to this pin in PORTx register
		case PORT_A: PORTA ^= (1<<pin); break;
		case PORT_B: PORTB ^= (1<<pin); break;
		case PORT_C: PORTC ^= (1<<pin); break;
		case PORT_D: PORTD ^= (1<<pin); break;
		default: return ERROR;
	}
	return OK;
}

uint8_t DIO_togglePort(uint8_t port)
{
	// Check which port
	switch (port)
	{
		// Toggle PORTx register
		case PORT_A: PORTA = ~PORTA; break;
		case PORT_B: PORTB = ~PORTB; break;
		case PORT_C: PORTC = ~PORTC; break;
		case PORT_D: PORTD = ~PORTD; break;
		default: return ERROR;
	}
	return OK;
}

/* Read input value on certain pin HIGH or LOW */
uint8_t DIO_readPin(uint8_t port, uint8_t pin, uint8_t* value)
{
	// Check which port
	switch (port)
	{
		// read bit corresponding to this pin in register PINx
		case PORT_A: *value = (PINA & (1<<pin)>>pin);
					 break;
		case PORT_B: *value = (PINB & (1<<pin)>>pin);
					 break;
		case PORT_C: *value = (PINC & (1<<pin)>>pin);
					 break;
		case PORT_D: *value = (PIND & (1<<pin)>>pin);
					 break;
		default: return ERROR;		
	}
	return OK;
}

/* Read input value on certain pin HIGH or LOW */
uint8_t DIO_readPort(uint8_t port, uint8_t* value)
{
	// Check which port
	switch (port)
	{
		// read register PINx
		case PORT_A: *value = PINA; break;
		case PORT_B: *value = PINB; break;
		case PORT_C: *value = PINC; break;
		case PORT_D: *value = PIND; break;
		default:  return ERROR;
	}
	return OK;
}
