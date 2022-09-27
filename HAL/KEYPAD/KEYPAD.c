/*
 * KEYPAD.c.c
 *
 * Created: 27-Sep-22 11:53:51 PM
 * Author : ADMIN
 */ 

#include "KEYPAD.h"

u8 KEYPAD_read(u8 port)
{
	u8 r = -1;
	u8 c = -1;
	// To read the row
	DIO_initPin(port, 0, INPUT_PULLUP);
	DIO_initPin(port, 1, INPUT_PULLUP);
	DIO_initPin(port, 2, INPUT_PULLUP);
	DIO_initPin(port, 3, INPUT_PULLUP);
	
	DIO_initPin(port, 4, OUTPUT);
	DIO_initPin(port, 5, OUTPUT);
	DIO_initPin(port, 6, OUTPUT);
	DIO_initPin(port, 7, OUTPUT);
	
	DIO_setPinValue(port, 4, LOW);
	DIO_setPinValue(port, 5, LOW);
	DIO_setPinValue(port, 6, LOW);
	DIO_setPinValue(port, 7, LOW);
	
	if (DIO_readPin(port, 0) == 0) r=1; 
	else if (DIO_readPin(port, 1) == 0) r=2;
	else if (DIO_readPin(port, 2) == 0) r=3;
	else if (DIO_readPin(port, 3) == 0) r=4;
	
	
	// To read the column
	DIO_initPin(port, 4, INPUT_PULLUP);
	DIO_initPin(port, 5, INPUT_PULLUP);
	DIO_initPin(port, 6, INPUT_PULLUP);
	DIO_initPin(port, 7, INPUT_PULLUP);
	
	DIO_initPin(port, 0, OUTPUT);
	DIO_initPin(port, 1, OUTPUT);
	DIO_initPin(port, 2, OUTPUT);
	DIO_initPin(port, 3, OUTPUT);
	
	DIO_setPinValue(port, 0, LOW);
	DIO_setPinValue(port, 1, LOW);
	DIO_setPinValue(port, 2, LOW);
	DIO_setPinValue(port, 3, LOW);
	
	if (DIO_readPin(port, 4) == 0) c=1;
	else if (DIO_readPin(port, 5) == 0) c=2;
	else if (DIO_readPin(port, 6) == 0) c=3;
	else if (DIO_readPin(port, 7) == 0) c=4;
	
	return ((r-1)*4 + c);
}