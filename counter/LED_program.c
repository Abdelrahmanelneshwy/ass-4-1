/*
 * LED_program.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Abdelrahman
 */
#include "LED_interface.h"


/***********setPinDir to output**********/
void LED_init(u8 PORTID,u8 PINID)
{
	DIO_setPinDir(PORTID,PINID,output);
}



/***********setPinval to high**********/
void LED_on(u8 PORTID,u8 PINID)
{
	DIO_setPinval(PORTID,PINID,HIGH);
}




/***********setPinval to low**********/
void LED_off(u8 PORTID,u8 PINID)
{
	DIO_setPinval(PORTID,PINID,LOW);
}



/***************toggle led between high and low*****************/
void LED_toggle(u8 PORTID,u8 PINID)
{
	TOG_BIT(PORTID, PINID);
}
