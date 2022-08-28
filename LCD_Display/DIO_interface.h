/*
 * DIO_interface.h
 *
 *  Created on: Aug 20, 2022
 *      Author: abdelrahman
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_register.h"

#define input 0
#define output 1

#define HIGH 1
#define LOW 0


#define portHIGH 0xff
#define portLOW 0x00


#define outport 0xff
#define inport 0x00
/*********port id************/
#define A 0
#define B 1
#define C 2
#define D 3


/*********pin id************/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*********function of port prototypes************/
void DIO_setPortDir(u8 PORTID,u8 Dir);
void DIO_setPortval(u8 PORTID,u8 portval);
u8 DIO_getPortval(u8 PORTID);


/*********function of Pin prototypes************/
void DIO_setPinDir(u8 PORTID,u8 PINID,u8 Dir);
void DIO_setPinval(u8 PORTID,u8 PINID,u8 pinval);
u8 DIO_getPinval(u8 PORTID,u8 PINID);
#endif /* DIO_INTERFACE_H_ */
