I2C-Flexel.h library
====================

This library provides API for interaction with the I2C-Flexel Arduino Shield (note: I2C-FLEXEL name is
© web4robot.com - this website appears to be not functioning anymore).

The repo is a [Atmel Studio 6](http://www.atmel.com/microsite/atmel_studio6/default.aspx) solution directory.
Uses [Wire.h](https://github.com/czukowski/Wire.h) library.

Note that the included `*.cppproj` files have some Arduino and other dependencies in it. These include some
absolute paths that will unlikely match yours. See C++ Project properties -> Toolchain and update Directories
in AVR/GNU C Compiler, AVR/GNU C++ Compiler and Libraries in AVR/GNU Linker.

Has no evidence of working as of yet, since there are no unit tests at the moment, due to difficulties with
running them on Atmel Studio 6's AVR Simulator.

I2C-Flexel documentation
------------------------

Since it's come to my attention that the original website is now not working, I'm putting the original I2C-Flexel
documentation and example files here, to the `Docs` subfolder, in order to preserve the knowledge. Hope the author
wouldn't mind.

There is still a copy of the original website in the [Wayback Machine](http://web.archive.org) (if you consider yourself lucky finding the documentation you needed there, know that the service is accepting [donations](https://archive.org/donate/))!
