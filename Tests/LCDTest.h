/**
 * LCDTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_LCDTEST_H_
#define I2CFLEXEL_LCDTEST_H_

test(setLcdBacklightBrightnessTest)
{
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_LCD_BACKLIGHT_BRIGHTNESS, 0x50, '\0'};
	i2cFlexelSuite.object.setLcdBacklightBrightness(80);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(setLcdContrastTest)
{
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_LCD_CONTRAST, 0x51, '\0'};
	i2cFlexelSuite.object.setLcdContrast(81);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(turnOnDisplayTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_TURN_ON_DISPLAY, '\0'};
	i2cFlexelSuite.object.turnOnDisplay();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(turnOffDisplayTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_TURN_OFF_DISPLAY, '\0'};
	i2cFlexelSuite.object.turnOffDisplay();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(setLcdCursorPositionTest)
{
	const char expectedCommand[5] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_LCD_CURSOR_POSITION, 0x01, 0x03, '\0'};
	i2cFlexelSuite.object.setLcdCursorPosition(1, 3);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(setLcdCursorPositionTrimmedTest)
{
	const char expectedCommand[5] = {
		I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_LCD_CURSOR_POSITION, I2C_FLEXEL_LCD_MAX_ROWS_COUNT - 1, I2C_FLEXEL_LCD_MAX_COLS_COUNT - 1, '\0'
	};
	i2cFlexelSuite.object.setLcdCursorPosition(I2C_FLEXEL_LCD_MAX_ROWS_COUNT, I2C_FLEXEL_LCD_MAX_COLS_COUNT + 2);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(homeCursorTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_HOME_CURSOR, '\0'};
	i2cFlexelSuite.object.homeCursor();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(turnOnUnderlineCursorTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_TURN_ON_UNDERLINE_CURSOR, '\0'};
	i2cFlexelSuite.object.turnOnUnderlineCursor();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(turnOffUnderlineCursorTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_TURN_OFF_UNDERLINE_CURSOR, '\0'};
	i2cFlexelSuite.object.turnOffUnderlineCursor();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(moveCursorLeftOneSpaceTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_MOVE_CURSOR_LEFT_ONE_SPACE, '\0'};
	i2cFlexelSuite.object.moveCursorLeftOneSpace();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(moveCursorRightOneSpaceTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_MOVE_CURSOR_RIGHT_ONE_SPACE, '\0'};
	i2cFlexelSuite.object.moveCursorRightOneSpace();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(turnOnBlinkingCursorTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_TURN_ON_BLINKING_CURSOR, '\0'};
	i2cFlexelSuite.object.turnOnBlinkingCursor();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(turnOffBlinkingCursorTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_TURN_OFF_BLINKING_CURSOR, '\0'};
	i2cFlexelSuite.object.turnOffBlinkingCursor();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(clearLcdScreenTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_CLEAR_LCD_SCREEN, '\0'};
	i2cFlexelSuite.object.clearLcdScreen();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(printStringOnLcdTest)
{
	const char expectedCommand[9] = {
		I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_PRINT_STRING_ON_LCD, 0x05, 'H', 'e', 'l', 'l', 'o', '\0'
	};
	i2cFlexelSuite.object.printStringOnLcd("Hello");
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(printStringOnLcdWithLengthTest)
{
	const char expectedCommand[9] = {
		I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_PRINT_STRING_ON_LCD, 0x05, 'H', 'e', 'l', 'l', 'o', '\0'
	};
	i2cFlexelSuite.object.printStringOnLcd("Hello", 5);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	
}

test(loadLcdCustomCharactersTest)
{
	// The bit map for character ‘X’
	byte bitmap[8] = {0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00};
	const char expectedCommand[12] = {
		I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_LOAD_LCD_CUSTOM_CHARACTERS, 0x01, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, '\0'
	};
	i2cFlexelSuite.object.loadLcdCustomCharacters(0x01, bitmap);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,write,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	
}

#endif /* I2CFLEXEL_OUTPUTTEST_H_ */