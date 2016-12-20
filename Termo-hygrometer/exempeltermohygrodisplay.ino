// Config temperature sensor
#include "DHT.h"
#define DHTPIN 5     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// Config lcd
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#define LCD_ADDR 0x3F 
LiquidCrystal_I2C lcd(LCD_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  dht.begin();

  lcd.begin(16,2);

  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Starting...");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("DHT11 Temp/Humid");
}

void loop() {
  // Wait a few seconds between measurements.
  delay(5000);

  // Read temp / humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  lcd.clear();
  if (isnan(h) || isnan(t)) {
    lcd.print("Reading error");
    return;
  }
  lcd.print("Temp: ");
  lcd.print((int)t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print((int)h);
  lcd.print("%");
}
