/**
 * CommandTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_COMMANDTEST_H_
#define I2CFLEXEL_COMMANDTEST_H_

#include <Arduino.h>
#include <ArduinoUnit.h>
#include <I2CFlexel.h>
#include <MockWire.h>

test(getFirmwareVersionTest)
{
	const char firmwareVersionBuffer[2] = {0x01, '\0'};
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_GET_FIRMWARE_VERSION, '\0'};
	i2cFlexelSuite.wire.addToRxBuffer(firmwareVersionBuffer);
	assertEquals(0x01, i2cFlexelSuite.object.getFirmwareVersion());
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.requestedFromAddress);
	assertEquals(1, i2cFlexelSuite.wire.requestedFromQuantity);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,endTransmission,requestFrom,read", i2cFlexelSuite.wire.methodCalls);
}

test(setBuzzerTimeTest)
{
	uint16_t buzzerTime = 1270;
	// 1270 / 5 = 254 = 0xFE
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_BUZZER_TIME, 0xFE, '\0'};
	i2cFlexelSuite.object.setBuzzerTime(buzzerTime);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(getAnalogInputValueTest)
{
	AnalogInputPin pin = INPUT2;
	// 19473 = 0100 1100 0001 0001 = 0x4C 0x11;
	const char analogInputBuffer[3] = {0x4C, 0x11, '\0'};
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_GET_ANALOG_INPUT_VALUE, 0x02, '\0'};
	i2cFlexelSuite.wire.addToRxBuffer(analogInputBuffer);
	uint16_t actual = i2cFlexelSuite.object.getAnalogInputValue(pin);
	assertEquals(19473, actual);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.requestedFromAddress);
	assertEquals(2, i2cFlexelSuite.wire.requestedFromQuantity);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission,requestFrom,read,read", i2cFlexelSuite.wire.methodCalls);
}

#endif /* I2CFLEXEL_COMMANDTEST_H_ */