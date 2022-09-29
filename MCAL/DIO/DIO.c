/*
 * DIO.c
 * DIO Driver for ATmega16A
 * Created: 27-Sep-22 12:12:29 AM
 * Author : Mahmoud Ahmed
 */ 

#include "DIO.h"

void DIO_initPin(u8 port, u8 pin, u8 mode)
{
	if (mode == OUTPUT)
	{
		switch (port)
		{
			case 0: DDRA |= (1<<pin); break;
			case 1: DDRB |= (1<<pin); break;
			case 2: DDRC |= (1<<pin); break;
			case 3: DDRD |= (1<<pin); break;
		}
	} 
	else if (mode == INPUT)
	{
		switch (port)
		{
			case 0: DDRA &= ~(1<<pin); break;
			case 1: DDRB &= ~(1<<pin); break;
			case 2: DDRC &= ~(1<<pin); break;
			case 3: DDRD &= ~(1<<pin); break;
		}	
	}
	else if (mode == INPUT_PULLUP)
	{
			switch (port)
			{
				case 0: DDRA &= ~(1<<pin); 
						PORTA |= (1<<pin);
						break;
				case 1: DDRB &= ~(1<<pin); 
						PORTB |= (1<<pin);
						break;
				case 2: DDRC &= ~(1<<pin); 
						PORTC |= (1<<pin);
						break;
				case 3: DDRD &= ~(1<<pin); 
						PORTD |= (1<<pin);
						break;
			}
	}
		
}

void DIO_initPort(u8 port, u8 mode)
{
		if (mode == OUTPUT)
		{
			switch (port)
			{
				case 0: DDRA = 0xFF; break;
				case 1: DDRB = 0xFF; break;
				case 2: DDRC = 0xFF; break;
				case 3: DDRD = 0xFF; break;
			}
		}
		else if (mode == INPUT)
		{
			switch (port)
			{
				case 0: DDRA = 0x00; break;
				case 1: DDRB = 0x00; break;
				case 2: DDRC = 0x00; break;
				case 3: DDRD = 0x00; break;
			}
		}
		else if (mode == INPUT_PULLUP)
		{
			switch (port)
			{
				case 0: DDRA = 0x00;
						PORTA = 0xFF;
						break;
				case 1: DDRB = 0x00;
						PORTB = 0xFF;
						break;
				case 2: DDRC = 0x00;
						PORTC = 0xFF;
						break;
				case 3: DDRD = 0x00;
						PORTD = 0xFF;
						break;
			}
		}
}

void DIO_setPinValue(u8 port, u8 pin, u8 value)
{
	if (value == HIGH)
	{
		switch (port)
		{
			case 0: PORTA |= (1<<pin); break;
			case 1: PORTB |= (1<<pin); break;
			case 2: PORTC |= (1<<pin); break;
			case 3: PORTD |= (1<<pin); break;
		}
	}
	else if (value == INPUT)
	{
		switch (port)
		{
			case 0: PORTA &= ~(1<<pin); break;
			case 1: PORTB &= ~(1<<pin); break;
			case 2: PORTC &= ~(1<<pin); break;
			case 3: PORTD &= ~(1<<pin); break;
		}
	}
}

void DIO_setPortValue(u8 port, u8 value)
{
	if (value == HIGH)
	{
		switch (port)
		{
			case 0: PORTA = 0xFF; break;
			case 1: PORTB = 0xFF; break;
			case 2: PORTC = 0xFF; break;
			case 3: PORTD = 0xFF; break;
		}
	}
	else if (value == LOW)
	{
		switch (port)
		{
			case 0: PORTA = 0x00; break;
			case 1: PORTB = 0x00; break;
			case 2: PORTC = 0x00; break;
			case 3: PORTD = 0x00; break;
		}
	}
}

u8 DIO_readPin(u8 port, u8 pin)
{
	u8 val = -1;
		switch (port)
		{
			case 0: if( (PINA & (1<<pin)) == 0x00) val = 0;
					else val = 1;
					break;
			case 1: if( (PINB & (1<<pin)) == 0x00) val = 0;
					else val = 1;
					break;
			case 2: if( (PINC & (1<<pin)) == 0x00) val = 0;
					else val = 1;
					break;
			case 3: if( (PIND & (1<<pin)) == 0x00) val = 0;
					else val = 1;
					break;
		}
	return val;
}

u8 DIO_readPort(u8 port)
{
	u8 val = -1;
	switch (port)
	{
		case 0: val = PINA; break;
		case 1: val = PINB; break;
		case 2: val = PINC; break;
		case 3: val = PIND; break;
	}
	return val;
}
