#ifndef SSD_H_
#define SSD_H_

#include "DIO.h"

#define Common_Cathode 0
#define Common_Anode 1
#define ON 1
#define OFF 0

void SSD_SetNumber(u8 port,u8 type, u8 num);
void SSD_Enable(u8 port, u8 pin, u8 mode, u8 type);
void SSD_SetDecimalPoint(u8 port, u8 value);

#endif

/*
CONNECTIONS
	  PORT
0 1 2 3 4 5 6 7
| | | | | | | |
v v v v v v v v
a b c d e f g .
   7-Segment

0 = a b c d e f  = 0b 0011 1111
1 = b c		     = 0b 0000 0110
2 = a b c g e d  = 0b 0101 1011
3 = a b c d g    = 0b 0100 1111
4 = b c f g      = 0b 0110 0110
5 = a c d f g    = 0b 0110 1101
6 = a c d e f g  = 0b 0111 1101
7 = a b c		 = 0b 0000 0111
8 =a b c d e f g = 0b 0111 1111
9 = a b c d f g  = 0b 0110 1111
u8  numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
*/