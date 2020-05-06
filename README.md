# cgrPinner

- Fast input/output controller macros for AVR and AVR based Arduino boards.
- Compatible with Arduino IDE [(Example)](#Example)
- No need to create instance(object)
- Usable for both C and C++

## Macros
- setOutput
- setInput
- pinHigh
- pinLow
- pinToggle
- readPin

## Library usage
> Include the library
```c++
#include <cgrPinner.h> // https://github.com/bladekel/cgrPinner/
```

> Define the pin names whatever you want with PORT and BIT
```c++
//      name   PORT,BIT
#define out1      B,5 // Set pin bit number 5 on PORTB as out1
#define in1       C,1 // Set pin bit number 1 on PORTC as in1
```

> Set pin directions
```c++
setOutput(out1); // set out1 as an output
setInput(in1);   // set in1  as an input
```

> Set pin logic status
```c++
pinHigh(out1);    // Set out1 as HIGH
pinLow(out1);     // Set out1 as LOW
pinToggle(out1);  // Toggle out1
```

> Read pin logic status
```c++
bool status = readPin(in1);  // Read pin status
```

## Example

![**read_write.ino**](https://github.com/bladekel/cgrPinner/blob/master/examples/read_write/read_write.ino)

```c++
#include <cgrPinner.h> // https://github.com/bladekel/cgrPinner/

// Defining IOs : name Port,Bit
#define out1 B,5
#define out2 B,4
#define in1 B,2
#define in2 B,1

void setup() {
  // Adjusting the output pins
  setOutput(out1);
  setOutput(out2);
  
  // Adjusting the input pins
  setInput(in1);
  setInput(in2);
}

void loop() {  
  // Read in1 pin and toggle the out1 pin
  if(readPin(in1) == true)pinToggle(out1); 

  // Read in2 pin and change the out2 pin status
  if(readPin(in2) == true)pinHigh(out2);
  else pinLow(out2);
}
```
