/*
 * Seven_Segment.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Abdelrahman
 */

#include "Seven_Segment.h"
/*******************disable 7_segment*********************/
void Seven_segment_enable(u8 Segment)
{
	if (Segment == tens)
	{
		DIO_setPinDir(B, PIN2, output);
		DIO_setPinval(B, PIN2, HIGH);
	}
	else if (Segment == unit)
	{
		DIO_setPinDir(B, PIN1, output);
		DIO_setPinval(B, PIN1, HIGH);
	}
}

/*******************enable 7_segment*********************/
void Seven_segment_disable(u8 Segment)
{
	if (Segment == tens)
	{
		DIO_setPinDir(B, PIN2, output);
		DIO_setPinval(B, PIN2, LOW);
	}
	else if (Segment == unit)
	{
		DIO_setPinDir(B, PIN1, output);
		DIO_setPinval(B, PIN1, LOW);
	}
}
/**************active 7_segment on which pins *****************/
void Seven_segment_init(u8 PORTID,u8 type)
{
  if(type == MSB)
  {
	  DIO_setPinDir(PORTID, PIN4, output);
	  DIO_setPinDir(PORTID, PIN5, output);
	  DIO_setPinDir(PORTID, PIN6, output);
	  DIO_setPinDir(PORTID, PIN7, output);
  }
  else if (type == LSB)
  {
	  DIO_setPinDir(PORTID, PIN0, output);
	  DIO_setPinDir(PORTID, PIN1, output);
	  DIO_setPinDir(PORTID, PIN2, output);
	  DIO_setPinDir(PORTID, PIN3, output);
  }
}


/*********************write value on 7_segment*****************/
void Write_Seven_segment(u8 PORTID,u8 type, u8 num)
{
	if(type == MSB)
	{
		switch(PORTID)
				{
				case A: PORTA=(PORTA & 0x0f) | (num<<4);
					break;
				case B: PORTB=(PORTB & 0x0f) | (num<<4);
					break;
				case C: PORTC=(PORTC & 0x0f) | (num<<4);
					break;
				case D: PORTD=(PORTD & 0x0f) | (num<<4);
					break;
				default:/*do no thing*/
					break;
				}
	}
	else if (type == LSB)
	{
		switch(PORTID)
		{
		case A: PORTA=(PORTID & 0xf0) | (num & 0x0f);
			break;
		case B: PORTB=(PORTID & 0xf0) | (num & 0x0f);
			break;
		case C: PORTC=(PORTID & 0xf0) | (num & 0x0f);
			break;
		case D: PORTD=(PORTID & 0xf0) | (num & 0x0f);
			break;
		default:/*do no thing*/
			break;
		}
	}
}


/***********************read value on 7_segment***********************/
u8 Read_Seven_segment(u8 PORTID,u8 type)
{
	int Bits;
	if(type == MSB)
	{
		Bits = ((PORTID & 0xf0)>>4);
	}
	else if (type == LSB)
	{
		Bits = (PORTID & 0x0f);
	}
 return Bits ;
}
