/**
 * Command.h - I2C Flexel Command class
 * 
 * Note: I2C-FLEXEL name is (c) http://www.web4robot.com
 * 
 * This class implements the commands other than LCD supported by the I2C-FLEXEL board.
 * 
 * Author:     Korney Czukowski (https://github.com/czukowski)
 * Copyright:  (c) 2012 Korney Czukowski
 * License:    MIT License
 */
#ifndef I2C_FLEXEL_COMMAND_H_
#define I2C_FLEXEL_COMMAND_H_

#include <Arduino.h>

namespace I2CFlexel
{
	enum HighPowerPin {HIGHPOWER1 = 1, HIGHPOWER2 = 2, HIGHPOWER3 = 3, HIGHPOWER4 = 4};
	enum ServoPin {SERVO1 = 1, SERVO2 = 2, SERVO3 = 3, SERVO4 = 4};
	enum DcMotor {MOTOR1 = 0x00, MOTOR2 = 0x01};
	enum MotorDirection {FORWARD = 0x02, REVERSE = 0x03};
	enum AnalogInputPin {INPUT1 = 1, INPUT2 = 2, INPUT3 = 3, INPUT4 = 4};
	/**
	 * Buzzer ms per counts conversion rate
	 */
	const byte buzzerMsPerCount = 5;

	class Command : protected I2CFlexel
	{
		/**
		 * Public class methods
		 */
		public:
			/**
			 * Returns data byte with firmware version number.
			 */
			byte getFirmwareVersion();
			/**
			 * Calls the `setHighPowerPin` method with the converted argument set
			 */
			void setHighPowerPin(HighPowerPin pin);
			/**
			 * Calls the `clearHighPowerPin` method with the converted argument set
			 */
			void clearHighPowerPin(HighPowerPin pin);
			/**
			 * Calls the `setPwmForHighPowerPin` method with the converted argument set
			 */
			void setPwmForHighPowerPin(HighPowerPin pin, byte pwmValue);
			/**
			 * Calls the `setServoMotorPosition` method with the converted argument set
			 */
			void setServoMotorPosition(ServoPin pin, byte msb, byte lsb);
			/**
			 * Calls the `setPwmForDcMotor` method with the converted argument set
			 */
			void setPwmForDcMotor(DcMotor motor, MotorDirection direction, byte pwmValue);
			/**
			 * Calls the `getAnalogInputValue` method with the converted argument set
			 */
			uint16_t getAnalogInputValue(AnalogInputPin pin);
			/**
			 * Calls the `setBuzzerTime` method with the converted argument set
			 */
			void setBuzzerTime(uint16_t ms);
		/**
		 * Some commands are protected methods to try and prevent invalid values coming into them.
		 * For such commands public methods with constrained parameters are also provided.
		 */
		protected:
			/**
			 * This command sets the high power pin, the single byte parameter select the pin
			 * number in range from 1 to 4.
			 */
			void setHighPowerPin(byte pin);
			/**
			 * This command reset the high power pin, the single byte parameter select the pin
			 * number in range from 1 to 4.
			 */
			void clearHighPowerPin(byte pin);
			/**
			 * This command sets the high power pin as PWM output with PWM duty cycle
			 * according [pwmValue]. The first parameter [pin] selects the pin number.
			 * The pin number – from 1 to 4, PWM value – from 0 to 255.
			 * Note: PWM frequency is 100 Hz. Use this pin mode for high power LED dimming
			 * or the heater control.
			 */
			void setPwmForHighPowerPin(byte pin, byte pwmValue);
			/**
			 * This command sets the servo motor position. The first parameter [servo] selects
			 * the servo motor in range from 1 to 4. [MSB] and [LSB] bytes define the servo motor
			 * position in range from 600 to 2400 with 1 microsecond resolution.
			 * Note: The module embedded microcontroller pins are shared between the high power
			 * outputs and servo motor control.
			 * For example, if you use a high power pin 2 to control relay, you can not use servo
			 * motor with number 2.
			 */
			void setServoMotorPosition(byte pin, byte msb, byte lsb);
			/**
			 * This command sets the direction and PWM duty cycle for DC motor. The first
			 * parameter [mot/dir] selects the motor and direction, the second byte [pwm] defines the PWM
			 * duty cycle in range from 0 to 255.
			 * First parameter [mot/dir] format: Bit 2 defines the motor: 0 – motor 1, 1 – motor 2; Bit 1 –
			 * sets the motor direction: 0 – forward, 1 – reverse.
			 */
			void setPwmForDcMotor(byte motorAndPosition, byte pwmValue);
			/**
			 * Reads the analog input. Data byte defines the input number in range from 1 to 4. Module
			 * returns 2 data bytes with 12 bit ADC value.
			 */
			void getAnalogInputValue(byte pin, byte* analog);
			/**
			 * Initiates the buzzer pulse. Data byte defines the buzzer pulse time. Data byte value is in range from 1 to
			 * 255 counts. 1 count = 5 milliseconds. The buzzer pulse frequency is 2 KHz.
			 */
			void setBuzzerTime(byte count);
	};
}

#endif /* I2C_FLEXEL_COMMAND_H_ */