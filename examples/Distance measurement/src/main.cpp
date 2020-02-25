#include <qmobot.h>


void setup() { // This function runs once
	begin(true, true); // Function to initialize Qmobot
}

void loop() { // This function runs in loop
	int distance = 0; // Keep distance value in variable

	distance = echo('R'); 
	
	if(distance > 1000){ // If the value is 1199 - than it is more than sensor is able to measure
		print("Right sensor distance is unrecheable");
	}
	else if(distance < 0){ // If distance is under 0 - than there is ERROR
		print("ERROR");
	}
	else{
		print("Right sensor distance is: ");
		println(distance);
	}
}
