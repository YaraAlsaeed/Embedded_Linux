#include "DIO.h"
#include "DIO_REG.h"
#include "Bit_Math.h"
#include "Std_Types.h"
/**
 *@brief  : Function to Configure the Pins to be INPUT InternalPullUp or INPUT ExternalPullDown pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t ErrorStatus = DIO_enumNOk;
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD) //checking if the port number is correct
	{
		ErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum < DIO_enumPin0 || Copy_enumPinNum > DIO_enumPin7) //checking if the pin number is correct
	{
		ErrorStatus = DIO_enumWrongPin;
	}
	else if(Copy_enumConfig < DIO_enumOutput || Copy_enumConfig > DIO_enumInputExternalPD) //checking if the configuration is correct
	{
		ErrorStatus = DIO_enumWrongConfig;
	}
	else //implement the code normally
	{
		switch(Copy_enumPortNum) //check we are in which port
		{
			case DIO_enumPortA: //if port A
				switch(Copy_enumConfig) //check what configuration did we choose
				{
					case DIO_enumOutput: //if output
						SET_BIT(DDRA,Copy_enumPinNum);
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						CLR_BIT(DDRA,Copy_enumPinNum);
						CLR_BIT(PORTA,Copy_enumPinNum);
						break;
					case DIO_enumInputInternalPU: //if input internal pullup
						CLR_BIT(DDRA,Copy_enumPinNum);
						SET_BIT(PORTA,Copy_enumPinNum);
						break;
					default:
						break;	
				}
				break;
			case DIO_enumPortB: //if port B
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						SET_BIT(DDRB,Copy_enumPinNum);
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						CLR_BIT(DDRB,Copy_enumPinNum);
						CLR_BIT(PORTB,Copy_enumPinNum);
						break;
					case DIO_enumInputInternalPU: //if internal pullup
						CLR_BIT(DDRB,Copy_enumPinNum);
						SET_BIT(PORTB,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortC: //if port C
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						SET_BIT(DDRC,Copy_enumPinNum);
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						CLR_BIT(DDRC,Copy_enumPinNum);
						CLR_BIT(PORTC,Copy_enumPinNum);
						break;
					case DIO_enumInputInternalPU: //if internal pullup
						CLR_BIT(DDRC,Copy_enumPinNum);
						SET_BIT(PORTC,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortD: //if Port D 
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						SET_BIT(DDRD,Copy_enumPinNum);
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						CLR_BIT(DDRD,Copy_enumPinNum);
						CLR_BIT(PORTD,Copy_enumPinNum);
						break;
					case DIO_enumInputInternalPU: //if input internal pullup
						CLR_BIT(DDRD,Copy_enumPinNum);
						SET_BIT(PORTD,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		ErrorStatus = DIO_enumOk;
	}
	return ErrorStatus;
}
/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT InternalPullUp or INPUT ExternalPullDown or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t ErrorStatus = DIO_enumNOk;
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD) //checking if the port number is correct
	{
		ErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumConfig < DIO_enumOutput || Copy_enumConfig > DIO_enumInputExternalPD) //checking if the configuration is correct
	{
		ErrorStatus = DIO_enumWrongConfig;
	}
	else //implement code normally
	{
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA: //if Port A
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						DDRA = 0xFF;
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						DDRA = 0x00;
						PORTA = 0x00;
						break;
					case DIO_enumInputInternalPU: //if input internal pullup
						DDRA = 0x00;
						PORTA = 0xFF;
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortB: //if port B
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						DDRB = 0xFF;
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						DDRB = 0x00;
						PORTB = 0x00;
						break;
					case DIO_enumInputInternalPU: //if input internal pullup
						DDRB = 0x00;
						PORTB = 0xFF;
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortC: //if port C
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						DDRC = 0xFF;
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						DDRC = 0x00;
						PORTC = 0x00;
						break;
					case DIO_enumInputInternalPU: //if input internal pullup
						DDRC = 0x00;
						PORTC = 0xFF;
						break;
					default:
						break;
					}
					break;
			case DIO_enumPortD: //if port D
				switch(Copy_enumConfig)
				{
					case DIO_enumOutput: //if output
						DDRD = 0xFF;
						break;
					case DIO_enumInputExternalPD: //if input external pulldown
						DDRD = 0x00;
						PORTD = 0x00;
						break;
					case DIO_enumInputInternalPU: //if input internal pullup
						DDRD = 0x00;
						PORTD = 0xFF;
						break;
					default:
						break;
					}
				break;
			default:
				break;
		}
		ErrorStatus = DIO_enumOk;
	}
	return ErrorStatus;
}

/**
 *@brief  : Function to Set the Input Pins to be external pulldown or internal pullup or the output pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t ErrorStatus = DIO_enumNOk;
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD) //checking if the port number is correct
	{
		ErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum < DIO_enumPin0 || Copy_enumPinNum > DIO_enumPin7) //checking if the pin number is correct
	{
		ErrorStatus = DIO_enumWrongPin;
	}
	else if(Copy_enumLogicState < DIO_enumLogicLow || Copy_enumLogicState > DIO_enumLogicHigh)
	{
		ErrorStatus = DIO_enumWrongConfig;
	}
	else //implement code normally
	{
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA: //if Port A
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh: 
						SET_BIT(PORTA,Copy_enumPinNum);
						break;
					case DIO_enumLogicLow:
						CLR_BIT(PORTA,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortB: //if port B
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
						SET_BIT(PORTB,Copy_enumPinNum);
						break;
					case DIO_enumLogicLow:
						CLR_BIT(PORTB,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortC: //if port C
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
						SET_BIT(PORTC,Copy_enumPinNum);
						break;
					case DIO_enumLogicLow:
						CLR_BIT(PORTC,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortD: //if port D
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
						SET_BIT(PORTD,Copy_enumPinNum);
						break;
					case DIO_enumLogicLow:
						CLR_BIT(PORTD,Copy_enumPinNum);
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		ErrorStatus = DIO_enumOk;
	}
	return ErrorStatus;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState) 
{
	DIO_enumError_t ErrorStatus = DIO_enumNOk;
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD) //checking if the port number is correct
	{
		ErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumLogicState < DIO_enumLogicLow || Copy_enumLogicState > DIO_enumLogicHigh) //checking if the configuration is correct
	{
		ErrorStatus = DIO_enumWrongConfig;
	}
	else //implement code normally
	{
		switch (Copy_enumPortNum)
		{
			case DIO_enumPortA: //if Port A
				switch(Copy_enumLogicState)
				{
						case DIO_enumLogicHigh:
							PORTA = 0xFF;
							break;
						case DIO_enumLogicLow:
							PORTA = 0x00;
							break;
						default:
							break;
				}
				break;
			case DIO_enumPortB: //if port B
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
						PORTB = 0xFF;
						break;
					case DIO_enumLogicLow:
						PORTB = 0x00;
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortC: //if port C
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
						PORTC = 0xFF;
						break;
					case DIO_enumLogicLow:
						PORTC = 0x00;
						break;
					default:
						break;
				}
				break;
			case DIO_enumPortD: //if port D
				switch(Copy_enumLogicState)
				{
					case DIO_enumLogicHigh:
						PORTD = 0xFF;
						break;
					case DIO_enumLogicLow:
						PORTD = 0x00;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		ErrorStatus = DIO_enumOk;
	}
	return ErrorStatus;
}

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t ErrorStatus = DIO_enumNOk;
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD) //checking if the port number is correct
	{
		ErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum < DIO_enumPin0 || Copy_enumPinNum > DIO_enumPin7) //checking if the pin number is correct
	{
		ErrorStatus = DIO_enumWrongPin;
	}
	else if (Add_Pu8PinValue == NULL) //checking if the pointer is not wild
	{
		ErrorStatus = DIO_enumNullPointer;
	}
	else //implement the code normally
	{
		switch(Copy_enumPortNum) //check we are in which port
		{
			case DIO_enumPortA: //if port A
				*Add_Pu8PinValue = GET_BIT(PINA,Copy_enumPinNum);
				break;
			case DIO_enumPortB: //if port B
				*Add_Pu8PinValue = GET_BIT(PINB,Copy_enumPinNum);
				break;
			case DIO_enumPortC: //if port C
				*Add_Pu8PinValue = GET_BIT(PINC,Copy_enumPinNum);
				break;
			case DIO_enumPortD: //if Port D
				*Add_Pu8PinValue = GET_BIT(PIND,Copy_enumPinNum);
				break;
			default:
				break;
		}
		ErrorStatus = DIO_enumOk;
	}
	return ErrorStatus;
}