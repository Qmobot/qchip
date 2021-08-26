#include <qmobot.h>


String EL = "OFF";
String ER = "OFF";
String LS = "OFF";
String RS = "OFF";
String CS = "OFF";
String VBAT = "OFF";
String MLs = "OFF";
String MRs = "OFF";
String LEDs = "OFF";
uint32_t chipId = 0;
String name2;

void name() {
	for(int i=0; i<17; i=i+8) {
	  chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
	}
	name2 = String(name);
}


void setup() { // This function runs once
	begin(true, true); // Function to initialize Qmobot
	name();
}


void showAll(){
	erase();
	show("ML: " + MLs, 0, 10);
	show("MR: " + MRs, 60, 10);
	show("LED: " + LEDs, 0, 20);
	show(" | BAT: " + VBAT, 60, 20);
	show("EchoL: " + EL, 0, 30);
	show(" | EchoR: " + ER, 60, 30);
	show("L: "+LS+" | C: "+CS+" | R: "+RS+"", 0, 40);
	show("Qmobot.com/start");
	show(name2, 50, 0);
}

void CheckVals(){
	int distance = echo('R');
	int distance2 = echo('L');
	int L = digitalRead(LEFT_SENSORPIN /* Three pins: LEFT, CENTER, RIGHT*/);
	int C = digitalRead(CENTER_SENSORPIN /* Three pins: LEFT, CENTER, RIGHT*/);
	int R = digitalRead(RIGHT_SENSORPIN /* Three pins: LEFT, CENTER, RIGHT*/);
	
	EL = String(distance2);
	ER = String(distance);
	LS = String(L);
	RS = String(R);
	CS = String(C);

	float VBAT2 = (float)(analogRead(37))/1024.0; 
	VBAT = String(VBAT2*222-444);
}

void loop() { // This function runs in loop
	stop();
	CheckVals();
	MLs = "ON";
	showAll();
	run('L', 255);

	delay(500);
	stop();
	MLs = "OFF";
	MRs = "ON";
	CheckVals();
	showAll();

	run('R', 255);
	delay(500);
	stop();

	MLs = "OFF";
	MRs = "OFF";
	CheckVals();
	showAll();
	
	LEDs = "ON";
	CheckVals();
	showAll();

	analogWrite(LED_BUILTIN /* Pin number */, 255 /* Value from 0 to 255*/);
	delay(1000);
	
	LEDs = "OFF";
	CheckVals();
	showAll();

	analogWrite(LED_BUILTIN /* Pin number */, 0 /* Value from 0 to 255*/);
	delay(2000);
	for(int i = 0; i<10; i++){
		CheckVals();
		showAll();
		delay(500);
	}
}
