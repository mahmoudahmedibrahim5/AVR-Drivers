/*
 * KEYPAD.c
 *
 * Created: 27-Sep-22 11:53:51 PM
 * Author : Mahmoud Ahmed
 */ 

#include "KEYPAD.h"

u8 KEYPAD_read(u8 port)
{
	/* row and column are two variables to identify which key is pressed
	 * row is initialized by 1 and column is initialized by zero
	 * If no keys are pressed then (((row-1)*4)+column) will be equal zero
	 * So the function will return value of NO_KEY_PRESSED
	 */
	u8 row = 1,column = 0;
	u8 key[17] = {NO_KEY_PRESSED,1,2,3,'A',4,5,6,'B',7,8,9,'C','*',0,'#','D'};
	
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
	
	if (DIO_readPin(port, 0) == 0) row=1; 
	else if (DIO_readPin(port, 1) == 0) row=2;
	else if (DIO_readPin(port, 2) == 0) row=3;
	else if (DIO_readPin(port, 3) == 0) row=4;
	
	
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
	
	if (DIO_readPin(port, 4) == 0) column=1;
	else if (DIO_readPin(port, 5) == 0) column=2;
	else if (DIO_readPin(port, 6) == 0) column=3;
	else if (DIO_readPin(port, 7) == 0) column=4;
	
	return key[((row-1)*4)+column];
}
