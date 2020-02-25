#include <qmobot.h>


struct Button { // Create structure named Button
  const uint8_t Pin;
  uint32_t numberKeyPresses;
  bool pressed;
}; 
// Structure is the collection of variables of different types 
// (but logically related to each other) under a single name.


// Next we create an instance of the Button structure and initialize 
// pin number to builtin led, number of key presses to 0 and default 
// pressed state to false.
Button button1 = {LED_BUILTIN, 0, false}; 


// The following piece of code is an Interrupt Service Routine. 
// As mentioned earlier, ISR in Qchip should have the IRAM_ATTR attribute.

// In ISR we simply increment the KeyPresses counter by 1 & set button pressed state to True.
void IRAM_ATTR isr() {
  button1.numberKeyPresses += 1;
  button1.pressed = true;
}

void setup() {
	begin(true, true);

  // Next we tell the Qchip to monitor the pin and call the interrupt 
  // service routine isr when the pin goes from HIGH to LOW i.e. FALLING state.
	pinMode(button1.PIN, INPUT_PULLUP);
	attachInterrupt(button1.PIN, isr, FALLING);
}

void loop() {
  // In Loop section of the code, we simply check if the button pressed state returns to be true. 
  // When it does, we simply print the number of key pressed till now and set the button pressed 
  // state LOW so that we can continue getting next interrupts.
  if (button1.pressed) {
      Serial.printf("Button 1 has been pressed %u times\n", button1.numberKeyPresses);
      button1.pressed = false;
  }

  //Detach Interrupt after 1 Minute
  static uint32_t lastMillis = 0;
  if (millis() - lastMillis > 60000) {
    lastMillis = millis();
    detachInterrupt(button1.PIN);
	Serial.println("Interrupt Detached!");
  }
}