#ifndef _QMOBOT_H_
#define _QMOBOT_H_


#include <Arduino.h>
#include <Wire.h>
#include <Wifi.h>
#include "oled/SSD1306Wire.h"
#include "AnalogWrite/analogWrite.h"

#define RT 27
#define RE 34
#define LT 26
#define LE 39

#define LEFT_SENSORPIN 36
#define CENTER_SENSORPIN 37
#define RIGHT_SENSORPIN 38

#define PWMA 17
#define AIN1 18
#define AIN2 23
#define PWMB 5
#define BIN1 19
#define BIN2 22

#define BAT 32


void begin(bool DisplayEnable=true, bool SerialEnable=true, bool PABOOST=true, long BAND=470E6);
void print(String phrase);
void println(String phrase);
void erase();
void show(String phrase="Qmobot.com", int x=0, int y=0);
void stop();
void run(char Motor='R', int value=0);
int echo(char way='R');

#endif