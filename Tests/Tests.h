/**
 * TestSuites.h - TestSuites definitions
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2CFLEXEL_TESTSUITES_H_
#define I2CFLEXEL_TESTSUITES_H_

#include <Arduino.h>
#include <ArduinoUnit.h>
#include <MockWire.h>
#include <I2CFlexel.h>

namespace I2CFlexel
{
	class I2CFlexelSuite : virtual public TestSuite
	{
		public:
			MockWire wire;
			I2CFlexel object;
			I2CFlexelSuite() : TestSuite("I2C Flexel tests") {}
			void setUp()
			{
				wire = MockWire();
				object = I2CFlexel();
				object.setWire(wire);
			}
	};
}

#endif /* I2CFLEXEL_TESTSUITES_H_ */