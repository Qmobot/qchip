

#ifndef _QMOBOT_H_
#define _QMOBOT_H_


#include <Arduino.h>
#include <Wire.h>
#include "oled/SSD1306Wire.h"

#define RT 22
#define RE 36
#define LT 21
#define LE 34

#define LEFT_SENSORPIN 39
#define CENTER_SENSORPIN 38
#define RIGHT_SENSORPIN 37

#define PWMA 26
#define AIN1 14
#define AIN2 27
#define STB 18
#define PWMB 25
#define BIN1 19
#define BIN2 23


class Qchip_chip {

 public:
    Qchip_chip();

    void begin(bool DisplayEnable=true, bool SerialEnable=true, bool PABOOST=true, long BAND=470E6);
    void motor(bool motor=1, int dir=0);
    void stop();
    SSD1306Wire *display;

};
extern Qchip_chip Qchip;

#endif
