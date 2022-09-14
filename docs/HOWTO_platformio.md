# How to use AVR template with PlatformIO

*[PlatformIO](https://platformio.org/) is a cross-platform build system that can be used to develop software platforms for Arduino, ESP32, PIC32, and AVR. PlatformIO can be used with VS Code to provide a powerful set of tools to assist you in development [[1]](https://maker.pro/arduino/tutorial/how-to-use-platformio-in-visual-studio-code-to-program-arduino), [[2]](https://dronebotworkshop.com/platformio/).*

1. Download and install [Visual Studio Code](https://code.visualstudio.com/) source code editor.

2. Run Visual Studio Code, open up the extensions viewer in menu **View > Extensions Ctrl+shift+X**, and then typing `PlatformIO` into the search bar. Press **Install** button on the result `PlatformIO IDE`.

   ![Install PatformIO IDE](images/platformio_install.png)

   It may take a few minutes depending on your connection speed. Do not close any window and do not open other folders until the installing process is completed. After that, restart the Visual Studio Code.

3. *Install Arduino framework:* Click on the PlatformIO icon in the left-hand margin, then in menu **PIO Home > Platforms > Embedded**. Type `AVR` as a platform's filter and select **Atmel AVR**. Click on the **Install** button.

   ![Install PatformIO IDE](images/platformio_atmel.png)

4. *Create a new project:* Click on the PlatformIO icon in the left-hand margin, then in menu **PIO Home > Open > New Project**. Type `blink` as project name, select `Arduino Uno` board, keep `Arduino` framework, and select location to your working folder. Click on the **Finish** button.

5. *Code the application:* Copy/paste [blink example code](https://raw.githubusercontent.com/tomas-fryza/digital-electronics-2/master/examples/blink/main.c) from this repository to your `BLINK > src > main.cpp` file.

6. *Compile and upload the code:* The handy shortcuts for building and uploading the code is available on the blue footer taskbar. Hover over the icon to get its functionality. Firts, compile (build) the project and then upload it to Arduino Uno board. You can clean up generated files as well.

   ![Install PatformIO IDE](images/platformio_footer.png)

#### Tested on operating systems

| **Version**                | **Result (yyyy-mm-dd)** | **Note**    |
| :------------------------- | :---------------------: | :---------- |
| Windows 10                 | OK (2022-09-08)         | Lab SC 6.61 |
| Linux Mint 20.3 (Una)      | OK (2022-02-23)         | Laptop      |
| Windows 10                 | OK (2021-11-25)         | Office      |
