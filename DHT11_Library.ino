/*
 * library  Manager -> DHT11 by Adafruit Installed
 * Download Adafruit Sensor Master Library
 * add .zipLibrary
 * File -> example -> DHT sensor library -> DHT tester
*/
#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN D3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  Serial.print("Humidity : ");
  Serial.print(h);
  Serial.print("Tempearture :");
  Serial.println(t);

  if (t > 23)
    digitalWrite(D0, HIGH);
  else
    digitalWrite(D0, LOW);
}
