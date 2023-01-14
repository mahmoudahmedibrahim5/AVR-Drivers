#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/GLOBAL_INT/GINT.h"
#include "../../MCAL/EXTERNAL_INT/EXINT_Interface.h"

typedef struct button{
	uint8_t port;
	uint8_t pin;
}ST_Button_t;

uint8_t BUTTON_init (ST_Button_t* button);
uint8_t BUTTON_read(ST_Button_t* button, uint8_t* value);
uint8_t BUTTON_interrupt(uint8_t pin, uint8_t mode);

#endif /* BUTTON_H_ */