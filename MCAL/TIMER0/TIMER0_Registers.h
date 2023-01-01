#ifndef TIMER0_REGISTERS_H_
#define TIMER0_REGISTERS_H_

#include "../../Utilities/DataTypes.h"

#define SFIOR *((volatile uint8_t *) 0x50)
#define TCNT0 *((volatile uint8_t *) 0x52)
#define TCCR0 *((volatile uint8_t *) 0x53)
#define TIFR  *((volatile uint8_t *) 0x58)
#define TIMSK *((volatile uint8_t *) 0x59)
#define OCR0  *((volatile uint8_t *) 0x5C)


#endif /* TIMER0_REGISTERS_H_ */