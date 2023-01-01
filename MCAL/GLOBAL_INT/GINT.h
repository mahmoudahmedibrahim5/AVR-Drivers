#ifndef GINT_H_
#define GINT_H_

#include "../../Utilities/DataTypes.h"

#define SREG *((volatile uint8_t *) 0x5F)

void GINT_Enable (void);
void GINT_Disable (void);

#endif /* GINT_H_ */