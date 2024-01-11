/*
 * main.c
 *
 * Created: 11/28/2023 3:49:37 PM
 *  Author: Yara
 */ 

#include "DIO_REG.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "DIO.h"
#include <util/delay.h>

int main(void)
{
    DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0,DIO_enumOutput);
    DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1,DIO_enumOutput);

    while(1)
    {
	    
	    DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh);
	    DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
	    _delay_ms(1000);
	    DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh);
	    DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
	    _delay_ms(1000);
    }
}