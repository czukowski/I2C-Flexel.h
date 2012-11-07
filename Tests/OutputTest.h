/**
 * OutputTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_OUTPUTTEST_H_
#define I2CFLEXEL_OUTPUTTEST_H_

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

#endif /* I2CFLEXEL_OUTPUTTEST_H_ */