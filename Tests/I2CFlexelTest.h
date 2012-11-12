/**
 * I2CFlexelTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_TEST_H_
#define I2CFLEXEL_TEST_H_

#include <Arduino.h>
#include <ArduinoUnit.h>
#include <I2CFlexel.h>
#include <MockWire.h>

test(beginCommandTest)
{
	i2cFlexelSuite.object->beginCommand(0x01);
	assertEquals(1, i2cFlexelSuite.wire->transmitting);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	char expectedData[] = {I2C_FLEXEL_PREFIX, 0x01, '\0'};
	assertEquals(expectedData, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write", i2cFlexelSuite.wire->methodCalls);
}

test(sendCommandParameterTest)
{
	i2cFlexelSuite.wire->transmitting = 1;
	i2cFlexelSuite.object->sendCommandParameter(0x01);
	i2cFlexelSuite.object->sendCommandParameter(0x02);
	char expectedData[] = {0x01, 0x02, '\0'};
	assertEquals(expectedData, i2cFlexelSuite.wire->writtenData);
	assertEquals("write,write", i2cFlexelSuite.wire->methodCalls);	
}

test(sendCommandParametersTest)
{
	i2cFlexelSuite.wire->transmitting = 1;
	char parameters[] = "str";
	i2cFlexelSuite.object->sendCommandParameters( (byte*) parameters, strlen(parameters));
	assertEquals(parameters, i2cFlexelSuite.wire->writtenData);
	assertEquals("write,write,write", i2cFlexelSuite.wire->methodCalls);
}

test(endCommandTest)
{
	i2cFlexelSuite.object->endCommand();
	assertEquals("endTransmission", i2cFlexelSuite.wire->methodCalls);
}

test(requestByteTest)
{
	i2cFlexelSuite.wire->addToRxBuffer("rx buffer content");
	i2cFlexelSuite.object->requestByte();
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);
	assertEquals(1, i2cFlexelSuite.wire->requestedFromQuantity);
	assertEquals(true, i2cFlexelSuite.wire->requestedFromSentStop);
	assertEquals("requestFrom", i2cFlexelSuite.wire->methodCalls);
}

test(requestBytesTest)
{
	i2cFlexelSuite.wire->addToRxBuffer("rx buffer content");
	i2cFlexelSuite.object->requestBytes(BUFFER_LENGTH * 2);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);
	assertEquals(BUFFER_LENGTH, i2cFlexelSuite.wire->requestedFromQuantity);
	assertEquals(true, i2cFlexelSuite.wire->requestedFromSentStop);
	assertEquals("requestFrom", i2cFlexelSuite.wire->methodCalls);
}

test(readByteTest)
{
	i2cFlexelSuite.wire->addToRxBuffer("content");
	assertEquals('c', i2cFlexelSuite.object->readByte());
	assertEquals(1, i2cFlexelSuite.wire->rxBufferIndex);
	assertEquals("read", i2cFlexelSuite.wire->methodCalls);
}

test(readByteFromEmptyBufferTest)
{
	assertEquals( (byte) -1, i2cFlexelSuite.object->readByte());
	assertEquals(0, i2cFlexelSuite.wire->rxBufferIndex);
	assertEquals("read", i2cFlexelSuite.wire->methodCalls);
}

test(readBytesFromMiddleTest)
{
	char readFromBuffer[6];
	i2cFlexelSuite.wire->addToRxBuffer("content");
	i2cFlexelSuite.wire->rxBufferIndex = 1;
	i2cFlexelSuite.object->readBytes( (byte*) readFromBuffer, 5);
	assertEquals(6, i2cFlexelSuite.wire->rxBufferIndex);
	assertEquals("onten", readFromBuffer);
	assertEquals("read,read,read,read,read", i2cFlexelSuite.wire->methodCalls);
}

#endif /* TESTSUITES_H_ */