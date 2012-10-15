/**
 * Clock.h - I2C Flexel Clock class
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements the RTCC commands supported by the I2C-FLEXEL board.
 * BCD <-> DEC conversion is handled automatically
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2C_FLEXEL_CLOCK_H_
#define I2C_FLEXEL_CLOCK_H_

#include <Arduino.h>

namespace I2CFlexel
{
	/**
	 * Structure to hold date and time values
	 */
	struct DateTime
	{
		DateTime(byte sec, byte min, byte hour) : seconds(sec), minutes(min), hours(hours) {};
		DateTime(byte wday, byte day, byte month, byte year) : weekDay(wday), day(day), month(month), year(year) {};
		DateTime(byte sec, byte min, byte hour, byte wday, byte day, byte month, byte year) : seconds(sec), minutes(min), hours(hours), weekDay(wday), day(day), month(month), year(year) {};
		byte seconds;
		byte minutes;
		byte hours;
		byte weekDay;
		byte day;
		byte month;
		byte year;
	};

	class Clock : protected I2CFlexel
	{
		/**
		 * Public class methods
		 */
		public:
			/**
			 * Returns DateTime structure with the current time
			 */
			DateTime getTime();
			/**
			 * Returns DateTime structure with the current date
			 */
			DateTime getDate();
			/**
			 * Returns DateTime structure with the current date and time
			 */
			DateTime getTimeAndDate();
			/**
			 * Sets time from the provided DateTime struct
			 */
			void setTime(DateTime time);
			/**
			 * Sets date from the provided DateTime struct
			 */
			void setDate(DateTime date);
			/**
			 * Sets time and date from the provided DateTime struct
			 */
			void setTimeAndDate(DateTime dateTime);
		/**
		 * Some commands are protected methods to try and prevent invalid values coming into them.
		 * For such commands public methods with constrained parameters are also provided.
		 */
		protected:
			/**
			 * Writes 3 data bytes into provided argument.
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 */
			void getTime(byte* time);
			/**
			 * Writes 4 data bytes into provided argument.
			 * Byte 1 – day of the week (BCD codification, 00-06)
			 * Byte 2 – day of the month (BCD codification, 01-31)
			 * Byte 3 – month (BCD codification, 01-12)
			 * Byte 4 – year (BCD codification, 00-99)
			 */
			void getDate(byte* date);
			/**
			 * Writes 7 data bytes into provided argument.
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 * Byte 4 – day of the week (BCD codification, 00-06)
			 * Byte 5 – day of the month (BCD codification, 01-31)
			 * Byte 6 – month (BCD codification, 01-12)
			 * Byte 7 – year (BCD codification, 00-99)
			 */
			void getTimeAndDate(byte* timeAndDate);
			/**
			 * Sets the time from the provided 3 bytes
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 */
			void setTime(byte sec, byte min, byte hour);
			/**
			 * Sets the date from the provided 4 bytes
			 * Byte 1 – day of the week (BCD codification, 00-06)
			 * Byte 2 – day of the month (BCD codification, 01-31)
			 * Byte 3 – month (BCD codification, 01-12)
			 * Byte 4 – year (BCD codification, 00-99)
			 */
			void setDate(byte wday, byte day, byte month, byte year);
			/**
			 * Sets the time and date from the provided 7 bytes
			 * Byte 1 – seconds (BCD codification, 00-59)
			 * Byte 2 – minutes (BCD codification, 00-59)
			 * Byte 3 – hours (BCD codification, 00-24)
			 * Byte 4 – day of the week (BCD codification, 00-06)
			 * Byte 5 – day of the month (BCD codification, 01-31)
			 * Byte 6 – month (BCD codification, 01-12)
			 * Byte 7 – year (BCD codification, 00-99)
			 */
			void setTimeAndDate(byte sec, byte min, byte hour, byte wday, byte day, byte month, byte year);
		/**
		 * BCD conversion and some other helper functions are private methods
		 */
		private:
			/**
			 * Convert normal BCD codification numbers to binary coded BCD codification
			 */
			byte decToBcd(byte val) { return ((val / 10 * 16) + (val % 10)); };
			/**
			 * Convert binary coded BCD codification to normal BCD codification numbers
			 */
			byte bcdToDec(byte val) { return ((val / 16 * 10) + (val % 16)); };
	};
}

#endif /* I2C_FLEXEL_CLOCK_H_ */