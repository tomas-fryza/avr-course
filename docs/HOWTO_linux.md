## How to Use AVR Template on Linux

AVR template requires the following packages to be installed correctly:

```bash
# Open source distributed version control system
sudo apt-get install git
# GNU make utility
sudo apt-get install make
# Software for programming Atmel AVR Microcontrollers
sudo apt-get install avrdude
# Documentation system for C, C++, Java, Python and other languages
sudo apt-get install doxygen
# Graph drawing tools
sudo apt-get install graphviz
```

Download and install [Atom text editor](https://atom.io/).

Download the latest [AVR Toolchain](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) for Linux, such as [AVR 8-bit Toolchain 3.6.2 - Linux 64-bit](https://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en607660).

Extract the contents of the `*.tar.gz` archive to a specific directory, for example, to `/opt` directory.

```bash
sudo tar -xzvf avr8-gnu-toolchain-3.6.2.1759-linux.any.x86_64.tar.gz -C /opt/
```

[Download this template](https://gitlab.com/tomas.fryza/avr-template/-/archive/master/avr-template-master.tar.gz) to local computer and use it to start your own repository.

Go to `projects/01-demo` directory, open `Makefile`, find and change (if necessary) line with path to AVR 8-bit toolchain.

```bash
# Change directory
cd project
# Modify projects.in
vim projects.in
# Check path to toolchain
PREFIX = /opt/avr8-gnu-toolchain-linux_x86_64
```

> **Note:**
If USB drivers for AVR boards are missing, download and install [Arduino IDE](https://www.arduino.cc/en/Main/Software) (it includes all drivers:).
>

> **Note:**
If your Arduino board (or clone) does not contain any bootloader, follow [instructions below](#how-to-install-bootloader-to-arduino-uno-clone).
>

All processes are done with help of `Makefile` script file. In Terminal change directory to `projects/01-demo`, then following commands allow compilation and programming of the application:

```bash
# Compile all binary
make
# Remove ALL binaries and object files from the directory
make clean
# Write compiled file to the Flash memory
make flash
# Generate extended listing file
make list
# Display the sizes of sections inside binary file
make size
```

To create a new project, make a new directory within `projects/` folder, write a new `main.c` source file, and copy `Makefile` from previous project.

```bash
# Make a new directory
mkdir name_of_new_project
# Change directory
cd name_of_new_project
# Copy source file and Makefile from 01-demo project
cp ../01-demo/main.c ../01-demo/Makefile .
# Edit main.c :)
```

---

#### How to Install Bootloader to Arduino Uno Clone
To install the bootloader, follow instructions at [Instructables](https://www.instructables.com/id/How-to-fix-bad-Chinese-Arduino-clones/) or [Arduino webpages](https://www.arduino.cc/en/Tutorial/ArduinoISP).

---

#### How to Add AVR Assembly Support to Atom Editor
In menu **Edit > Preferences** choose **Install**. Search for `language-asm-avr` package and click on **Install** button.

---

#### How to Add AVR Assembly Support to Visual Studio Code
In menu **File > Preferences > Extensions Ctrl+Shift+X** search for `AVR Support` package and click on **Install** button.
