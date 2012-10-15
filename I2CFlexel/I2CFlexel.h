/**
 * I2CFlexel.h - I2C Flexel base class
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

#include <IWire.h>

// I2C-Flexel board address and command prefix
#define I2C_FLEXEL_ADDRESS 0x48
#define I2C_FLEXEL_PREFIX 0xFE

// I2C-Flexel Module Control Commands
#define I2C_FLEXEL_COMMAND_GET_FIRMWARE_VERSION 0x24
#define I2C_FLEXEL_COMMAND_SET_HIGH_POWER_PIN 0x25
#define I2C_FLEXEL_COMMAND_CLEAR_HIGH_POWER_PIN 0x26
#define I2C_FLEXEL_COMMAND_SET_PWM_FOR_HIGH_POWER_PIN 0x27
#define I2C_FLEXEL_COMMAND_SET_SERVO_MOTOR_POSITION 0x28
#define I2C_FLEXEL_COMMAND_SET_PWM_FOR_DC_MOTOR 0x29
#define I2C_FLEXEL_COMMAND_GET_TIME 0x2A
#define I2C_FLEXEL_COMMAND_GET_DATE 0x2B
#define I2C_FLEXEL_COMMAND_GET_TIME_AND_DATE 0x2C
#define I2C_FLEXEL_COMMAND_SET_TIME 0x2D
#define I2C_FLEXEL_COMMAND_SET_DATE 0x2E
#define I2C_FLEXEL_COMMAND_SET_TIME_AND_DATE 0x2F
#define I2C_FLEXEL_COMMAND_GET_ANALOG_INPUT_VALUE 0x30
#define I2C_FLEXEL_COMMAND_SET_KEYPAD_MODE 0x31
#define I2C_FLEXEL_COMMAND_READ_KEYPAD 0x32
#define I2C_FLEXEL_COMMAND_READ_BUTTONS 0x33
#define I2C_FLEXEL_COMMAND_READ_PS2_KEYPAD 0x34
#define I2C_FLEXEL_COMMAND_READ_REMOTE_CONTROL 0x35
#define I2C_FLEXEL_COMMAND_SET_BUZZER_TIME 0x36

// I2C-Flexel LCD Control Commands
#define I2C_FLEXEL_COMMAND_SET_LCD_BACKLIGHT_BRIGHTNESS 0x03
#define I2C_FLEXEL_COMMAND_SET_LCD_CONTRAST 0x04
#define I2C_FLEXEL_COMMAND_TURN_ON_DISPLAY 0x0A
#define I2C_FLEXEL_COMMAND_TURN_OFF_DISPLAY 0x0B
#define I2C_FLEXEL_COMMAND_SET_LCD_CURSOR_POSITION 0x0C
#define I2C_FLEXEL_COMMAND_HOME_CURSOR 0x0D
#define I2C_FLEXEL_COMMAND_TURN_ON_UNDERLINE_CURSOR 0x0E
#define I2C_FLEXEL_COMMAND_TURN_OFF_UNDERLINE_CURSOR 0x0F
#define I2C_FLEXEL_COMMAND_MOVE_CURSOR_LEFT_ONE_SPACE 0x10
#define I2C_FLEXEL_COMMAND_MOVE_CURSOR_RIGHT_ONE_SPACE 0x11
#define I2C_FLEXEL_COMMAND_TURN_ON_BLINKING_CURSOR 0x12
#define I2C_FLEXEL_COMMAND_TURN_OFF_BLINKING_CURSOR 0x13
#define I2C_FLEXEL_COMMAND_CLEAR_LCD_SCREEN 0x14
#define I2C_FLEXEL_COMMAND_PRINT_STRING_ON_LCD 0x15
#define I2C_FLEXEL_COMMAND_LOAD_LCD_CUSTOM_CHARACTERS 0x1A

namespace I2CFlexel
{
	class I2CFlexel
	{
		public:
			/**
			 * Constructor and destructor
			 */
			I2CFlexel(IWire & wire) : connector(wire) {};
			virtual ~I2CFlexel() {};
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
		private:
			IWire & connector;
	};
}

#endif /* I2CFLEXEL_H_ */