## How to use AVR template on Linux

1. Download and install [Visual Studio Code](https://code.visualstudio.com/) source code editor.

2. AVR template requires the following packages to be installed correctly:

    ```bash
    sudo apt-get install git make avrdude putty
    ```

3. Optionally, download and install [Saleae logic](https://www.saleae.com/downloads/) for analyzing digital and analog signals.

4. Download the latest toolchain [AVR 8-bit Toolchain 3.6.2 - Linux 64-bit](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) and extract all files to `/opt` directory:

    ```bash
    sudo tar -xzvf avr8-gnu-toolchain-3.6.2.1759-linux.any.x86_64.tar.gz -C /opt/
    ```

5. Download and extract `Examples` folder from [this repository](https://github.com/tomas-fryza/Digital-electronics-2/archive/master.zip) to local computer.

6. Start Visual Studio Code source code editor, open examples folder, and in `Examples/firmware.in` file enable and/or modify Linux parameters according to your local settings:

    ```Makefile
    ## Linux
    PREFIX  = /opt/avr8-gnu-toolchain-linux_x86_64
    AVRDUDE = avrdude
    RM      = rm -f
    # See "dmesg" command output
    USBPORT = /dev/ttyUSB0

    ## Windows
    #PREFIX  = C:\Appz\Avr\avr8-gnu-toolchain-win32_x86
    #AVRDUDE = C:\Appz\Avr\avrdude.exe
    #RM      = del
    ## See USB-SERIAL CH340 port in Device Manager
    #USBPORT = COM3
    ```

    > If USB drivers for AVR boards are missing, download and install [Arduino IDE](https://www.arduino.cc/en/Main/Software) (it includes all drivers:).
    >

7. Open a new terminal in menu **Terminal > New Terminal** and change working directory to `Examples/blink`.

    ```bash
    cd Examples/blink
    ls
    ```

    All processes are done with help of `Makefile` script file. The following commands allow compilation and programming:

    ```bash
    make all
    make flash
    make size
    make list
    make clean
    ```

8. To create a new project, make a new directory within `Labs` folder and copy three files `main.c`, `Makefile`, and `README.md` from `Examples/blink` project to `Labs/new-project-folder`.

    > If your Arduino board (or clone) does not contain any bootloader, follow instructions at [Instructables](https://www.instructables.com/id/How-to-fix-bad-Chinese-Arduino-clones/) or [Arduino webpages](https://www.arduino.cc/en/Tutorial/ArduinoISP).
    >


#### Tested on operating systems

**Name**   | **Version**                | **Result**      | **Note**
---------- | -------------------------- | --------------- | -----------
Linux Mint | 18.3, Sylvia               | OK (2019-06-13) | Laptop
Linux Mint | 18.2, Sonya                | OK (2019-05-17) | Lab SC 6.61
Ubuntu     | 18.04.1 LTS, Bionic Beaver | OK (2019-05-15) | Office
Ubuntu     | 16.04, Xenial Xerus        | OK (2018-09-15) | Office

```bash
# FYI: How to check OS version in Linux
cat /etc/os-release
```
