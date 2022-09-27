#ifndef DIO_DRIVER
#define DIO_DRIVER

#include "Data_Types.h"
#include "DIO_Registers.h"

#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

void DIO_initPin(u8 port, u8 pin, u8 mode);
void DIO_initPort(u8 port, u8 mode);

void DIO_setPinValue(u8 port, u8 pin, u8 value);
void DIO_setPortValue(u8 port, u8 value);

u8 DIO_readPin(u8 port, u8 pin);
u8 DIO_readPort(u8 port);

#endif