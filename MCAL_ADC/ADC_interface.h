/*
 * ADC_interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: abdelrahman
 */

#ifndef MCAL_MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_MCAL_ADC_ADC_INTERFACE_H_
#include "../../Helper/STD_TYPES.h"
#include "../../Helper/BIT_MATH.h"
#include "ADC_config.h"
#include "../MCAL_DIO/DIO_interface.h"

#define MSB 1
#define LSB 0

#define internal 0
#define external 1

void ADC_init(u8 type,u8 VREF,u8 prescale);

u16 ADC_ReadChannel(u8 Channel);//,u8 type);


#endif /* MCAL_MCAL_ADC_ADC_INTERFACE_H_ */
