/**
 * Clock.cpp - I2C Flexel Clock class implementation
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements the RTCC commands supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */

#include "I2CFlexel.h"
#include "Clock.h"

namespace I2CFlexel
{
	void Clock::getTime(byte* time)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_TIME);
		endCommand();
		requestBytes(3);
		readBytes(time, 3);
	}
	DateTime Clock::getTime()
	{
		byte time[3];
		getTime(time);
		return DateTime(bcdToDec(time[0]), bcdToDec(time[1]), bcdToDec(time[2]));
	}

	void Clock::getDate(byte *date)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_DATE);
		endCommand();
		requestBytes(4);
		readBytes(date, 4);
	}
	DateTime Clock::getDate()
	{
		byte date[4];
		getDate(date);
		return DateTime(bcdToDec(date[0]), bcdToDec(date[1]), bcdToDec(date[2]), bcdToDec(date[3]));
	}

	void Clock::getTimeAndDate(byte* timeAndDate)
	{
		beginCommand(I2C_FLEXEL_COMMAND_GET_TIME_AND_DATE);
		endCommand();
		requestBytes(7);
		readBytes(timeAndDate, 7);
	}
	DateTime Clock::getTimeAndDate()
	{
		byte timeAndDate[7];
		getTimeAndDate(timeAndDate);
		return DateTime(
			bcdToDec(timeAndDate[0]), bcdToDec(timeAndDate[1]), bcdToDec(timeAndDate[2]), bcdToDec(timeAndDate[3]),
			bcdToDec(timeAndDate[4]), bcdToDec(timeAndDate[5]), bcdToDec(timeAndDate[6])
		);
	}

	void Clock::setTime(byte sec, byte min, byte hour)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_TIME);
		sendCommandParameter(sec);
		sendCommandParameter(min);
		sendCommandParameter(hour);
		endCommand();
	}
	void Clock::setTime(DateTime time)
	{
		setTime(decToBcd(time.seconds), decToBcd(time.minutes), decToBcd(time.hours));
	}

	void Clock::setDate(byte wday, byte day, byte month, byte year)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_DATE);
		sendCommandParameter(wday);
		sendCommandParameter(day);
		sendCommandParameter(month);
		sendCommandParameter(year);
		endCommand();
	}
	void Clock::setDate(DateTime date)
	{
		setDate(decToBcd(date.weekDay), decToBcd(date.day), decToBcd(date.month), decToBcd(date.year));
	}

	void Clock::setTimeAndDate(byte sec, byte min, byte hour, byte wday, byte day, byte month, byte year)
	{
		beginCommand(I2C_FLEXEL_COMMAND_SET_TIME_AND_DATE);
		sendCommandParameter(sec);
		sendCommandParameter(min);
		sendCommandParameter(hour);
		sendCommandParameter(wday);
		sendCommandParameter(day);
		sendCommandParameter(month);
		sendCommandParameter(year);
		endCommand();
	}
	void Clock::setTimeAndDate(DateTime timeAndDate)
	{
		setTimeAndDate(
			decToBcd(timeAndDate.seconds), decToBcd(timeAndDate.minutes), decToBcd(timeAndDate.hours), decToBcd(timeAndDate.weekDay),
			decToBcd(timeAndDate.day), decToBcd(timeAndDate.month), decToBcd(timeAndDate.year)
		);
	}
}