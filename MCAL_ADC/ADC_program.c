/*
 * ADC_program.c
 *
 *  Created on: Sep 10, 2022
 *      Author: abdelrahman
 */
#include <avr/io.h>
#include "ADC_interface.h"

void ADC_init(u8 type ,u8 VREF,u8 prescale)
{
	SET_BIT(ADCSRA,ADEN);

	/**************SET PINS OF MSB or LSB *********/
	if(type == MSB)
	{
		SET_BIT(ADMUX,ADLAR);
	}
	else if (type == LSB)
	{
		CLR_BIT(ADMUX,ADLAR);
	}

	/**************VREF choose *********/
	if(VREF == internal)
		{
			CLR_BIT(ADMUX,REFS1);
			CLR_BIT(ADMUX,REFS0);
		}
		else if (type == external)
		{
			SET_BIT(ADMUX,REFS1);
			SET_BIT(ADMUX,REFS0);

		}
	/**************prescale value **************/
	switch(prescale)
	{
	case 2:	CLR_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
	case 4: CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
	case 8: SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
	case 16: CLR_BIT(ADCSRA,ADPS0);
			 CLR_BIT(ADCSRA,ADPS1);
			 SET_BIT(ADCSRA,ADPS2);
			break;
	case 32: SET_BIT(ADCSRA,ADPS0);
			 CLR_BIT(ADCSRA,ADPS1);
			 SET_BIT(ADCSRA,ADPS2);
			break;
	case 64: CLR_BIT(ADCSRA,ADPS0);
		     SET_BIT(ADCSRA,ADPS1);
		     SET_BIT(ADCSRA,ADPS2);
			break;
	case 128: SET_BIT(ADCSRA,ADPS0);
			  SET_BIT(ADCSRA,ADPS1);
			  SET_BIT(ADCSRA,ADPS2);
			break;
	default: // do no thing;
	 break;
	}
}

u16 ADC_ReadChannel(u8 Channel)//, u8 type)
{

	/**********************channel******************/
		Channel &= 0x07;
		ADMUX &=0xE0 ;
		ADMUX = ADMUX | Channel;
		SET_BIT(ADCSRA,ADSC);
		while(!GET_BIT(ADCSRA,ADIF));
		SET_BIT(ADCSRA,ADIF);
		/*if(type == MSB)
					{
					u16 ADC_value;
						ADC_value=ADCH;
						ADC_value=(ADC_value<<2) | ((ADCL>>6) & 0x03) ;
					}
					else if (type == LSB)
					{
						ADC_value=ADCH;
						ADC_value=(ADC_value<<8) | (ADCL) ;
					}
						SET_BIT(ADCSRA,ADIF);
				}*/
	return ADC;
}
