#ifndef _QMOBOT_H_
#define _QMOBOT_H_


#include <Arduino.h>
#include <Wire.h>
#include <Wifi.h>
#include "oled/SSD1306Wire.h"
#include "AnalogWrite/analogWrite.h"

#include "WiFi/src/WiFi.h"
#include "WiFi/src/WiFiAP.h"
#include "WiFi/src/WiFiMulti.h"
#include "WiFi/src/WiFiUdp.h"
#include "WiFi/src/WiFiScan.h"
#include "WiFi/src/ETH.h"
#include "WiFi/src/WiFiClient.h"
#include "WiFi/src/WiFiSTA.h"
#include "WiFi/src/WiFiServer.h"
#include "WiFi/src/WiFiType.h"
#include "WiFi/src/WiFiGeneric.h"
#include "FFat/src/FFat.h"
#include "SD/src/sd_defines.h"
#include "SD/src/sd_diskio.h"
#include "SD/src/SD.h"
#include "Preferences/src/Preferences.h"
#include "HTTPClient/src/HTTPClient.h"
#include "BLE/src/BLEServer.h"
#include "BLE/src/GeneralUtils.h"
#include "BLE/src/BLEService.h"
#include "BLE/src/BLEEddystoneURL.h"
#include "BLE/src/BLEEddystoneTLM.h"
#include "BLE/src/BLEDescriptor.h"
#include "BLE/src/BLEExceptions.h"
#include "BLE/src/BLEHIDDevice.h"
#include "BLE/src/BLEUUID.h"
#include "BLE/src/BLESecurity.h"
#include "BLE/src/RTOS.h"
#include "BLE/src/BLEAddress.h"
#include "BLE/src/BLERemoteService.h"
#include "BLE/src/BLEAdvertising.h"
#include "BLE/src/BLECharacteristic.h"
#include "BLE/src/BLE2904.h"
#include "BLE/src/BLEAdvertisedDevice.h"
#include "BLE/src/BLEScan.h"
#include "BLE/src/BLERemoteDescriptor.h"
#include "BLE/src/BLEUtils.h"
#include "BLE/src/BLEDevice.h"
#include "BLE/src/BLEBeacon.h"
#include "BLE/src/BLEValue.h"
#include "BLE/src/BLERemoteCharacteristic.h"
#include "BLE/src/BLE2902.h"
#include "BLE/src/HIDTypes.h"
#include "BLE/src/BLEClient.h"
#include "BLE/src/HIDKeyboardTypes.h"
#include "LittleFS/src/LittleFS.h"
#include "Wire/src/Wire.h"
#include "Update/src/HttpsOTAUpdate.h"
#include "Update/src/Update.h"
#include "DNSServer/src/DNSServer.h"
#include "SPIFFS/src/SPIFFS.h"
#include "NetBIOS/src/NetBIOS.h"
#include "HTTPUpdateServer/src/HTTPUpdateServer.h"
#include "WiFiProv/src/WiFiProv.h"
#include "RainMaker/src/RMakerDevice.h"
#include "RainMaker/src/RMakerType.h"
#include "RainMaker/src/RMaker.h"
#include "RainMaker/src/RMakerNode.h"
#include "RainMaker/src/RMakerParam.h"
#include "RainMaker/src/RMakerQR.h"
#include "RainMaker/src/RMakerUtils.h"
#include "ArduinoOTA/src/ArduinoOTA.h"
#include "WiFiClientSecure/src/WiFiClientSecure.h"
#include "WiFiClientSecure/src/ssl_client.h"
#include "ESP32/src/dummy.h"
#include "USB/src/USB_NOT.h"
#include "WebServer/src/WebServer.h"
#include "WebServer/src/Uri.h"
#include "WebServer/src/HTTP_Method.h"
#include "SPI/src/SPI.h"
#include "SimpleBLE/src/SimpleBLE.h"
#include "AsyncUDP/src/AsyncUDP.h"
#include "Ticker/src/Ticker.h"
#include "HTTPUpdate/src/HTTPUpdate.h"
#include "ESPmDNS/src/ESPmDNS.h"
#include "EEPROM/src/EEPROM.h"
#include "FS/src/vfs_api.h"
#include "FS/src/FS.h"
#include "FS/src/FSImpl.h"
#include "BluetoothSerial/src/BluetoothSerial.h"
#include "BluetoothSerial/src/BTScan.h"
#include "BluetoothSerial/src/BTAddress.h"
#include "BluetoothSerial/src/BTAdvertisedDevice.h"
#include "SD_MMC/src/sd_defines.h"
#include "SD_MMC/src/SD_MMC.h"

#define RT 27
#define RE 34
#define LT 26
#define LE 39

#define LEFT_SENSORPIN 36
#define CENTER_SENSORPIN 33
#define RIGHT_SENSORPIN 38

#define PWMA 17
#define AIN1 18
#define AIN2 23
#define PWMB 5
#define BIN1 19
#define BIN2 22

#define BAT 37


void begin(bool DisplayEnable=true, bool SerialEnable=true, bool BOOT_CTRL=true, bool PABOOST=true, long BAND=470E6);
void IRAM_ATTR BOOT_control();
void print(String phrase);
void println(String phrase);
void erase();
void show(String phrase="Qmobot.com", int x=0, int y=0);
void stop();
float battery();
void run(char Motor='R', int value=0);
int echo(char way='R');

#endif