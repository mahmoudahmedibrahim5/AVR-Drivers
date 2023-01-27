#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_Registers.h"

#define DISABLED 0
#define RESERVED 1
#define EVEN_PARITY 2
#define ODD_PARITY 3

typedef enum USCRA_PORT {MPCM, U2X, PE, DOR, FE, UDRE, TXC, RXC}USCRA_PORT_t;
typedef enum USCRB_PORT {TXB8, RXB8, UCSZ2, TXEN, RXEN, UDRIE, TXCIE, RXCIE}USCRB_PORT_t;
typedef enum USCRC_PORT {UCPOL, UCSZ0, UCSZ1, USBS, UPM0, UPM1, UMSEL, URSEL}USCRC_PORT_t;
	
void UART_initialize(uint32_t baudrate, uint64_t fosc);
void UART_send(uint8_t data);
void UART_receieve(uint8_t *data);
void UART_setParityMode(uint8_t mode);
void UART_setStopBits(uint8_t mode);

#endif /* UART_INTERFACE_H_ */