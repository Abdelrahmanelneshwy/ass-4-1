/*
 * Seven_Segment.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Abdelrahman
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"



#define MSB 0xf0          //second 4 bits in port
#define LSB 0x0f          //first 4 bits in port

#define tens 1
#define unit 0
/*******************enable 7_segment*********************/
void Seven_segment_enable(u8 Segment);
/*******************disable 7_segment*********************/
void Seven_segment_disable(u8 Segment);
/**************active 7_segment on which pins *****************/
void Seven_segment_init(u8 PORTID,u8 type);

/*********************write value on 7_segment*****************/
void Write_Seven_segment(u8 PORTID,u8 type, u8 num);

/***********************read value on 7_segment***********************/
u8 Read_Seven_segment(u8 PORTID,u8 type);
#endif /* SEVEN_SEGMENT_H_ */
