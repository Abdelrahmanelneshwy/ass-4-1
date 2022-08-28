/*
 * main.c
 *
 *  Created on: Aug 27, 2022
 *      Author: abdelrahman
 */

#include "LCD_interface.h"
#include <util/delay.h>
 int main()
 {
	 LCD_init();

	 while(1)
	 {
		LCD_Sentance("massssssssssryyyyyyyyyyyyy", 0, 10);
	 }
 }


