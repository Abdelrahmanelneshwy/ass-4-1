/*
 * Keypad_progran.c
 *
 *  Created on: Sep 3, 2022
 *      Author: abdelrahman
 */
#include "Keypad_interface.h"
#include "DIO_interface.h"
#include "switch_interface.h"
#include <util/delay.h>


const u8 arr[Row][Col]={{'7','8','9','/'},
						{'4','5','6','*'},
						{'1','2','3','-'},
						{'c','0','=','+'}};

void Keypad_init()
{
	/***************init col pins**************/
	DIO_setPinDir(Keypad_PORT, Col1, output);
	DIO_setPinDir(Keypad_PORT, Col2, output);
	DIO_setPinDir(Keypad_PORT, Col3, output);
	DIO_setPinDir(Keypad_PORT, Col4, output);

	DIO_setPinval(Keypad_PORT, Col1, HIGH);
	DIO_setPinval(Keypad_PORT, Col2, HIGH);
	DIO_setPinval(Keypad_PORT, Col3, HIGH);
	DIO_setPinval(Keypad_PORT, Col4, HIGH);

	/****************init row pins****************/
	DIO_setPinDir(Keypad_PORT, row1, input);
	DIO_setPinDir(Keypad_PORT, row2, input);
	DIO_setPinDir(Keypad_PORT, row3, input);
	DIO_setPinDir(Keypad_PORT, row4, input);

	DIO_setPinval(Keypad_PORT, row1, HIGH);
	DIO_setPinval(Keypad_PORT, row2, HIGH);
	DIO_setPinval(Keypad_PORT, row3, HIGH);
	DIO_setPinval(Keypad_PORT, row4, HIGH);
}

u8 Get_Key()
{
	u8 r;
	u8 c;
	u8 flag=0;
	for(c=0;c<4;c++)
	{
		DIO_setPinval(Keypad_PORT,c, LOW);
		for(r=4;r<8;r++)
		{
			if(PB_state(Keypad_PORT, c)==0)
			{
				_delay_ms(30);

				if(PB_state(Keypad_PORT, c)==0)
				{
					if(flag==0)
					{
					return arr[r][c];
					flag=1;
					}
				}
			}
			else
			{
				flag=1;
			}
		}
		DIO_setPinval(Keypad_PORT,c, HIGH);
	}
	return 0 ;
}

