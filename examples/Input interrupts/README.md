# What is interrupts?

The Qchip offers up to 32 interrupt slots for each core. 
Each interrupt has a certain priority level and can be categorized into two types.

1. **Hardware Interrupts** – These occur in response to an external event. 
For example, GPIO Interrupt(when a key is pressed down) or a Touch Interrupt(when touch is detected)

2. **Software Interrupts** – These occur in response to a software instruction. 
For example, a Simple Timer Interrupt or Watchdog Timer Interrupt(when timer times out)

> In Qchip, we can define an interrupt service routine function that will be called when 
a GPIO pin changes its signal value.

With an Qchip board, all the GPIO pins can be configured to function as interrupt request inputs.

In PlatformIO, we use a function called `attachInterrupt()` to set an interrupt on a pin by pin basis. 
The recommended syntax looks like below.

``attachInterrupt(GPIOPin, ISR, Mode);``

This function takes three parameters:

1. GPIOPin – Sets the GPIO pin as an interrupt pin, which tells the Qchip which pin to monitor.

2. ISR – Is the name of the function that will be called every time the interrupt is triggered.

3. Mode – Defines when the interrupt should be triggered. Five constants are predefined as valid values:

> LOW	Triggers interrupt whenever the pin is LOW
> HIGH	Triggers interrupt whenever the pin is HIGH
> CHANGE	Triggers interrupt whenever the pin changes value, from HIGH to LOW or LOW to HIGH
> FALLING	Triggers interrupt when the pin goes from HIGH to LOW
> RISING	Triggers interrupt when the pin goes from LOW to HIGH

You can optionally call `detachInterrupt()` function when you no 
longer want Qchip to monitor a pin. The recommended syntax looks like below.

``detachInterrupt(GPIOPin);``

Interrupt Service Routine is invoked when an interrupt occurs on any GPIO pin. 
Its syntax looks like below.

```
void IRAM_ATTR ISR() {
    Statements;
}
```

ISRs in ESP32 are special kinds of functions that have some unique rules most other functions do not have.

The interrupt service routine must have an execution time **as short as possible**, because it blocks the normal program execution.

Interrupt service routines should have the IRAM_ATTR attribute, according to the [documentation](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/general-notes.html#iram-instruction-ram)

> What is IRAM_ATTR?
> By flagging a piece of code with the IRAM_ATTR attribute we are declaring that the compiled code will be placed in the Internal RAM (IRAM) of the Qchip.

> Otherwise the code is placed in the Flash. And flash on the Qchip is much slower than internal RAM.

> If the code we want to run is an interrupt service routine (ISR), we generally want to execute it as quickly as possible. If we had to ‘wait’ for an ISR to load from flash, things would go horribly wrong.
> 

