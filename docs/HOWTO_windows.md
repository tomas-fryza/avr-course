## How to Use AVR Template on Windows

TBD

https://git-scm.com/downloads
http://www.mingw.org/
http://download.savannah.gnu.org/releases/avrdude/

From webpage https://atom.io/ download and install Atom text editor.

https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers

drivers:
https://www.arduino.cc/en/Main/Software

copy "libusb0.dll" from Arduino folder to avrdude folder, such as c:\APPZ\AVR\

Makefile.win --> Makefile

run cmd
mingw32-make all
mingw32-make size
...

---

#### How to Install Bootloader to Arduino Uno Clone
To install the bootloader, follow instructions at [Instructables](https://www.instructables.com/id/How-to-fix-bad-Chinese-Arduino-clones/) or [Arduino webpages](https://www.arduino.cc/en/Tutorial/ArduinoISP).

---

#### How to Add AVR Assembly Support to Atom Editor
In menu **Edit > Preferences** choose **Install**. Search for `language-asm-avr` package and click on **Install** button.

---

#### How to Add AVR Assembly Support to Visual Studio Code
In menu **File > Preferences > Extensions Ctrl+Shift+X** search for `AVR Support` package and click on **Install** button.
