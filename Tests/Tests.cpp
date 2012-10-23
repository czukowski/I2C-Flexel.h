/**
 * Tests.cpp - Tests runner
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#include <ArduinoUnit.h>
#include <utility/NonReportingReporter.h>
#include <I2CFlexel.h>
#include <MockWire.h>
#include "Tests.h"

using namespace I2CFlexel;

I2CFlexelSuite i2cFlexelSuite;
#include "I2CFlexelTest.h"

int main(int argc, const char* argv[])
{
	NonReportingReporter nonReportingReporter;
	i2cFlexelSuite.setReporter(nonReportingReporter);
	i2cFlexelSuite.run();
	return 0;
}
