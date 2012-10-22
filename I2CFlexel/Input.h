/**
 * Clock.h - I2C Flexel Input class
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements Input (keypad, remote) commands supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2C_FLEXEL_INPUT_H_
#define I2C_FLEXEL_INPUT_H_

#include <Arduino.h>

namespace I2CFlexel
{
	enum KeypadMode {KEYPAD_4X4 = 0x00, KEYPAD_8 = 0x01, KEYPAD_PS2 = 0x02};

	class Input : public I2CFlexel
	{
		/**
		 * Public class methods
		 */
		public:
			/**
			 * Calls the `setKeypadMode` method with the converted argument set
			 */
			void setKeypadMode(KeypadMode mode);
			/**
			 * Sends command to read Keypad, Buttons or PS2 keypad depending on the current keypad mode.
			 */
			byte readKey();
			//byte readRemoteControl();
		/**
		 * Some commands are protected methods to try and prevent invalid values coming into them.
		 * For such commands public methods with constrained parameters are also provided.
		 */
		protected:
			/**
			 * Sets the keypad mode. Data byte defines the keypad mode.
			 * Data byte = 0x00 - matrix keypad 4 row x 4 column (default at power up).
			 * Data byte = 0x01 - 8 button port.
			 * Data byte = 0x02 - keyboard with PS2 interface.
			 */
			void setKeypadMode(byte mode);
			/**
			 * Read the keypad. Module returns 1 data byte. If there is no key data in the keypad buffer,
			 * 0 is returned. If there is key data, a key code from 0x01 to 0x10 is returned, depending on
			 * what key was pressed.
			 * Note: I2C-FLEXEL module provides 16 bytes FIFO buffer.
			 */
			byte readKeypad();
			/**
			 * Read the keypad port. Module returns 1 data byte. If there is no data in the keypad buffer,
			 * 0 is returned. If there is data, a button code from 0x01 to 0x08 is returned, depending on
			 * what button was pressed.
			 * Note: I2C-FLEXEL module provides 16 bytes FIFO buffer.
			 */
			byte readButtons();
			/**
			 * Read the keypad. Module returns 1 data bytes. If there is no key data in the keypad buffer,
			 * 0 is returned. If there is key data, a key code from 0x01 to 0x10 is returned, depending on
			 * what key was pressed.
			 * Note: I2C-FLEXEL module provides 16 bytes FIFO buffer.
			 */
			byte readPS2Keypad();
		/**
		 * Private class members
		 */
		private:
			/**
			 * Stores the current keypad mode
			 */
			byte keypadMode;
			/**
			 * Issues a read key command according to input argument.
			 */
			byte readKey(byte command);
	};	
}

#endif /* I2C_FLEXEL_INPUT_H_ */