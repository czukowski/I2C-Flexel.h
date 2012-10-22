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
		return connector->read();
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
}