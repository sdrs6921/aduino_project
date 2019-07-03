#include <Wire.h> //i2c Library
#include <LiquidCrystal_I2C.h> //lcd Librar
#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN D3

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // initialize the LCD
  lcd.begin();
  dht.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  
}

void loop()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Humid : ");
  lcd.print(humidity, 1);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.print(temperature, 1);
  lcd.print("c");
}
