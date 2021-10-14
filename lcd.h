/*
 * lcd.h
 *
 *  Created on: Oct 13, 2021
 *      Author: Kyrillos
 */

#ifndef LCD_H_
#define LCD_H_

#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"



/****************************************************
 *  		Module macros and configuration         *
 ****************************************************/
#define
#define LCD_MODE
#define LCD_COMMAND_TYPE
/*--------------------------------------------------*/

/****************************************************
 *  		Module macros and configuration         *
 ****************************************************/

typedef enum{
	LCD_CMD_CLEAR_DISPLAY 						= 0x01,
	LCD_CMD_RETURN_HOME								  ,
	LCD_CMD_SHIFT_CURSOR_LEFT					= 0x04,
	LCD_CMD_SHIFT_DISPLAY_RIGHT		  				  ,
	LCD_CMD_SHIFT_CURSOR_RIGHT		  				  ,
	LCD_CMD_SHIFT_DISPLAY_LEFT		  				  ,
	LCD_CMD_DISPLAY_OFF_CURSOR_OFF					  ,
	LCD_CMD_DISPLAY_OFF_CURSOR_ON				= 0x0A,
	LCD_CMD_DISPLAY_ON_CURSOR_OFF				= 0x0C,
	LCD_CMD_DISPLAY_ON_CURSOR_ON				= 0x0E,
	LCD_CMD_DISPLAY_ON_CURSOR_BLINKING			= 0x0F,
	LCD_CMD_SHIFT_CURSOR_POSITION_LEFT				  ,
	LCD_CMD_SHIFT_CURSOR_POSITION_RIGHT			= 0x14,
	LCD_CMD_SHIFT_ENTIRE_DISPLAY_LEFT			= 0x18,
	LCD_CMD_SHIFT_CURSOR_DISPLAY_RIGHT			= 0x1C,
	LCD_CMD_MOVE_CURSOR_TO_BEGINNING_1ST_LINE	= 0x80,
	LCD_CMD_MOVE_CURSOR_TO_BEGINNING_2ND_LINE	= 0xC0,
	LCD_CMD_MODE_8BITS_1_LINES_5X7_DOTS			= 0x30,
	LCD_CMD_MODE_8BITS_2_LINES_5X7_DOTS			= 0x38,
	LCD_CMD_MODE_4BITS_1_LINES_5X7_DOTS			= 0x20,
	LCD_CMD_MODE_8BITS_2_LINES_5X7_DOTS			= 0x28
}LCD_Command;

#define LCD_PORT_ID
#endif /* LCD_H_ */
