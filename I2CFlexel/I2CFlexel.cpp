/**
 * I2CFlexel.cpp - I2C Flexel base class implementation
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */

#include "I2CFlexel.h"
#include "I2CIncludes.h"

namespace I2CFlexel
{
	void I2CFlexel::setWire(IWire& wire)
	{
		connector = &wire;
	}

	void I2CFlexel::beginCommand(byte command)
	{
		connector->beginTransmission(I2C_FLEXEL_ADDRESS);
		connector->write(I2C_FLEXEL_PREFIX);
		connector->write(command);
	}

	void I2CFlexel::sendCommandParameter(byte parameter)
	{
		connector->write(parameter);
	}

	void I2CFlexel::sendCommandParameters(byte* parameters, uint8_t count)
	{
		for (uint8_t i = 0; i < count; i++)
		{
			connector->write(parameters[i]);
		}
	}

	void I2CFlexel::endCommand()
	{
		connector->endTransmission();
	}

	void I2CFlexel::requestByte()
	{
		requestBytes(1);
	}

	void I2CFlexel::requestBytes(uint8_t count)
	{
		connector->requestFrom( (uint8_t) I2C_FLEXEL_ADDRESS, count);
	}

	byte I2CFlexel::readByte()
	{
		return (byte) connector->read();
	}

	void I2CFlexel::readBytes(byte* arr, uint8_t size)
	{
		byte *p = arr;
		for (int i = 0; i < size; i++)
		{
			*p++ = readByte();
		}
		*p = 0;
	}

	// Clock functions

	void I2CFlexel::getTime(byte* time)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_TIME);
		endCommand();
		requestBytes(3);
		readBytes(time, 3);
	}
	DateTime I2CFlexel::getTime()
	{
		byte time[3];
		getTime(time);
		return DateTime(bcdToDec(time[0]), bcdToDec(time[1]), bcdToDec(time[2]));
	}

	void I2CFlexel::getDate(byte *date)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_DATE);
		endCommand();
		requestBytes(4);
		readBytes(date, 4);
	}
	DateTime I2CFlexel::getDate()
	{
		byte date[4];
		getDate(date);
		return DateTime(bcdToDec(date[0]), bcdToDec(date[1]), bcdToDec(date[2]), bcdToDec(date[3]));
	}

	void I2CFlexel::getTimeAndDate(byte* timeAndDate)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_TIME_AND_DATE);
		endCommand();
		requestBytes(7);
		readBytes(timeAndDate, 7);
	}
	DateTime I2CFlexel::getTimeAndDate()
	{
		byte timeAndDate[7];
		getTimeAndDate(timeAndDate);
		return DateTime(
			bcdToDec(timeAndDate[0]), bcdToDec(timeAndDate[1]), bcdToDec(timeAndDate[2]), bcdToDec(timeAndDate[3]),
			bcdToDec(timeAndDate[4]), bcdToDec(timeAndDate[5]), bcdToDec(timeAndDate[6])
		);
	}

	void I2CFlexel::setTime(byte sec, byte min, byte hour)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_TIME);
		sendCommandParameter(sec);
		sendCommandParameter(min);
		sendCommandParameter(hour);
		endCommand();
	}
	void I2CFlexel::setTime(const DateTime &time)
	{
		setTime(decToBcd(time.seconds), decToBcd(time.minutes), decToBcd(time.hours));
	}

	void I2CFlexel::setDate(byte wday, byte day, byte month, byte year)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_DATE);
		sendCommandParameter(wday);
		sendCommandParameter(day);
		sendCommandParameter(month);
		sendCommandParameter(year);
		endCommand();
	}
	void I2CFlexel::setDate(const DateTime &date)
	{
		setDate(decToBcd(date.weekDay), decToBcd(date.day), decToBcd(date.month), decToBcd(date.year));
	}

	void I2CFlexel::setTimeAndDate(byte sec, byte min, byte hour, byte wday, byte day, byte month, byte year)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_TIME_AND_DATE);
		sendCommandParameter(sec);
		sendCommandParameter(min);
		sendCommandParameter(hour);
		sendCommandParameter(wday);
		sendCommandParameter(day);
		sendCommandParameter(month);
		sendCommandParameter(year);
		endCommand();
	}
	void I2CFlexel::setTimeAndDate(const DateTime &timeAndDate)
	{
		setTimeAndDate(
			decToBcd(timeAndDate.seconds), decToBcd(timeAndDate.minutes), decToBcd(timeAndDate.hours), decToBcd(timeAndDate.weekDay),
			decToBcd(timeAndDate.day), decToBcd(timeAndDate.month), decToBcd(timeAndDate.year)
		);
	}

	// Misc command functions

	byte I2CFlexel::getFirmwareVersion()
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_FIRMWARE_VERSION);
		endCommand();
		requestByte();
		return readByte();
	}

	void I2CFlexel::setHighPowerPin(const HighPowerPin &pin)
	{
		setHighPowerPin( (byte) pin);
	}
	void I2CFlexel::setHighPowerPin(byte pin)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_HIGH_POWER_PIN);
		sendCommandParameter(pin);
		endCommand();
	}

	void I2CFlexel::clearHighPowerPin(const HighPowerPin &pin)
	{
		clearHighPowerPin( (byte) pin);
	}
	void I2CFlexel::clearHighPowerPin(byte pin)
	{
		beginCommand(I2C_FLEXEL_COMMAND_CLEAR_HIGH_POWER_PIN);
		sendCommandParameter(pin);
		endCommand();
	}

	void I2CFlexel::setPwmForHighPowerPin(const HighPowerPin &pin, byte pwmValue)
	{
		setPwmForHighPowerPin( (byte) pin, pwmValue);
	}
	void I2CFlexel::setPwmForHighPowerPin(byte pin, byte pwmValue)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_PWM_FOR_HIGH_POWER_PIN);
		sendCommandParameter(pin);
		sendCommandParameter(pwmValue);
		endCommand();
	}

	void I2CFlexel::setServoMotorPosition(const ServoPin &pin, uint16_t position)
	{
		byte msb = position / 256;
		byte lsb = position - msb * 256;
		setServoMotorPosition( (byte) pin, msb, lsb);
	}
	void I2CFlexel::setServoMotorPosition(byte pin, byte msb, byte lsb)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_SERVO_MOTOR_POSITION);
		sendCommandParameter(pin);
		sendCommandParameter(msb);
		sendCommandParameter(lsb);
		endCommand();
	}

	void I2CFlexel::setPwmForDcMotor(const DcMotor &motor, const MotorDirection &direction, byte pwmValue)
	{
		byte motorAndPosition = (( (byte) motor << 1) + (byte) direction);
		setPwmForDcMotor(motorAndPosition, pwmValue);
	}
	void I2CFlexel::setPwmForDcMotor(byte motorAndPosition, byte pwmValue)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_PWM_FOR_DC_MOTOR);
		sendCommandParameter(motorAndPosition);
		sendCommandParameter(pwmValue);
		endCommand();
	}

	uint16_t I2CFlexel::getAnalogInputValue(const AnalogInputPin &pin)
	{
		byte analog[2];
		getAnalogInputValue( (byte) pin, analog);
		return (uint16_t) ((analog[0] << 8) + analog[1]);
	}
	void I2CFlexel::getAnalogInputValue(byte pin, byte* analog)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_ANALOG_INPUT_VALUE);
		sendCommandParameter(pin);
		endCommand();
		requestBytes(2);
		readBytes(analog, 2);
	}

	void I2CFlexel::setBuzzerTime(uint16_t ms)
	{
		byte count = (byte) (ms / buzzerMsPerCount);
		setBuzzerTime(count);
	}
	void I2CFlexel::setBuzzerTime(byte count)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_BUZZER_TIME);
		sendCommandParameter(count);
		endCommand();
	}

	// Input functions

	void I2CFlexel::setKeypadMode(const KeypadMode &mode)
	{
		setKeypadMode( (byte) mode);
		keypadMode = (byte) mode + I2C_FLEXEL_READ_KEY_BASE;
	}
	void I2CFlexel::setKeypadMode(byte mode)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_KEYPAD_MODE);
		sendCommandParameter(mode);
		endCommand();
	}

	byte I2CFlexel::readKeypad()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_KEYPAD);
	}

	byte I2CFlexel::readButtons()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_BUTTONS);
	}

	byte I2CFlexel::readPS2Keypad()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_PS2_KEYPAD);
	}

	byte I2CFlexel::readRemoteControl()
	{
		return readKey(I2C_FLEXEL_COMMAND_READ_REMOTE_CONTROL);
	}

	byte I2CFlexel::readKey(byte command)
	{
		beginCommand(command);
		endCommand();
		requestByte();
		return readByte();
	}
	byte I2CFlexel::readKey()
	{
		return readKey(keypadMode);
	}

	// LCD functions

	void I2CFlexel::setLcdBacklightBrightness(byte brightness)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_LCD_BACKLIGHT_BRIGHTNESS);
		sendCommandParameter(brightness);
		endCommand();
	}

	void I2CFlexel::setLcdContrast(byte contrast)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_LCD_CONTRAST);
		sendCommandParameter(contrast);
		endCommand();
	}

	void I2CFlexel::turnOnDisplay()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_ON_DISPLAY);
		endCommand();
	}

	void I2CFlexel::turnOffDisplay()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_OFF_DISPLAY);
		endCommand();
	}

	void I2CFlexel::setLcdCursorPosition(byte row, byte column)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_LCD_CURSOR_POSITION);
		sendCommandParameter(min(I2C_FLEXEL_LCD_MAX_ROWS_COUNT - 1, row));
		sendCommandParameter(min(I2C_FLEXEL_LCD_MAX_COLS_COUNT - 1, column));
		endCommand();
	}

	void I2CFlexel::homeCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_HOME_CURSOR);
		endCommand();
	}

	void I2CFlexel::turnOnUnderlineCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_ON_UNDERLINE_CURSOR);
		endCommand();
	}

	void I2CFlexel::turnOffUnderlineCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_OFF_UNDERLINE_CURSOR);
		endCommand();
	}

	void I2CFlexel::moveCursorLeftOneSpace()
	{
		beginCommand(I2C_FLEXEL_COMMAND_MOVE_CURSOR_LEFT_ONE_SPACE);
		endCommand();
	}

	void I2CFlexel::moveCursorRightOneSpace()
	{
		beginCommand(I2C_FLEXEL_COMMAND_MOVE_CURSOR_RIGHT_ONE_SPACE);
		endCommand();
	}

	void I2CFlexel::turnOnBlinkingCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_ON_BLINKING_CURSOR);
		endCommand();
	}

	void I2CFlexel::turnOffBlinkingCursor()
	{
		beginCommand(I2C_FLEXEL_COMMAND_TURN_OFF_BLINKING_CURSOR);
		endCommand();
	}

	void I2CFlexel::clearLcdScreen()
	{
		beginCommand(I2C_FLEXEL_COMMAND_CLEAR_LCD_SCREEN);
		endCommand();
	}

	void I2CFlexel::printStringOnLcd(const char *str)
	{
		printStringOnLcd(str, strlen(str));
	}

	void I2CFlexel::printStringOnLcd(const char *str, uint8_t length)
	{
		beginCommand(I2C_FLEXEL_COMMAND_PRINT_STRING_ON_LCD);
		sendCommandParameter(length);
		sendCommandParameters( (byte*) str, length);
		endCommand();
	}

	void I2CFlexel::loadLcdCustomCharacters(byte addr, byte *bitmap)
	{
		beginCommand(I2C_FLEXEL_COMMAND_LOAD_LCD_CUSTOM_CHARACTERS);
		sendCommandParameter(addr);
		sendCommandParameters(bitmap, I2C_FLEXEL_LCD_CHAR_ROWS_COUNT);
		endCommand();
	}
}