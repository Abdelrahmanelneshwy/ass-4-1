/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Abdelrahman
 */

#include "DIO_interface.h"
#include "Seven_Segment.h"
#include "switch_interface.h"
#include <util/delay.h>
int main()
{
	Seven_segment_init(A, MSB);
	PB_init(B, PIN0);
	PB_init(D, PIN6);
	int Units=0;
	int Tens=0;

	u8 flag=0;
	u8 flag1=0;
	while(1)
	{

		/*********using PB0 to increment the units ************/
		if(PB_state(B, PIN0))
		{
			_delay_ms(30);
			if(PB_state(B, PIN0))
			{
				if (flag==0)
				{
					Units++;
					if(Units>9)
					{
						Units=0;
						Tens++;
						if(Tens>9)
						{
							Tens=0;
						}
					}
				}
			}
			flag=1;
		}
		else
		{
			flag=0;
		}

		/*********using PB1 to increment the Tens ************/
		if(PB_state(D, PIN6))
		{
			_delay_ms(30);
			if(PB_state(D, PIN6))
			{
				if (flag1==0)
				{
					Tens++;
					if(Tens>9)
					{
						Tens=0;
						Units=0;

					}
					flag1=1;
				}
			}
		}

		else
		{
			flag1=0;
		}




		/*********show no. on 7_segments************/
		Seven_segment_enable(tens);
		Write_Seven_segment(A,MSB,Tens);
		_delay_ms(200);
		Seven_segment_disable(tens);
		Seven_segment_enable(unit);
		Write_Seven_segment(A,MSB,Units);
		_delay_ms(200);
		Seven_segment_disable(unit);
	}

}
