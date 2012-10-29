/**
 * I2CFlexel.h - I2C Flexel class
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This library aims at making it easy to control the I2C-FLEXEL board. The base class defines lower level communication
 * with the board using an interfaced Arduino Wire library, see https://github.com/czukowski/Wire.h
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */

#ifndef I2CFLEXEL_H_
#define I2CFLEXEL_H_

#include <Arduino.h>
#include <IWire.h>
#include "I2CIncludes.h"

namespace I2CFlexel
{
	class I2CFlexel
	{
		public:
			/**
			 * Constructor and destructor
			 */
			I2CFlexel() {};
			virtual ~I2CFlexel() {};
			/**
			 * Wire dependency setter
			 */
			void setWire(IWire& wire);
			/**
			 * Begins a command transmission
			 */
			void beginCommand(byte command);
			/**
			 * Sends a command parameter
			 */
			void sendCommandParameter(byte parameter);
			/**
			 * Sends command parameters (multiple bytes)
			 */
			void sendCommandParameters(byte* parameters, uint8_t count);
			/**
			 * Ends command transmission
			 */
			void endCommand();
			/**
			 * Requests a byte from the connector
			 */
			void requestByte();
			/**
			 * Requests a number of bytes from the connector
			 */
			void requestBytes(uint8_t count);
			/**
			 * Reads a single byte from the connector
			 */
			byte readByte();
			/**
			 * Requests and reads specified number of bytes into array
			 */
			void readBytes(byte* arr, uint8_t size);
			/**
			 * Returns DateTime structure with the current time
			 */
			DateTime getTime();
			/**
			 * Returns DateTime structure with the current date
			 */
			DateTime getDate();
			/**
			 * Returns DateTime structure with the current date and time
			 */
			DateTime getTimeAndDate();
			/**
			 * Sets time from the provided DateTime struct
			 */
			void setTime(const DateTime &time);
			/**
			 * Sets date from the provided DateTime struct
			 */
			void setDate(const DateTime &date);
			/**
			 * Sets time and date from the provided DateTime struct
			 */
			void setTimeAndDate(const DateTime &dateTime);
			/**
			 * Returns data byte with firmware version number.
			 */
			byte getFirmwareVersion();
			/**
			 * Calls the `setHighPowerPin` method with the converted argument set
			 */
			void setHighPowerPin(const HighPowerPin &pin);
			/**
			 * Calls the `clearHighPowerPin` method with the converted argument set
			 */
			void clearHighPowerPin(const HighPowerPin &pin);
			/**
			 * Calls the `setPwmForHighPowerPin` method with the converted argument set
			 */
			void setPwmForHighPowerPin(const HighPowerPin &pin, byte pwmValue);
			/**
			 * Calls the `setServoMotorPosition` method with the converted argument set
			 */
			void setServoMotorPosition(const ServoPin &pin, byte msb, byte lsb);
			/**
			 * Calls the `setPwmForDcMotor` method with the converted argument set
			 */
			void setPwmForDcMotor(const DcMotor &motor, const MotorDirection &direction, byte pwmValue);
			/**
			 * Calls the `getAnalogInputValue` method with the converted argument set
			 */
			uint16_t getAnalogInputValue(const AnalogInputPin &pin);
			/**
			 * Calls the `setBuzzerTime` method with the converted argument set
			 */
			void setBuzzerTime(uint16_t ms);
			/**
			 * Calls the `setKeypadMode` method with the converted argument set
			 */
			void setKeypadMode(const KeypadMode &mode);
			/**
			 * Sends command to read Keypad, Buttons or PS2 keypad depending on the current keypad mode.
			 */
			byte readKey();
			//byte readRemoteControl();
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
		/**
		 * Some commands are protected methods to try and prevent invalid values coming into them.
		 * For such commands public methods with constrained parameters are also provided.
		 */
		protected:
			/**
			 * Writes 3 data bytes into provided argument.
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 */
			void getTime(byte* time);
			/**
			 * Writes 4 data bytes into provided argument.
			 * Byte 1 – day of the week (BCD codification, 00-06)
			 * Byte 2 – day of the month (BCD codification, 01-31)
			 * Byte 3 – month (BCD codification, 01-12)
			 * Byte 4 – year (BCD codification, 00-99)
			 */
			void getDate(byte* date);
			/**
			 * Writes 7 data bytes into provided argument.
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 * Byte 4 – day of the week (BCD codification, 00-06)
			 * Byte 5 – day of the month (BCD codification, 01-31)
			 * Byte 6 – month (BCD codification, 01-12)
			 * Byte 7 – year (BCD codification, 00-99)
			 */
			void getTimeAndDate(byte* timeAndDate);
			/**
			 * Sets the time from the provided 3 bytes
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 */
			void setTime(byte sec, byte min, byte hour);
			/**
			 * Sets the date from the provided 4 bytes
			 * Byte 1 – day of the week (BCD codification, 00-06)
			 * Byte 2 – day of the month (BCD codification, 01-31)
			 * Byte 3 – month (BCD codification, 01-12)
			 * Byte 4 – year (BCD codification, 00-99)
			 */
			void setDate(byte wday, byte day, byte month, byte year);
			/**
			 * Sets the time and date from the provided 7 bytes
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 * Byte 4 – day of the week (BCD codification, 00-06)
			 * Byte 5 – day of the month (BCD codification, 01-31)
			 * Byte 6 – month (BCD codification, 01-12)
			 * Byte 7 – year (BCD codification, 00-99)
			 */
			void setTimeAndDate(byte sec, byte min, byte hour, byte wday, byte day, byte month, byte year);
			/**
			 * This command sets the high power pin, the single byte parameter select the pin
			 * number in range from 1 to 4.
			 */
			void setHighPowerPin(byte pin);
			/**
			 * This command reset the high power pin, the single byte parameter select the pin
			 * number in range from 1 to 4.
			 */
			void clearHighPowerPin(byte pin);
			/**
			 * This command sets the high power pin as PWM output with PWM duty cycle
			 * according [pwmValue]. The first parameter [pin] selects the pin number.
			 * The pin number – from 1 to 4, PWM value – from 0 to 255.
			 * Note: PWM frequency is 100 Hz. Use this pin mode for high power LED dimming
			 * or the heater control.
			 */
			void setPwmForHighPowerPin(byte pin, byte pwmValue);
			/**
			 * This command sets the servo motor position. The first parameter [servo] selects
			 * the servo motor in range from 1 to 4. [MSB] and [LSB] bytes define the servo motor
			 * position in range from 600 to 2400 with 1 microsecond resolution.
			 * Note: The module embedded microcontroller pins are shared between the high power
			 * outputs and servo motor control.
			 * For example, if you use a high power pin 2 to control relay, you can not use servo
			 * motor with number 2.
			 */
			void setServoMotorPosition(byte pin, byte msb, byte lsb);
			/**
			 * This command sets the direction and PWM duty cycle for DC motor. The first
			 * parameter [mot/dir] selects the motor and direction, the second byte [pwm] defines the PWM
			 * duty cycle in range from 0 to 255.
			 * First parameter [mot/dir] format: Bit 2 defines the motor: 0 – motor 1, 1 – motor 2; Bit 1 –
			 * sets the motor direction: 0 – forward, 1 – reverse.
			 */
			void setPwmForDcMotor(byte motorAndPosition, byte pwmValue);
			/**
			 * Reads the analog input. Data byte defines the input number in range from 1 to 4. Module
			 * returns 2 data bytes with 12 bit ADC value.
			 */
			void getAnalogInputValue(byte pin, byte* analog);
			/**
			 * Initiates the buzzer pulse. Data byte defines the buzzer pulse time. Data byte value is in range from 1 to
			 * 255 counts. 1 count = 5 milliseconds. The buzzer pulse frequency is 2 KHz.
			 */
			void setBuzzerTime(byte count);
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
		 * BCD conversion and some other helper functions are private methods
		 */
		private:
			IWire* connector;
			/**
			 * Convert normal BCD codification numbers to binary coded BCD codification
			 */
			byte decToBcd(byte val) { return ((val / 10 * 16) + (val % 10)); };
			/**
			 * Convert binary coded BCD codification to normal BCD codification numbers
			 */
			byte bcdToDec(byte val) { return ((val / 16 * 10) + (val % 16)); };
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

#endif /* I2CFLEXEL_H_ */