#ifndef GIE_H_
#define GIE_H_

#include "Data_Types.h"

#define SREG *((volatile u8 *) 0x5F)

void GINT_Enable (void);
void GINT_Disable (void);


#endif /* GIE_H_ */