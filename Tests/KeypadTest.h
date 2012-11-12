/**
 * KeypadTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_KEYPADTEST_H_
#define I2CFLEXEL_KEYPADTEST_H_

test(setKeypadModeTest)
{
	KeypadMode mode = KEYPAD_8;
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_KEYPAD_MODE, 0x01, '\0'};
	i2cFlexelSuite.object->setKeypadMode(mode);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire->methodCalls);
}

test(readKeyTest)
{
	KeypadMode mode = KEYPAD_8;
	const char expectedCommand[6] = {
		I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_KEYPAD_MODE, 0x01, I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_READ_BUTTONS, '\0'
	};
	const char inputBuffer[2] = {0x31, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(inputBuffer);
	i2cFlexelSuite.object->setKeypadMode(mode);
	assertEquals(0x31, i2cFlexelSuite.object->readKey());
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);
	assertEquals(1, i2cFlexelSuite.wire->requestedFromQuantity);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission,beginTransmission,write,write,endTransmission,requestFrom,read", i2cFlexelSuite.wire->methodCalls);
}

#define assertReadKey(expectedValue, expectedCommand, actualValue)\
	assertEquals(expectedValue, actualValue);\
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);\
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);\
	assertEquals(1, i2cFlexelSuite.wire->requestedFromQuantity);\
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);\
	assertEquals("beginTransmission,write,write,endTransmission,requestFrom,read", i2cFlexelSuite.wire->methodCalls);

test(readKeypadTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_READ_KEYPAD, '\0'};
	const char inputBuffer[2] = {0x01, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(inputBuffer);
	assertReadKey(0x01, expectedCommand, i2cFlexelSuite.object->readKeypad());
}

test(readButtonsTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_READ_BUTTONS, '\0'};
	const char inputBuffer[2] = {0x08, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(inputBuffer);
	assertReadKey(0x08, expectedCommand, i2cFlexelSuite.object->readButtons());
}

test(readPS2KeypadTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_READ_PS2_KEYPAD, '\0'};
	const char inputBuffer[2] = {0x05, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(inputBuffer);
	assertReadKey(0x05, expectedCommand, i2cFlexelSuite.object->readPS2Keypad());
}

test(readRemoteControlTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_READ_REMOTE_CONTROL, '\0'};
	const char inputBuffer[2] = {0x15, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(inputBuffer);
	assertReadKey(0x15, expectedCommand, i2cFlexelSuite.object->readRemoteControl());
}

#endif /* I2CFLEXEL_KEYPADTEST_H_ */