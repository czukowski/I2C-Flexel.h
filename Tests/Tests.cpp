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

// Test I2C-Flexel core methods
//#include "I2CFlexelTest.h"
// Test date and time related commands
//#include "ClockTest.h"
// Test misc I2C-Flexel commands
#include "CommandTest.h"
// Test set output pins and motor commands
#include "OutputTest.h"
// Test keypad commands
//#include "KeypadTest.h"

int main(int argc, const char* argv[])
{
	NonReportingReporter nonReportingReporter;
	i2cFlexelSuite.setReporter(nonReportingReporter);
	i2cFlexelSuite.run();
	return 0;
}
