/*
 * LCD_program.c
 *
 *  Created on: Aug 27, 2022
 *      Author: abdelrahman
 */
#include "LCD_interface.h"
#include "DIO_register.h"
#include <util/delay.h>
void LCD_init()
{
	DIO_setPinDir(LCD_Ctr_Port, LCD_RS_PIN, output);
	DIO_setPinDir(LCD_Ctr_Port, LCD_RW_PIN, output);
	DIO_setPinDir(LCD_Ctr_Port, LCD_EN_PIN, output);

	DIO_setPinDir(LCD_Data_Port, Data_PIN0, output);
	DIO_setPinDir(LCD_Data_Port, Data_PIN1, output);
	DIO_setPinDir(LCD_Data_Port, Data_PIN2, output);
	DIO_setPinDir(LCD_Data_Port, Data_PIN3, output);

	_delay_ms(50);

	LCD_CMD(LCD_RETURN_HOME);
	LCD_CMD(LCD_4BIT_MODE_2LINES_5X7);
	_delay_ms(1);

	LCD_CMD(LCD_ON_CURSOR_OFF);
	_delay_ms(1);

	LCD_CMD(LCD_CLEAR_SCREEN);
	_delay_ms(20);

	LCD_CMD(LCD_SHIFT_CURSOR_RIGHT);
	LCD_CMD(LCD_SET_CURSOR_1LINE);
}

void LCD_CMD(u8 CMD)
{
	/***************active LCD to take command**************/
	DIO_setPinval(LCD_Ctr_Port, LCD_RS_PIN, LOW);
	DIO_setPinval(LCD_Ctr_Port, LCD_RW_PIN, LOW);
	/**************higher bits command**************/
	PORTA=(PORTA & 0x0f)|(CMD & 0xf0);
	LCD_ENABLE();
	/**************lower bits command**************/
	PORTA=(PORTA & 0x0f)|(CMD << 4);
	LCD_ENABLE();
	_delay_ms(2);
}

void LCD_Data(u8 Data)
{
	/***************active LCD to take Data**************/
		DIO_setPinval(LCD_Ctr_Port, LCD_RS_PIN, HIGH);
		DIO_setPinval(LCD_Ctr_Port, LCD_RW_PIN, LOW);
		/**************higher bits data**************/
		PORTA=(PORTA & 0x0f)|(Data & 0xf0);
		LCD_ENABLE();
		/**************lower bits data**************/
		PORTA=(PORTA & 0x0f)|(Data << 4);
		LCD_ENABLE();
		_delay_ms(2);
}

void LCD_CLEAR()
{
 LCD_CMD(LCD_CLEAR_SCREEN);
 _delay_ms(20);
}

void LCD_ENABLE()
{
	DIO_setPinval(LCD_Ctr_Port, LCD_EN_PIN, HIGH);
	_delay_ms(2);
	DIO_setPinval(LCD_Ctr_Port, LCD_EN_PIN, LOW);
	_delay_ms(2);
}


void LCD_Sentence(u8 *SEN,u8 ROW, u8 Col)
{
	LCD_Goto(ROW,Col);
	u8 index=0;
	u8 line=0;
	while(SEN[index] != '\0' && (ROW*16)+(index+Col)<32)
	{
		if((ROW*16)+(index+Col)<16)
		{
			LCD_Data(SEN[index]);
			index++;
		}
		else if(((ROW * 16)+(index + Col))==16 && line==0)
		{
			LCD_Goto(1, 0);
			line++;
		}
		else if(((ROW*16)+(index+Col))<32 && line==1)
		{
			LCD_Data(SEN[index]);
			index++;
		}

	}
}

void LCD_Digit(u8 num)
{
	if(num<=9 && num>=0)
	{
		LCD_Data(48+num);
	}
}

void LCD_Goto(u8 ROW, u8 Col)
{
	u8 address;
	if (ROW <2 && Col <16)
	{
		address=(ROW * 0x40)+Col;
		address= SET_BIT(address,7);
		LCD_CMD(address);
	}
}

void LCD_Pattern(u8 *pattern,u8 CGRAM_index)
{
	u8 address;
	if(CGRAM_index < 8)
	{
		address = CGRAM_index * 8;
		address = SET_BIT(address,6);
		address = CLR_BIT(address,7);
		LCD_CMD(address);
		for(int i=0; i<8 ;i++)
		{
			LCD_Data(pattern[i]);
		}
	}
	LCD_CMD(LCD_RETURN_HOME);
}

void LCD_DisplayPattern(u8 CGRAM_index,u8 ROW, u8 Col )
{
	LCD_Goto(ROW,Col);
	LCD_Data(CGRAM_index);
}
