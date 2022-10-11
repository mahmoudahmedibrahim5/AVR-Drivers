#ifndef EXINT_H_
#define EXINT_H_

#include "Data_Types.h"
#include "Registers.h"

#define INT2 5
#define INT0 6
#define INT1 7

#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

void EXINT_enable(u8 pin, u8 mode);
void EXINT_disable(u8 pin);
u8 EXINT_readFlag(u8 pin);


#endif /* EXINT_H_ */