#ifndef EXINT_INTERFACE_H_
#define EXINT_INTERFACE_H_

#include "EXINT_Registers.h"

#define INT0 6
#define INT1 7
#define INT2 5

#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define OK 0
#define ERROR -1

uint8_t EXINT_enable(uint8_t pin, uint8_t mode);
uint8_t EXINT_disable(uint8_t pin);
uint8_t EXINT_readFlag(uint8_t pin, uint8_t *value);

//void (*interruptFunction)(void); // pointer to void function
//void EXINT_setInterruptFunction(void (*func)(void));

#define INT0_vect __vector_1
#define INT1_vect __vector_2

#define ISR(Vector) void Vector(void)__attribute__((signal,used));\
void Vector(void)


#endif /* EXINT_INTERFACE_H_ */