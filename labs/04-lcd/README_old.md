### Version: Atmel Studio 7

1. Create a new GCC C Executable Project for ATmega328P within `06-lcd` working folder and copy/paste [template code](main.c) to your `main.c` source file.

2. In **Solution Explorer** click on the project name, then in menu **Project**, select **Add Existing Item... Shift+Alt+A** and add LCD library files `lcd.h`, `lcd_definitions.h`, [`lcd.c`](../library/lcd.c) from `examples/library/include` and `Examples/library` folders and timer library `timer.h` from the previous labs.

### Version: Command-line toolchain

1. Copy `main.c` and `Makefile` files from previous lab to `labs/06-lcd` folder.

2. Copy/paste [template code](main.c) to your `06-lcd/main.c` source file.

3. Add the source file of LCD library between the compiled files in `06-lcd/Makefile`.

```Makefile
# Add or comment libraries you are using in the project
SRCS += $(LIBRARY_DIR)/lcd.c
#SRCS += $(LIBRARY_DIR)/uart.c
#SRCS += $(LIBRARY_DIR)/twi.c
#SRCS += $(LIBRARY_DIR)/gpio.c
#SRCS += $(LIBRARY_DIR)/segment.c
```




1. Compile the code and download to Arduino Uno board or load `*.hex` firmware to SimulIDE circuit (create an identical connection to the LCD keypad shield).

   ![SimulIDE](images/screenshot_simulide_lcd.png)
