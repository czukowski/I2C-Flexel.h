/**
 * LCD.h - I2C Flexel LCD class
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements the LCD commands supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_LCD_H_
#define I2CFLEXEL_LCD_H_

#include <Arduino.h>

#define I2C_FLEXEL_LCD_MAX_ROWS_COUNT 4
#define I2C_FLEXEL_LCD_MAX_COLS_COUNT 20
#define I2C_FLEXEL_LCD_CHAR_ROWS_COUNT 8

namespace I2CFlexel
{
	class LCD : public I2CFlexel
	{
		/**
		 * This command sets the backlight value (0 – 250), the single byte parameter select the
		 * desired brightness. The module modulates the backlight via a transistor. This allows to set
		 * different brightness settings.
		 * The command requires 1 ms to take effect; therefore, the subsequent input must have an
		 * appropriate delay.
		 * Default 80
		 */
		void setLcdBacklightBrightness(byte brightness);
		/**
		 * This command sets the LCD contrast value (0 – 100), the single byte parameter select the
		 * desired contrast. The module set the contrast voltage.
		 * The command requires 1 ms to take effect; therefore, the subsequent input must have an
		 * appropriate delay.
		 * Default 20
		 */
		void setLcdContrast(byte contrast);
		/**
		 * This command turns on the LCD display screen.
		 */
		void turnOnDisplay();
		/**
		 * This command turns off the LCD display screen.
		 */
		void turnOffDisplay();
		/**
		 * This command moves the cursor to a specified location where the next character
		 * will be displayed. The row value - from 0 to 3, the column value - from 0 to 19.
		 * The command requires 2 ms to take effect; therefore, the subsequent input must have an
		 * appropriate delay.
		 */
		void setLcdCursorPosition(byte row, byte column);
		/**
		 * This command moves the cursor move the cursor to line 0, column 0 of the LCD
		 * screen.
		 * The command requires 2 ms to take effect; therefore, the subsequent input must have an
		 * appropriate delay.
		 */
		void homeCursor();
		/**
		 * This command turn on the underline cursor, the cursor position is where the next
		 * character will appear.
		 * Default: The underline cursor is off.
		 */
		void turnOnUnderlineCursor();
		/**
		 * This command turns off the underline cursor.
		 * Default: The underline cursor is off.
		 */
		void turnOffUnderlineCursor();
		/**
		 * This command moves the cursor position left 1 space.
		 * Default: None.
		 */
		void moveCursorLeftOneSpace();
		/**
		 * This command moves the cursor position right 1 space.
		 * Default: None.
		 */
		void moveCursorRightOneSpace();
		/**
		 * This command turns on the blinking cursor; both the cursor and the character on
		 * the cursor will blink.
		 * Default: The blinking cursor is off.
		 */
		void turnOnBlinkingCursor();
		/**
		 * This command turns off the blinking cursor.
		 * Default: The blinking cursor is off.
		 */
		void turnOffBlinkingCursor();
		/**
		 * This command clears the display and place the cursor at line 1 column 1.
		 * Default: None.
		 * The command requires 2 ms to take effect; therefore, the subsequent input must have an
		 * appropriate delay.
		 */
		void clearLcdScreen();
		/**
		 * This command prints the string with the specified length to the LCD at the present
		 * cursor position.
		 */
		void printStringOnLcd(byte* str, uint8_t length);
		/**
		 * LCD module has space for 8 custom characters. Each custom character is 5 pixels wide by 8 pixels high.
		 * The `addr` parameter indicates which custom character is defining, and must have a value from 0 to 7.
		 * Following the `addr` parameter are 8 bytes that define the custom character. Bits 0 to 4 each byte
		 * byte will each define a pixel character.
		 * The command requires 2 ms to take effect; therefore, the subsequent input must have an
		 * appropriate delay.
		 * Example: The bit map for character ‘X’.
		 * Bit     7 6 5 4 3 2 1 0  Hex
		 * Byte 1  0 0 0 1 0 0 0 1  0x11
		 * Byte 2  0 0 0 0 1 0 1 0  0x0A
		 * Byte 3  0 0 0 0 0 1 0 0  0x04
		 * Byte 4  0 0 0 0 1 0 1 0  0x0A
		 * Byte 5  0 0 0 1 0 0 0 1  0x11
		 * Byte 6  0 0 0 0 0 0 0 0  0x00
		 * Byte 7  0 0 0 0 0 0 0 0  0x00
		 * Byte 8  0 0 0 0 0 0 0 0  0x00
		 */
		void loadLcdCustomCharacters(byte addr, byte* bitmap);
	};
}

#endif /* I2CFLEXEL_LCD_H_ */