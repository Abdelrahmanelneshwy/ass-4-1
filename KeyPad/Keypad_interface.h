/*
 * Keypad_interface.h
 *
 *  Created on: Sep 3, 2022
 *      Author: abdelrahman
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Keypad_config.h"

void Keypad_init();

u8 Get_Key();

#endif /* KEYPAD_INTERFACE_H_ */
