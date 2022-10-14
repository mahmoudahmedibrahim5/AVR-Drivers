#ifndef ADC_H_
#define ADC_H_

#include "ADC_Registers.h"

#define AVCC 0
#define INTERNAL_REFERENCE 1
#define AREF 2

#define SINGLE_CONVERSION 0
#define FREE_RUNNING 1

#define ADIE 3
#define ADATE 5
#define ADSC 6
#define ADEN 7


#define prescaler2    1
#define prescaler4	  2
#define prescaler8    3
#define prescaler16	  4
#define prescaler32	  5
#define prescaler64   6
#define prescaler128  7

void ADC_enableInterrupt(void);
void ADC_start(u8 mode);
void ADC_init(u8 pin, u8 source, u8 prescaler);
u16 ADC_read(void);



#endif /* ADC_H_ */