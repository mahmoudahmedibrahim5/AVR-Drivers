#ifndef EXINT_REGISTERS_H_
#define EXINT_REGISTERS_H_

#include "../../Utilities/DataTypes.h"

#define MCUCR	*((volatile uint8_t *) 0x55)
#define MCUCSR	*((volatile uint8_t *) 0x54)
#define GICR	*((volatile uint8_t *) 0x5B)
#define GIFR	*((volatile uint8_t *) 0x5A)

#endif /* EXINT_REGISTERS_H_ */