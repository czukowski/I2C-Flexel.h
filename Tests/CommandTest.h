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

test(setHighPowerPinTest)
{
	HighPowerPin pin = HIGHPOWER2;
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_HIGH_POWER_PIN, 0x02, '\0'};
	i2cFlexelSuite.object.setHighPowerPin(pin);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(clearHighPowerPinTest)
{
	HighPowerPin pin = HIGHPOWER3;
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_CLEAR_HIGH_POWER_PIN, 0x03, '\0'};
	i2cFlexelSuite.object.clearHighPowerPin(pin);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}

test(setPwmForHighPowerPinTest)
{
	HighPowerPin pin = HIGHPOWER1;
	const char expectedCommand[5] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_PWM_FOR_HIGH_POWER_PIN, 0x01, 0x56, '\0'};
	i2cFlexelSuite.object.setPwmForHighPowerPin(pin, 0x56);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	
}

test(setServoMotorPosition)
{
	ServoPin pin = SERVO4;
	const char expectedCommand[6] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_SERVO_MOTOR_POSITION, 0x04, 0x18, 0x59, '\0'};
	i2cFlexelSuite.object.setServoMotorPosition(pin, 0x18, 0x59);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	
}

#endif /* I2CFLEXEL_COMMANDTEST_H_ */