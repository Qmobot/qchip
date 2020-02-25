#include <qmobot.h>


void setup() { // This function runs once
	begin(true, true); // Function to initialize Qmobot
}

void loop() { // This function runs in loop
	long duration = 0;
	int distance = 0;

	// Send low to echo trigger
	digitalWrite(RT, LOW);
	delayMicroseconds(2);

	// Send high to echo trigger
	digitalWrite(RT, HIGH);
	// Wait 10 microseconds and send low - to create pulse
	delayMicroseconds(10);
	digitalWrite(RT, LOW);
	
	// Wait till pulse comes back to echo pin
	duration = pulseIn(RE, HIGH);
	
	// Calculate distance from time
	distance= duration*0.034/2;

	print("Distance is: ");
	println(distance);
}
