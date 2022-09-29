#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define NO_KEY_PRESSED 10
u8 KEYPAD_read(u8 port);


#endif /* KEYPAD_H_ */

// Connect the most left pin in the keypad to Px0 (PA0,PB0,PC0,PD0)