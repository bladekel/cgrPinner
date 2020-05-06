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
