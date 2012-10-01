/**
 * Clock.h - I2C Flexel Input class implementation
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements Input (keypad, remote) commands supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */

#include "I2CFlexel.h"
#include "Input.h"

#define I2C_FLEXEL_READ_KEY_BASE I2C_FLEXEL_COMMAND_READ_KEYPAD

namespace I2CFlexel
{
	void Input::setKeypadMode(KeypadMode mode)
	{
		setKeypadMode(mode);
		keypadMode = mode;
	}
	void Input::setKeypadMode(byte mode)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_KEYPAD_MODE);
		sendCommandParameter(mode);
		endCommand();
	}

	byte Input::readKeypad()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_KEYPAD);
	}

	byte Input::readButtons()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_BUTTONS);
	}

	byte Input::readPS2Keypad()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_PS2_KEYPAD);
	}

	byte Input::readKey(byte command)
	{
		beginCommand(command);
		endCommand();
		requestByte();
		return readByte();
	}
	byte Input::readKey()
	{
		return readKey(I2C_FLEXEL_READ_KEY_BASE + keypadMode);
	}
}	