#include <qmobot.h>


void setup() { // This function runs once
	begin(true, true); // Function to initialize Qmobot
}

void loop() { // This function runs in loop

}

void AnalogWriteExample(){
	analogWrite(LED_BUILTIN /* Pin number */, 255 /* Value from 0 to 255*/);
	analogWrite(LED_BUILTIN, 255, 4095 /* Alternative way to show maximum number, absolute maximum is 4095*/);
}

void DisplayExample(){
	erase(); // Erases display
	show("Your phrase", /* x axis value from 0 to 128 */ 0, /* y axis value from 0 to 64*/ 0);
}

void MotorControlExample(){
	stop(); // Stops all motors
	run('L' /* L - left motor, R - right motor */, 255/* Speed of motor from -255 to 255 */);
}

void EchoExample(){
	int distance = echo('R');
}

void FloorStateReadExample(){
	digitalRead(LEFT_SENSORPIN /* Three pins: LEFT, CENTER, RIGHT*/);
}