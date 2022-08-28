/*
 * LCD_interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: abdelrahman
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_config.h"

#define LCD_4BIT_MODE_2LINES_5X7 0x28
#define LCD_8BIT_MODE_2LINES_5X7 0x38

#define LCD_SHIFT_CURSOR_LEFT    0x04
#define LCD_SHIFT_CURSOR_RIGHT   0x06

#define LCD_CLEAR_SCREEN         0x01
#define LCD_RETURN_HOME          0x02
#define LCD_SHIFT_RIGHT          0x05
#define LCD_SHIFT_LEFT           0x07
#define LCD_ON_CURSOR_OFF        0x0C
#define LCD_OFF_CURSOR_OFF       0x08
#define LCD_SET_CURSOR_1LINE     0x80
#define LCD_SET_CURSOR_2LINE     0XC0


void LCD_init();

void LCD_CMD(u8 CMD);

void LCD_Data(u8 Data);

void LCD_CLEAR();

void LCD_ENABLE();

void LCD_Sentance(u8 *SEN,u8 ROW, u8 Col);

void LCD_Digit(u8 num);

void LCD_Goto(u8 ROW, u8 Col);
#endif /* LCD_INTERFACE_H_ */
