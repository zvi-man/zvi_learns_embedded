/*
 * scheduler.h
 *
 *  Created on: Feb 9, 2022
 *      Author: צבי
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdbool.h>

#define MAX_SLOTS 10

typedef void (*SCHEDULER_CALLBACK_t);
typedef int SCHEDULER_slot_num;

typedef struct SCHEDULER_SLOT_t
{
	bool is_active;
	uint32_t period_in_ticks;
	uint32_t ticks_remaining;
	bool is_priodic;
	SCHEDULER_CALLBACK_t pf_callback;

} SCHEDULER_SLOT_t;

void SCHEDULER_init();
void SCHEDULER_tick();
SCHEDULER_slot_num SCHEDULER_register_slot(uint32_t period_in_ticks, 	bool is_priodic, SCHEDULER_CALLBACK_t pf_callback);
void SCHEDULER_set_slot_period(SCHEDULER_slot_num slot_num, uint32_t period_in_ticks);

#endif /* INC_SCHEDULER_H_ */
