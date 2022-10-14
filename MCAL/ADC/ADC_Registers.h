#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Data_Types.h"

#define ADMUX	*((volatile u8 *)0x27)
#define ADCSRA	*((volatile u8 *)0x26)
#define ADCH	*((volatile u8 *)0x25)
#define ADCL	*((volatile u8 *)0x24)
#define SFIOR	*((volatile u8 *)0x50)


#endif /* REGISTERS_H_ */