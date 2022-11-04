### Version: Atmel Studio 7

1. Create a new GCC C Executable Project for ATmega328P within `08-i2C` working folder and copy/paste [template code](main.c) to your `main.c` source file.

2. In **Solution Explorer** click on the project name, then in menu **Project**, select **Add Existing Item... Shift+Alt+A** and add:
   * I2C/TWI files `twi.h`, [`twi.c`](../../examples/library/twi.c) from `examples/library/include` and `examples/library` folders,
   * UART library files `uart.h`, `uart.c` from the previous lab,
   * Timer library `timer.h` from the previous labs.

### Version: Command-line toolchain

1. Copy `main.c` and `Makefile` files from previous lab to `Labs/08-i2c` folder.

2. Copy/paste [template code](main.c) to your `08-i2c/main.c` source file.

3. Add the source files of I2C/TWI and UART libraries between the compiled files in `08-i2c/Makefile`.

```Makefile
# Add or comment libraries you are using in the project
#SRCS += $(LIBRARY_DIR)/lcd.c
SRCS += $(LIBRARY_DIR)/uart.c
SRCS += $(LIBRARY_DIR)/twi.c
#SRCS += $(LIBRARY_DIR)/gpio.c
#SRCS += $(LIBRARY_DIR)/segment.c
```
