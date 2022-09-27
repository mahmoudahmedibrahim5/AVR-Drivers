/*
 * SSD.c
 *
 * Created: 27-Sep-22 9:03:41 PM
 * Author : ADMIN
 */ 

#include "SSD.h"
u8  SSD_Numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void SSD_SetNumber(u8 port, u8 type, u8 num)
{
	DIO_initPort(port, OUTPUT);
	if (type == Common_Cathode)
	{
	switch(port)
	{
		case 0: PORTA = SSD_Numbers[num]; break;
		case 1: PORTB = SSD_Numbers[num]; break; 
		case 2: PORTC = SSD_Numbers[num]; break; 
		case 3: PORTD = SSD_Numbers[num]; break;  
	}
	}
	else if(type == Common_Anode)
	{
		switch(port)
		{
			case 0: PORTA = ~SSD_Numbers[num]; break;
			case 1: PORTB = ~SSD_Numbers[num]; break;
			case 2: PORTC = ~SSD_Numbers[num]; break;
			case 3: PORTD = ~SSD_Numbers[num]; break;
		}
	}
}

void SSD_Enable(u8 port, u8 pin, u8 mode, u8 type)
{
	DIO_initPort(port, OUTPUT);
	DIO_initPin(port, pin, OUTPUT);
	if (type == Common_Cathode)
	{
		if(mode == ON) DIO_setPinValue(port, pin, LOW);
		else if(mode == OFF) DIO_setPinValue(port, pin, HIGH);
	}
	else if(type == Common_Anode)
	{
		if(mode == ON) DIO_setPinValue(port, pin, HIGH);
		else if(mode == OFF) DIO_setPinValue(port, pin, LOW);
	}
}