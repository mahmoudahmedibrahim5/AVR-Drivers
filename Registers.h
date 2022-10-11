#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Data_Types.h"

#define MCUCR	*((volatile u8 *) 0x55)
#define MCUCSR	*((volatile u8 *) 0x54)
#define GICR	*((volatile u8 *) 0x5B)
#define GIFR	*((volatile u8 *) 0x5A)

#endif /* REGISTERS_H_ */