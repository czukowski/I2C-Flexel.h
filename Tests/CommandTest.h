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
	byte pwmValue = 0x56;
	const char expectedCommand[5] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_PWM_FOR_HIGH_POWER_PIN, 0x01, 0x56, '\0'};
	i2cFlexelSuite.object.setPwmForHighPowerPin(pin, pwmValue);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	
}

#define assertServoMotorPosition(motor, msb, lsb)\
	const char expectedCommand[6] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_SERVO_MOTOR_POSITION, motor, msb, lsb, '\0'};\
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);\
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);\
	assertEquals("beginTransmission,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);

test(setServoMotorPosition0Test)
{
	ServoPin pin = SERVO1;
	int position = 0;
	i2cFlexelSuite.object.setServoMotorPosition(pin, position);
	assertServoMotorPosition(0x01, 0x00, 0x00);
}

test(setServoMotorPosition1Test)
{
	ServoPin pin = SERVO2;
	int position = 1;
	i2cFlexelSuite.object.setServoMotorPosition(pin, position);
	assertServoMotorPosition(0x02, 0x00, 0x01);
}

test(setServoMotorPosition256Test)
{
	ServoPin pin = SERVO3;
	int position = 256;
	i2cFlexelSuite.object.setServoMotorPosition(pin, position);
	assertServoMotorPosition(0x03, 0x01, 0x00);
}

test(setServoMotorPosition6233Test)
{
	ServoPin pin = SERVO4;
	int position = 6233;
	i2cFlexelSuite.object.setServoMotorPosition(pin, position);
	// 6233 = 0001 1000 0101 1001 = 0x18 0x59;
	assertServoMotorPosition(0x04, 0x18, 0x59);
}

#define assertPwmForDcMotor(motorAndDirection, pwmValue)\
	const char expectedCommand[5] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_PWM_FOR_DC_MOTOR, motorAndDirection, pwmValue, '\0'};\
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);\
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);\
	assertEquals("beginTransmission,write,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	

test(setPwmForDcMotor1ForwardTest)
{
	DcMotor motor = MOTOR1;
	MotorDirection direction = FORWARD;
	i2cFlexelSuite.object.setPwmForDcMotor(motor, direction, 0x11);
	assertPwmForDcMotor(0x00, 0x11);
}

test(setPwmForDcMotor1ReverseTest)
{
	DcMotor motor = MOTOR1;
	MotorDirection direction = REVERSE;
	i2cFlexelSuite.object.setPwmForDcMotor(motor, direction, 0x41);
	assertPwmForDcMotor(0x01, 0x41);
}

test(setPwmForDcMotor2ForwardTest)
{
	DcMotor motor = MOTOR2;
	MotorDirection direction = FORWARD;
	i2cFlexelSuite.object.setPwmForDcMotor(motor, direction, 0x18);
	assertPwmForDcMotor(0x02, 0x18);
}

test(setPwmForDcMotor2ReverseTest)
{
	DcMotor motor = MOTOR2;
	MotorDirection direction = REVERSE;
	i2cFlexelSuite.object.setPwmForDcMotor(motor, direction, 0x51);
	assertPwmForDcMotor(0x03, 0x51);
}

test(getAnalogInputValueTest)
{
	// TODO: find out why this fails
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

test(setBuzzerTimeTest)
{
	// TODO: find out why this fails
	uint16_t buzzerTime = 1270;
	// 1270 / 5 = 254 = 0xFE
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_BUZZER_TIME, 0xFE, '\0'};
	i2cFlexelSuite.object.setBuzzerTime(buzzerTime);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);	
}

#endif /* I2CFLEXEL_COMMANDTEST_H_ */