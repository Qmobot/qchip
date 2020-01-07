#include "qmobot.h"


Qchip_chip::Qchip_chip(){
	display = new SSD1306Wire(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64);
	
	pinMode(RIGHT_SENSORPIN,INPUT);
	pinMode(CENTER_SENSORPIN,INPUT);
	pinMode(LEFT_SENSORPIN,INPUT);

	pinMode(RT, OUTPUT);
	pinMode(RE, INPUT);
	pinMode(LT, OUTPUT);
	pinMode(LE, INPUT);

	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);

	pinMode(PWMA, OUTPUT);
	pinMode(PWMB, OUTPUT);
}


void Qchip_chip::begin(bool DisplayEnable, bool SerialEnable, bool PABOOST, long BAND) {

	// UART
	if (SerialEnable) {
		Serial.begin(115200);
		Serial.flush();
		delay(50);
		Serial.print("Qchip is ready\r\n");
	}

	// OLED
	if (DisplayEnable)
	{
		display->init();
		display->flipScreenVertically();
		display->setFont(ArialMT_Plain_10);
		display->drawString(0, 0, "Qmobot.com");
		display->display();

		if (SerialEnable){
			Serial.print("you can see OLED printed OLED initial done!\r\n");
		}
	}
}

void Qchip_chip::motor(bool motors, int dir) {
	if(motors == 0){
		if(dir == 1){
			digitalWrite(AIN2, LOW);
			digitalWrite(AIN1, HIGH);
			digitalWrite(PWMA, HIGH);
		}
		else if(dir == -1){
			digitalWrite(AIN1, LOW);
			digitalWrite(AIN2, HIGH);
			digitalWrite(PWMA, HIGH);
		}
		else{
			digitalWrite(AIN2, LOW);
			digitalWrite(AIN1, LOW);
			digitalWrite(PWMA, LOW);
		}
	}
	else if(motors == 1){
		if(dir == 1){
			digitalWrite(BIN2, LOW);
			digitalWrite(BIN1, HIGH);
			digitalWrite(PWMB, HIGH);
		}
		else if(dir == -1){
			digitalWrite(BIN1, LOW);
			digitalWrite(BIN2, HIGH);
			digitalWrite(PWMB, HIGH);
		}
		else{
			digitalWrite(BIN2, LOW);
			digitalWrite(BIN1, LOW);
			digitalWrite(PWMB, LOW);
		}
	}
}

void Qchip_chip::stop() {
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, LOW);
	digitalWrite(PWMB, LOW);
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, LOW);
	digitalWrite(PWMA, LOW);
}

Qchip_chip Qchip;
