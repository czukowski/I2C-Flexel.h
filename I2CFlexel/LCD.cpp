/**
 * LCD.h - I2C Flexel LCD class implementation
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements the LCD commands supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */

#include "I2CFlexel.h"
#include "LCD.h"

namespace I2CFlexel
{
	void LCD::setLcdBacklightBrightness(byte brightness)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_LCD_BACKLIGHT_BRIGHTNESS);
		sendCommandParameter(brightness);
		endCommand();
	}

	void LCD::setLcdContrast(byte contrast)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_LCD_CONTRAST);
		sendCommandParameter(contrast);
		endCommand();
	}

	void LCD::turnOnDisplay()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_ON_DISPLAY);
		endCommand();
	}

	void LCD::turnOffDisplay()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_OFF_DISPLAY);
		endCommand();
	}

	void LCD::setLcdCursorPosition(byte row, byte column)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_LCD_CURSOR_POSITION);
		sendCommandParameter(min(I2C_FLEXEL_LCD_MAX_ROWS_COUNT - 1, row));
		sendCommandParameter(min(I2C_FLEXEL_LCD_MAX_COLS_COUNT - 1, column));
		endCommand();
	}

	void LCD::homeCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_HOME_CURSOR);
		endCommand();
	}

	void LCD::turnOnUnderlineCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_ON_UNDERLINE_CURSOR);
		endCommand();
	}

	void LCD::turnOffUnderlineCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_OFF_UNDERLINE_CURSOR);
		endCommand();
	}

	void LCD::moveCursorLeftOneSpace()
	{
		beginCommand(I2C_FLEXEL_COMMAND_MOVE_CURSOR_LEFT_ONE_SPACE);
		endCommand();
	}

	void LCD::moveCursorRightOneSpace()
	{
		beginCommand(I2C_FLEXEL_COMMAND_MOVE_CURSOR_RIGHT_ONE_SPACE);
		endCommand();
	}

	void LCD::turnOnBlinkingCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_ON_BLINKING_CURSOR);
		endCommand();
	}

	void LCD::turnOffBlinkingCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_OFF_BLINKING_CURSOR);
		endCommand();
	}

	void LCD::clearLcdScreen()
	{
		beginCommand(I2C_FLEXEL_COMMAND_CLEAR_LCD_SCREEN);
		endCommand();
	}

	void LCD::printStringOnLcd(byte* str, uint8_t length)
	{
		beginCommand(I2C_FLEXEL_COMMAND_PRINT_STRING_ON_LCD);
		sendCommandParameter(length);
		sendCommandParameters(str, length);
		endCommand();
	}

	void LCD::loadLcdCustomCharacters(byte addr, byte* bitmap)
	{
		beginCommand(I2C_FLEXEL_COMMAND_LOAD_LCD_CUSTOM_CHARACTERS);
		sendCommandParameter(addr);
		sendCommandParameters(bitmap, I2C_FLEXEL_LCD_CHAR_ROWS_COUNT);
		endCommand();
	}
}