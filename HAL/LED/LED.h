#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER0/TIMER0_Interface.h"

typedef struct led{
	uint8_t port;
	uint8_t pin;
}ST_Led_t;

uint8_t LED_init (ST_Led_t* LED);
uint8_t LED_turnON (ST_Led_t* LED);
uint8_t LED_turnOFF (ST_Led_t* LED);
uint8_t LED_toggle (ST_Led_t* LED);
uint8_t LED_read(ST_Led_t* LED, uint8_t* value);

#endif /* LED_H_ */