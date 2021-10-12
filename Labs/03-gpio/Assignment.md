# Lab 3: YOUR_FIRSTNAME FAMILYNAME

Link to your `Digital-electronics-2` GitHub repository:

   https://github.com/dnoa-g/Digital-electronics-2

### Data types in C

1. Complete table.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | -128 to 127 | Signed 8-bit integer |
| `uint16_t` | 16 | 0 to 65,535 | Unsigned 16-bit integer |
| `int16_t`  | 16 | -32,768 to 32,767 | Signed 16-bit integer |
| `float`    | 4 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | 0| ---- |An empty data type that has no value |


### GPIO library

1. In your words, describe the difference between the declaration and the definition of the function in C.
   * Function declaration =  A function declaration tells the compiler about a function name and how to call the function. The actual body of the function can be defined separately.
   * Function definition = Variable says where the variable gets stored. i.e., memory for the variable is allocated during the definition of the variable.
   * In C language definition and declaration for a variable takes place at the same time. i.e. there is no difference between declaration and definition.

2. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Use function from your GPIO library. Let the push button is connected to port D:

```c![Start Simulating (3) (1)](https://user-images.githubusercontent.com/91589518/136938939-a875f5f7-ede9-4edb-a4c8-d22c18d7d6b9.png)

    // Configure Push button at port D and enable internal pull-up resistor
    // WRITE YOUR CODE HERE
    int ledPin = 13; // pin for the LED
    int inPin = 5;   // input pin (for a pushbutton)
    int val = 0;     // variable for reading the pin status
    void setup() {
      pinMode(ledPin, OUTPUT);   // declare LED as output
      pinMode(inPin, INPUT);     // declare pushbutton as input
    // Infinite loop
    while (1)
    {
      val = digitalRead(inPin);  // read input value
      if (val == HIGH) {         // check if the input is HIGH (button released)
         digitalWrite(ledPin, LOW);    // turn LED OFF
      } else {
         digitalWrite(ledPin, HIGH);   // turn LED ON
      }
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);
![Start Simulating (3) (1)](https://user-images.githubusercontent.com/91589518/136938911-303d199a-5f20-4ad0-8657-0d0df2439781.png)

        // WRITE YOUR CODE HERE
    }
```


### Traffic light

1. Scheme of traffic light application with one red/yellow/green light for cars and one red/green light for pedestrians. Connect AVR device, LEDs, resistors, one push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure]()
