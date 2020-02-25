#ifndef _QMOBOT_H_
#define _QMOBOT_H_


#include <Arduino.h>
#include <Wire.h>
#include "oled/SSD1306Wire.h"
#include "AnalogWrite/analogWrite.h"

#define RT 21
#define RE 36
#define LT 22
#define LE 37

#define LEFT_SENSORPIN 38
#define CENTER_SENSORPIN 39
#define RIGHT_SENSORPIN 34

#define PWMA 2
#define AIN1 5
#define AIN2 17
#define PWMB 19
#define BIN1 18
#define BIN2 23


void begin(bool DisplayEnable=true, bool SerialEnable=true, bool PABOOST=true, long BAND=470E6);
void print(String phrase);
void println(String phrase);
void erase();
void show(String phrase="Qmobot.com", int x=0, int y=0);
void stop();
void run(char Motor='R', int value=0);
int echo(char way='R');

#endif