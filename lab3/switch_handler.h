/*
 * switch_handler.h
 *
 *  Created on: 25-Jan-2019
 *      Author: simmu
 */

#ifndef SWITCH_HANDLER_H_
#define SWITCH_HANDLER_H_

// LOCK_F and CR_F - used for unlocking PORTF pin 0
#define LOCK_F (*((volatile unsigned long *)0x40025520))
#define CR_F   (*((volatile unsigned long *)0x40025524))


void switch_setup(void);
void switchPinConfig(void);
int read_switch(char);


#endif /* SWITCH_HANDLER_H_ */
