/*
 * UART.h
 *
 * Created: 10/25/2021 10:21:17 PM
 *  Author: ADMIN
 */ 


#ifndef UART_H_
#define UART_H_

void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );

#endif /* UART_H_ */