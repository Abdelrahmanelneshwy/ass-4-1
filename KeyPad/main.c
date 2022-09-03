/*
 * main.c
 *
 *  Created on: Sep 3, 2022
 *      Author: abdelrahman
 */
#include "Keypad_interface.h"
int main()
{
	LCD_init();
	Keypad_init();
	while(1)
	{
		LCD_Data(Get_Key());
	}
}

