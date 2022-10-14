#ifndef TIMER0_REGISTERS_H_
#define TIMER0_REGISTERS_H_

#include "Data_Types.h"

#define SFIOR *((volatile u8 *) 0x50)
#define TCNT0 *((volatile u8 *) 0x52)
#define TCCR0 *((volatile u8 *) 0x53)
#define TIFR  *((volatile u8 *) 0x58)
#define TIMSK *((volatile u8 *) 0x59)
#define OCR0  *((volatile u8 *) 0x5C)

#endif /* TIMER0_REGISTERS_H_ */