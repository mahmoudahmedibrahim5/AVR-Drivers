#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

#include "../../Utilities/DataTypes.h"

#define UDR		*((volatile uint8_t *)0x2C)
#define UCSRA	*((volatile uint8_t *)0x2B)
#define UCSRB	*((volatile uint8_t *)0x2A)
#define UBBRL	*((volatile uint8_t *)0x29)
#define UCSRC	*((volatile uint8_t *)0x40)
#define UBBRH	*((volatile uint8_t *)0x40)


#endif /* UART_REGISTERS_H_ */