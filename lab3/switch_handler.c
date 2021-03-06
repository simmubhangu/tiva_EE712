/*
 * switch_handler.c
 *
 *  Created on: 25-Jan-2019
 *      Author: simmu
 */

#include "commonheader.h"
#include "switch_handler.h"

void switch_setup(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
}


void switchPinConfig(void)
{
    // Following two line removes the lock from SW2 interfaced on PORTF Pin0 -- leave this unchanged
    LOCK_F=0x4C4F434BU;
    CR_F=GPIO_PIN_0|GPIO_PIN_4;

    // GPIO PORTF Pin 0 and Pin4
    GPIODirModeSet(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0,GPIO_DIR_MODE_IN); // Set Pin-4 of PORT F as Input. Modifiy this to use another switch
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0,GPIO_STRENGTH_12MA,GPIO_PIN_TYPE_STD_WPU);
}

int read_switch(char Pin_number)
{
    return GPIOPinRead(GPIO_PORTF_BASE,Pin_number);
}


