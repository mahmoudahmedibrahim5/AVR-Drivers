#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_Registers.h"

#define NORMAL_MODE 0
#define CLEAR_TIMER_ON_COMPARE_MATCH_MODE 1
#define FAST_PWM_MODE 2
#define PHASE_CORRECT_MODE 3

#define TOIE0 0
#define OCIE0 1

#define TOV0 0
#define OCF0 1

#define prescaler1    0
#define prescaler8    1
#define prescaler64   2
#define prescaler256  3
#define prescaler1024 4

/* Non PWM modes */
#define TOGGLE_MODE 1
#define CLR_MODE    2
#define SET_MODE    3
/* PWM modes */
#define NON_INVERTING_MODE 2
#define INVERTING_MODE 3

void TIMER0_enable(u8 Register);
u8 read_Flag (u8 flag);
void TIMER0_init(u8 mode, u8 initial_Value, u8 prescaler);
void TIMER0_compOut(u8 mode, u8 value);
void TIMER0_updateInitialValue(u8 initial_Value);
void TIMER0_setDutyCycle(u8 compare_Value);


#endif /* TIMER0_H_ */