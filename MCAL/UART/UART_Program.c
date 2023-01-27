/*
 * UART_Program.c
 *
 * Created: 25-Jan-23 4:37:09 PM
 *  Author: Mahmoud Ahmed Ibrahim
 */ 

#include "UART_Interface.h"

void UART_initialize(uint32_t baudrate, uint64_t fosc)
{
	/* Set baud rate */
	baudrate = (fosc/(16*baudrate))-1; // calculate UBRR
	UBBRH = (uint8_t)(baudrate>>8);
	UBBRL = (uint8_t)baudrate;			

	/* Enable transmitter and receiver */
	UCSRB |= (1<<TXEN)| (1<<RXEN); 
	
	/* Set mode */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);		// 8-bit mode
}

void UART_send(uint8_t data)
{
	// wait for current transmission
	while (!(UCSRA & (1<<UDRE)));
	// load the buffer with the data
	UDR = data;
}

void UART_receieve(uint8_t *data)
{
	// wait for data to be received
	while (!(UCSRA & (1<<RXC)));
	// load the buffer with the data
	*data = UDR;
}
void UART_setParityMode(uint8_t mode)
{
	/* when we read value from UCSRC register 
	 * first read contains UBRRH value 
	 * second read will contain UCSRC value so, 
	 * we use this temp to take first read before update USCRC value
	 */
	uint8_t tmp;
	tmp = UCSRC;
	UCSRC |= (1<<URSEL); // Select UCSRC to write in
	switch(mode)
	{
		case 0:
			tmp = UCSRC;
			UCSRC &= ~(1<<UPM0) &~(1<<UPM1);
			break;
		case 1:
			tmp = UCSRC;
			UCSRC |= (1<<UPM0) &~(1<<UPM1);
			break;
		case 2:
			tmp = UCSRC;
			UCSRC &= ~(1<<UPM0) |(1<<UPM1);
			break;
		case 3:
			tmp = UCSRC;
			UCSRC |= (1<<UPM0) |(1<<UPM1);
			break;
	}
}

void UART_setStopBits(uint8_t num)
{
	uint8_t tmp;
	tmp = UCSRC;
	UCSRC |= (1<<URSEL); // Select UCSRC to write in
	if (num == 1){
		tmp = UCSRC;
		UCSRC &= ~(1<<USBS);
	}
	else if(num == 2){
		tmp = UCSRC;
		UCSRC |= (1<<USBS);
	}
}