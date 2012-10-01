/**
 * Command.cpp - I2C Flexel Command class implementation
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements the commands other than LCD supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */

#include "I2CFlexel.h"
#include "Command.h"

namespace I2CFlexel
{
	byte Command::getFirmwareVersion()
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_FIRMWARE_VERSION);
		endCommand();
		requestByte();
		return readByte();
	}

	void Command::setHighPowerPin(HighPowerPin pin)
	{
		setHighPowerPin( (byte) pin);
	}
	void Command::setHighPowerPin(byte pin)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_HIGH_POWER_PIN);
		sendCommandParameter(pin);
		endCommand();
	}

	void Command::clearHighPowerPin(HighPowerPin pin)
	{
		clearHighPowerPin( (byte) pin);
	}
	void Command::clearHighPowerPin(byte pin)
	{
		beginCommand(I2C_FLEXEL_COMMAND_CLEAR_HIGH_POWER_PIN);
		sendCommandParameter(pin);
		endCommand();
	}

	void Command::setPwmForHighPowerPin(HighPowerPin pin, byte pwmValue)
	{
		setPwmForHighPowerPin( (byte) pin, pwmValue);
	}
	void Command::setPwmForHighPowerPin(byte pin, byte pwmValue)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_PWM_FOR_HIGH_POWER_PIN);
		sendCommandParameter(pwmValue);
		endCommand();
	}

	void Command::setServoMotorPosition(ServoPin pin, byte msb, byte lsb)
	{
		// TODO: improve this
		setServoMotorPosition( (byte) pin, msb, lsb);
	}
	void Command::setServoMotorPosition(byte pin, byte msb, byte lsb)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_SERVO_MOTOR_POSITION);
		sendCommandParameter(pin);
		sendCommandParameter(msb);
		sendCommandParameter(lsb);
		endCommand();
	}

	void Command::setPwmForDcMotor(DcMotor motor, MotorDirection direction, byte pwmValue)
	{
		setPwmForDcMotor(( (byte) (motor << 2) + (byte) direction), pwmValue);
	}
	void Command::setPwmForDcMotor(byte motorAndPosition, byte pwmValue)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_PWM_FOR_DC_MOTOR);
		sendCommandParameter(motorAndPosition);
		sendCommandParameter(pwmValue);
		endCommand();
	}

	uint16_t Command::getAnalogInputValue(AnalogInputPin pin)
	{
		byte analog[2];
		getAnalogInputValue( (byte) pin, analog);
		return (uint16_t) ((analog[0] << 8) + analog[1]);
	}
	void Command::getAnalogInputValue(byte pin, byte* analog)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_ANALOG_INPUT_VALUE);
		sendCommandParameter(pin);
		endCommand();
		requestBytes(2);
		readBytes(analog, 2);
	}

	void Command::setBuzzerTime(uint16_t ms)
	{
		setBuzzerTime( (byte) floor(ms / buzzerMsPerCount));
	}
	void Command::setBuzzerTime(byte count)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_BUZZER_TIME);
		sendCommandParameter(count);
		endCommand();
	}

}