/**
 * InputTest.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_INPUTTEST_H_
#define I2CFLEXEL_INPUTTEST_H_

test(setKeypadModeTest)
{
	KeypadMode mode = KEYPAD_8;
	const char expectedCommand[4] = {I2C_FLEXEL_PREFIX, I2C_FLEXEL_COMMAND_SET_KEYPAD_MODE, 0x01, '\0'};
	i2cFlexelSuite.object.setKeypadMode(mode);
	assertEquals(I2C_FLEXEL_ADDRESS, i2cFlexelSuite.wire.transmitAddress);
	assertEquals(expectedCommand, i2cFlexelSuite.wire.writtenData);
	assertEquals("beginTransmission,write,write,write,endTransmission", i2cFlexelSuite.wire.methodCalls);
}



#endif /* I2CFLEXEL_INPUTTEST_H_ */