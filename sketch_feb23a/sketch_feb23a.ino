#define BLYNK_DEVICE_NAME "nodemcu"
#define BLYNK_TEMPLATE_ID "TMPLtMcaTfdT"
#define BLYNK_TEMPLATE_NAME "WOL TaiTung"
#define BLYNK_AUTH_TOKEN "NDqHjxgis3kL1MmYWtjnkYY8nMfODX49"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WakeOnLan.h>
WiFiUDP UDP;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "NDqHjxgis3kL1MmYWtjnkYY8nMfODX49";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TP-Link_1234"; // wifi 名稱
char pass[] = "12345678"; // wifi 密碼

// Set your local broadcast addres
IPAddress computer_ip(192,168,0,255);//廣播位址
// Set your NIC physical address in hex
// e.g 30-9C-23-1D-DB-7B will look like this:
byte mac[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 };//網路口的mac位址


int buttonState = 1;
const int ledPin = BUILTIN_LED;

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1

BLYNK_WRITE(V0)
{
  buttonState = param.asInt(); // assigning incoming value from pin V1 to a variable
    if (buttonState == 1) {
    digitalWrite(ledPin, LOW);
    WakeOnLan::sendWOL(computer_ip, UDP, mac, sizeof mac);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}

//如果需要多一組的控制
/*
BLYNK_WRITE(V1)
{
  buttonState = param.asInt(); // assigning incoming value from pin V1 to a variable
    if (buttonState == 1) {
    digitalWrite(ledPin, LOW);
    WakeOnLan::sendWOL(computer_ip, UDP, mac1, sizeof mac);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
*/

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, buttonState);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  UDP.begin(9);
}

void loop()
{
  Blynk.run();
}