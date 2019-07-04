#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial mySerial(D5, D6); // RX, TX


void setup() {
  pinMode(D0, OUTPUT);
  Serial.begin(9600);//PC - NODE
  mySerial.begin(9600);//NODE - PC
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (mySerial.available()) {
    //receive Serial Port
    char command = mySerial.read();
    Serial.print(command);
    Serial.println();
    switch(command) {
      case 't':
        mySerial.print(temperature);
        mySerial.print("c");
        break;
      case 'h':
        mySerial.print(humidity);
        mySerial.print("%");
        break;
      case 'a':
        digitalWrite(D0, LOW);
        mySerial.print("LED ON");
        break;
      case 'b':
        digitalWrite(D0, HIGH);
        mySerial.print("LED OFF");
        break;
    }
  }
}
