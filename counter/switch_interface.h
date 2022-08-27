/*
 * switch_interface.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Abdelrahman
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"




/**************set pin to be output for PushButton*************/
void PB_init(u8 PORTID,u8 PINID);



/**************check value on pin***************/
u8 PB_state(u8 PORTID,u8 PINID);

#endif /* SWITCH_INTERFACE_H_ */
