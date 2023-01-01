#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Registers.h"

#define LOW 0
#define HIGH 1

#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define OK 0
#define ERROR -1

uint8_t DIO_initPin(uint8_t port, uint8_t pin, uint8_t mode);
uint8_t DIO_initPort(uint8_t port, uint8_t mode);

uint8_t DIO_setPinValue(uint8_t port, uint8_t pin, uint8_t value);
uint8_t DIO_setPortValue(uint8_t port, uint8_t value);

uint8_t DIO_togglePin(uint8_t port, uint8_t pin);
uint8_t DIO_togglePort(uint8_t port);

uint8_t DIO_readPin(uint8_t port, uint8_t pin, uint8_t* value);
uint8_t DIO_readPort(uint8_t port, uint8_t* value);

#endif /* DIO_INTERFACE_H_ */