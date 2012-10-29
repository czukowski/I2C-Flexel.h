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

// Uncomment tests you want to run; all of them won't fit into 2k of RAM

//#include "I2CFlexelTest.h"
//#include "ClockTest.h"
#include "CommandTest.h"

int main(int argc, const char* argv[])
{
	NonReportingReporter nonReportingReporter;
	i2cFlexelSuite.setReporter(nonReportingReporter);
	i2cFlexelSuite.run();
	return 0;
}
