


### Version: Atmel Studio 7

1. Create a new GCC C Executable Project for ATmega328P within `07-uart` working folder and copy/paste [template code](main.c) to your `main.c` source file.

2. In **Solution Explorer** click on the project name, then in menu **Project**, select **Add Existing Item... Shift+Alt+A** and add:
   * UART files [`uart.h`](../library/include/uart.h), [`uart.c`](../library/uart.c) from `examples/library/include` and `examples/library` folders,
   * LCD library files `lcd.h`, `lcd_definitions.h`, `lcd.c` from the previous labs,
   * Timer library `timer.h` from the previous labs.

### Version: Command-line toolchain

1. Copy `main.c` and `Makefile` files from previous lab to `labs/07-uart` folder.

2. Copy/paste [template code](main.c) to your `07-uart/main.c` source file.

3. Add the source files of UART and LCD libraries between the compiled files in `07-uart/Makefile`.

```Makefile
# Add or comment libraries you are using in the project
SRCS += $(LIBRARY_DIR)/lcd.c
SRCS += $(LIBRARY_DIR)/uart.c
#SRCS += $(LIBRARY_DIR)/twi.c
#SRCS += $(LIBRARY_DIR)/gpio.c
#SRCS += $(LIBRARY_DIR)/segment.c
```

### Both versions

