// https://github.com/bladekel/cgrPinner

// Works on AVR
// You have to know the available ports on your IC, because this library dont check if it is available or not...
// Include the library on your main file(eg. main.cpp)

// Defining pins =>
// #define LED1 B,5 ( LED1 is on port B, bit 5 )
// #define BTN1 C,1 ( BTN1 is on port C, bit 1 )

// Adjusting pin mode =>
// setOutput(LED1);
// setInput(BTN1);

// Changing pin state =>
// pinHigh(LED1);
// pinLow(LED1);
// pinToggle(LED1);

// Reading pin state => 
// if(readPin(BTN1) == true ) {// do your staff;} ;


#ifndef _CGRPINNER_H_
#define _CGRPINNER_H_

#define BIT(p,b)				(b)
#define PORTDir(p,b)			(DDR ## p)
#define PORTLogic(p,b)			(PORT ## p)
#define PORTRead(p,b)			(PIN ## p)

#define pinAsOutput(p,b)		(p |= 1<<b)
#define pinAsInput(p,b)			(p &=~ (1<<b))
#define setOutput(io)			pinAsOutput(PORTDir(io),BIT(io))
#define setInput(io)			pinAsInput(PORTDir(io),BIT(io))

#define setPinToHigh(p,b)		(p |= 1<<b)
#define setPinToLow(p,b)		(p &=~ (1<<b))
#define setPinToToggle(p,b)		(p ^= 1<<b)
#define getPinLogic(p,b)		(((p) & (1<<b)) != 0)

#define pinHigh(io)				setPinToHigh(PORTLogic(io),BIT(io))
#define pinLow(io)				setPinToLow(PORTLogic(io),BIT(io))
#define pinToggle(io)			setPinToToggle(PORTLogic(io),BIT(io))

#define readPin(io)				getPinLogic(PORTRead(io),BIT(io))

#endif
