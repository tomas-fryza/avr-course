## How to use AVR template on Windows

1. Download and install [Visual Studio Code](https://code.visualstudio.com/) source code editor.

2. Download and install [Git](https://git-scm.com/downloads). During installation choose the default editor used by Git as **Use Visual Studio Code as Git's default editor**.

3. Download and run [MinGW Installation Manager](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/). During installation keep installation directory as `C:\MinGW`.

    In MinGW Installation Manager, mark **mingw32-base-bin** package for installation and apply changes in menu **Installation > Apply Changes**.

    Add `C:\MinGW\bin` to your **Path** environment variable: **This PC > Properties > Advanced system settings > Environment Variables...**

4. Download the latest version of Avrdude, such as [avrdude-6.3-mingw32.zip](http://download.savannah.gnu.org/releases/avrdude/) and extract **avrdude.conf** and **avrdude.exe** files to `C:\Appz\Avr` (Do NOT use any space in filepath). Copy [libusb0.dll](libusb0.dll) dynamic link library to `C:\Appz\Avr`. You can find the dll as part of Arduino IDE as well.

5. Download and install [PuTTy](https://www.putty.org/) client for serial communication between Arduino Uno board and your computer.

6. Optionally, download and install [Saleae logic](https://www.saleae.com/downloads/) for analyzing digital and analog signals.

7. Download the latest toolchain [AVR 8-bit Toolchain v3.62 - Windows](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) and extract all files to `C:\Appz\Avr\avr8-gnu-toolchain-win32_x86`.

8. Download and extract `Examples` folder from [this repository](https://github.com/tomas-fryza/Digital-electronics-2/archive/master.zip) to local computer.

9. Start Visual Studio Code source code editor, open template folder, in `Examples/firmware.in` file enable and/or modify Windows parameters according to your local settings:

    ```Makefile
    ## Linux
    #PREFIX  = /opt/avr8-gnu-toolchain-linux_x86_64
    #AVRDUDE = avrdude
    #RM      = rm -f
    ## See "dmesg" command output
    #USBPORT = /dev/ttyUSB0

    ## Windows
    PREFIX  = C:\Appz\Avr\avr8-gnu-toolchain-win32_x86
    AVRDUDE = C:\Appz\Avr\avrdude.exe
    RM      = del
    # See USB-SERIAL CH340 port in Device Manager
    USBPORT = COM3
    ```

    > If USB drivers for AVR boards are missing, download and install [Arduino IDE](https://www.arduino.cc/en/Main/Software) (it includes all drivers:).
    >

10. Open a new terminal in menu **Terminal > New Terminal** and change working directory to `Examples/blink`.

    ```bash
    cd Examples
    cd blink
    ls
    ```

    > Instead of `ls` command you can try `dir`.
    >

    All processes are done with help of `Makefile` script file. The following commands allow project compilation and programming:

    ```bash
    mingw32-make.exe all
    mingw32-make.exe flash
    mingw32-make.exe size
    mingw32-make.exe list
    mingw32-make.exe clean
    ```

11. To create a new project, make a new directory within `Labs` folder and copy three files `main.c`, `Makefile`, and `README.md` from `Examples/blink` project to `Labs/new-project-folder`.

    > If your Arduino board (or clone) does not contain any bootloader, follow instructions at [Instructables](https://www.instructables.com/id/How-to-fix-bad-Chinese-Arduino-clones/) or [Arduino webpages](https://www.arduino.cc/en/Tutorial/ArduinoISP).
    >
    > For Windows 10, you can install [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and then follow the AVR installation notes for Linux.
    >


#### Tested on operating systems

**Name**   | **Version**                | **Result**      | **Note**
---------- | -------------------------- | --------------- | -----------
Windows    | Windows 10                 | OK (2020-09-03) | Lab SC 6.61
Windows    | Windows 10                 | OK (2019-11-26) | Lab SC 6.66
Windows    | Windows 7                  | OK (2019-05-17) | Lab SC 6.61
