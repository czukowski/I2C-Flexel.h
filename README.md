I2C-Flexel.h library
====================

This library provides API for interaction with the [I2C-Flexel](http://www.web4robot.com/ArduinoShield.html)
Arduino Shield (note: I2C-FLEXEL name is © [www.web4robot.com](http://www.web4robot.com)).

The repo is a [Atmel Studio 6](http://www.atmel.com/microsite/atmel_studio6/default.aspx) solution directory.
Uses [Wire.h](https://github.com/czukowski/Wire.h) library.

Note that the included `*.cppproj` files have some Arduino and other dependencies in it. These include some
absolute paths that will unlikely match yours. See C++ Project properties -> Toolchain and update Directories
in AVR/GNU C Compiler, AVR/GNU C++ Compiler and Libraries in AVR/GNU Linker.

Has no evidence of working as of yet, since there are no unit tests at the moment, due to difficulties with
running them on Atmel Studio 6's AVR Simulator.