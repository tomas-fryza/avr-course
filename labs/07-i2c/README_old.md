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








2. Explore the use of Finite State Machine (FSM) in the `main.c` source file. Note that state names are declared using `typedef enum` as follows

```c
typedef enum {  // FSM declaration
    STATE_IDLE = 1,
    STATE_SEND,
    STATE_ACK
} state_t;
```

  and the body and transitions between states are defined using `switch`/`case` C structure.

```c
    static state_t state = STATE_IDLE;  // Current state of the FSM

    // FSM
    switch (state)
    {
    // Increment I2C slave address
    case STATE_IDLE:
        ...
        break;
    
    // Transmit I2C slave address and get result
    case STATE_SEND:
        ...
        break;

    // A module connected to the bus was found
    case STATE_ACK:
        ...
        break;

    // If something unexpected happens then move to IDLE
    default:
        state = STATE_IDLE;
        break;
    }
```






3. Complete the Timer/Counter1 overflow routine according to the following state diagram and scan slave addresses. Transmit useful information via UART to PuTTY SSH Client or Serial monitor.

   ![FSM for I2C scanner](images/fsm_scan_i2c.png)

> The figure above was created in [diagrams.net](https://app.diagrams.net/). It is an open source, online, desktop and container deployable diagramming software.
>



### Version: Real hardware

1. Program an FSM application which reads data from humidity/temperature DHT12 sensor and sends them periodically via UART to PuTTY SSH Client. Use Timer/Counter1 with a suitable overflow time. Note that, according to the [DHT12 manual](../../docs/dht12_manual.pdf), the internal DHT12 data registers have the following structure.

   | **Register address** | **Description** |
   | :-: | :-- |
   | 0x00 | Humidity integer part |
   | 0x01 | Humidity fractional part |
   | 0x02 | Temperature integer part |
   | 0x03 | Temperature fractional part |
   | 0x04 | Checksum |

   ![FSM for I2C temperature](images/fsm_dht_i2c.png)

```c
/* Variables ---------------------------------------------------------*/
typedef enum {              // FSM declaration
    STATE_IDLE = 1,
    STATE_HUMID,
    STATE_TEMP,
    STATE_CHECK
} state_t;

...

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Update Finite State Machine and get humidity, temperature,
 *           and checksum from DHT12 sensor.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    static state_t state = STATE_IDLE;  // Current state of the FSM
    static uint8_t addr = 0x5c;  // I2C slave address of DHT12
    uint8_t value;               // Data obtained from the I2C bus
    char uart_string[] = "000";  // String for converting numbers by itoa()

    // FSM
    switch (state)
    {
    // Do nothing
    case STATE_IDLE:
        // Move to the next state
        state = STATE_HUMID;
        break;
    
    // Get humidity
    case STATE_HUMID:
        // WRITE YOUR CODE HERE
        
        // Move to the next state
        state = STATE_TEMP;
        break;

    // Get temperature
    case STATE_TEMP:
        // WRITE YOUR CODE HERE

        // Move to the next state
        state = STATE_CHECK;
        break;

    // Get checksum
    case STATE_CHECK:
        // WRITE YOUR CODE HERE
        
        // Move to the next state
        state = STATE_IDLE;
        break;

    default:
        state = STATE_IDLE;
        break;
    }
}
```
