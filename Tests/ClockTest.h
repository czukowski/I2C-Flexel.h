/**
 * ClockTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_CLOCKTEST_H_
#define I2CFLEXEL_CLOCKTEST_H_

#include <Arduino.h>
#include <ArduinoUnit.h>
#include <I2CFlexel.h>
#include <MockWire.h>

test(getTimeTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_GET_TIME, '\0'};
	const char timeBuffer[4] = {0x01, 0x01, 0x12, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(timeBuffer);
	DateTime actualTime = i2cFlexelSuite.object->getTime();
	assertEquals(12, actualTime.hours);
	assertEquals(1, actualTime.minutes);
	assertEquals(1, actualTime.seconds);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);
	assertEquals(3, i2cFlexelSuite.wire->requestedFromQuantity);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,endTransmission,requestFrom,read,read,read", i2cFlexelSuite.wire->methodCalls);
}

test(getDateTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_GET_DATE, '\0'};
	const char dateBuffer[5] = {0x00, 0x01, 0x12, 0x88, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(dateBuffer, 4);
	DateTime actualDate = i2cFlexelSuite.object->getDate();
	assertEquals(88, actualDate.year);
	assertEquals(12, actualDate.month);
	assertEquals(1, actualDate.day);
	assertEquals(0, actualDate.weekDay);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);
	assertEquals(4, i2cFlexelSuite.wire->requestedFromQuantity);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,endTransmission,requestFrom,read,read,read,read", i2cFlexelSuite.wire->methodCalls);
}

test(getTimeAndDateTest)
{
	const char expectedCommand[3] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_GET_TIME_AND_DATE, '\0'};
	const char dateTimeBuffer[8] = {0x31, 0x28, 0x11, 0x04, 0x05, 0x08, 0x12, '\0'};
	i2cFlexelSuite.wire->addToRxBuffer(dateTimeBuffer, 7);
	DateTime actualTimeAndDate = i2cFlexelSuite.object->getTimeAndDate();
	assertEquals(12, actualTimeAndDate.year);
	assertEquals(8, actualTimeAndDate.month);
	assertEquals(5, actualTimeAndDate.day);
	assertEquals(4, actualTimeAndDate.weekDay);
	assertEquals(11, actualTimeAndDate.hours);
	assertEquals(28, actualTimeAndDate.minutes);
	assertEquals(31, actualTimeAndDate.seconds);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->requestedFromAddress);
	assertEquals(7, i2cFlexelSuite.wire->requestedFromQuantity);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,endTransmission,requestFrom,read,read,read,read,read,read,read", i2cFlexelSuite.wire->methodCalls);
}

test(setTimeTest)
{
	const char expectedCommand[6] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_TIME, 0x05, 0x12, 0x08, '\0'};
	DateTime time = DateTime(5, 12, 8);
	i2cFlexelSuite.object->setTime(time);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire->methodCalls);
}

test(setDateTest)
{
	const char expectedCommand[7] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_DATE, 0x01, 0x21, 0x08, 0x99, '\0'};
	DateTime date = DateTime(1, 21, 8, 99);
	i2cFlexelSuite.object->setDate(date);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire->methodCalls);
}

test(setTimeAndDateTest)
{
	const char expectedCommand[10] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_TIME_AND_DATE, 0x00, 0x00, 0x12, 0x05, 0x11, 0x09, 0x12, '\0'};
	DateTime timeAndDate = DateTime(0, 0, 12, 5, 11, 9, 12);
	i2cFlexelSuite.object->setTimeAndDate(timeAndDate);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire->transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire->writtenData);
	assertEquals("beginTransmission,write,write,write,write,write,write,write,write,write,endTransmission", i2cFlexelSuite.wire->methodCalls);
}

#endif /* I2CFLEXEL_CLOCKTEST_H_ */