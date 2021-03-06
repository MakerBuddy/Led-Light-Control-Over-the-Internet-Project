//Important Libries
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

char ssid[] = "Your WiFi SSID"; //Your Wifi Network Name
char wifiPassword[] = "Your WiFi Password"; //Your Wifi Password

char username[] = "Cayenne Username"; //This User Name From Cayenne Website
char password[] = "Cayenne Password"; //This Password From Cayenne Website
char clientID[] = "Cayenne ClientID"; //This Client ID From Cayenne Website

int light1 = 16; // Define Led Light
int light2 = 5;
int light3 = 4;

void setup() {
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);

  Serial.begin(115200);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);

}

void loop() {
  Cayenne.loop();
}

//Channels for Controlling Home Appliances
CAYENNE_IN(1)
{ CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());

  int i = getValue.asInt();
  digitalWrite(light1, i);
}

CAYENNE_IN(2)
{ CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());

  int j = getValue.asInt();
  digitalWrite(light2, j);
}

CAYENNE_IN(3)
{ CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());

  int k = getValue.asInt();
  digitalWrite(light3, k);
}
