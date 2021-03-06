/**
 * I2CIncludes.h
 *
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2C_FLEXEL_INCLUDES_H_
#define I2C_FLEXEL_INCLUDES_H_

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

// Helper constants
#define I2C_FLEXEL_READ_KEY_BASE I2C_FLEXEL_COMMAND_READ_KEYPAD;
#define I2C_FLEXEL_BUZZER_MS_PER_COUNT 0x05
#define I2C_FLEXEL_LCD_MAX_ROWS_COUNT 0x04
#define I2C_FLEXEL_LCD_MAX_COLS_COUNT 0x14
#define I2C_FLEXEL_LCD_CHAR_ROWS_COUNT 0x08

namespace I2CFlexel
{
	/**
	 * Enumerations
	 */
	enum HighPowerPin {HIGHPOWER1 = 0x01, HIGHPOWER2 = 0x02, HIGHPOWER3 = 0x03, HIGHPOWER4 = 0x04};
	enum ServoPin {SERVO1 = 0x01, SERVO2 = 0x02, SERVO3 = 0x03, SERVO4 = 0x04};
	enum DcMotor {MOTOR1 = 0x00, MOTOR2 = 0x01};
	enum MotorDirection {FORWARD = 0x00, REVERSE = 0x01};
	enum AnalogInputPin {INPUT1 = 0x01, INPUT2 = 0x02, INPUT3 = 0x03, INPUT4 = 0x04};
	enum KeypadMode {KEYPAD_4X4 = 0x00, KEYPAD_8 = 0x01, KEYPAD_PS2 = 0x02};

	/**
	 * Structure to hold date and time values
	 */
	struct DateTime
	{
		byte seconds;
		byte minutes;
		byte hours;
		byte weekDay;
		byte day;
		byte month;
		byte year;
		DateTime(byte sec, byte min, byte hour)
		{
			setTime(sec, min, hour);
		};
		DateTime(byte wday, byte day, byte month, byte year)
		{
			setDate(wday, day, month, year);
		};
		DateTime(byte sec, byte min, byte hour, byte wday, byte day, byte month, byte year)
		{
			setTime(sec, min, hour);
			setDate(wday, day, month, year);
		};
		void setDate(byte wday_, byte day_, byte month_, byte year_)
		{
			weekDay = wday_;
			day = day_;
			month = month_;
			year = year_;
		};
		void setTime(byte sec, byte min, byte hour)
		{
			seconds = sec;
			minutes = min;
			hours = hour;
		};
	};
}

#endif /* I2C_FLEXEL_INCLUDES_H_ */