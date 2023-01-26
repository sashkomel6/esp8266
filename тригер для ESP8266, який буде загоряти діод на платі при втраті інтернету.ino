#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
unsigned int localPort = 2390;
IPAddress ip(8,8,8,8); // google dns

int ledPin = 2; // LED connected to digital pin 2
bool internet_status = true;

const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

void setup() {
pinMode(ledPin, OUTPUT); // sets the digital pin as output
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.println("Connecting to WiFi...");
}
Serial.println("Connected to WiFi");
udp.begin(localPort);
}

void loop() {
if(WiFi.status()== WL_CONNECTED){ //Check WiFi connection status
WiFiClient client;
if (client.connect("www.google.com", 80)) { //ping google.com
digitalWrite(ledPin, HIGH); //if connected turn off LED
} else {
digitalWrite(ledPin, LOW); //if not connected turn on LED
}
}
}
