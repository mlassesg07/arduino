// DHT Temperature & Humidity Sensor
// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

// include the library code:
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            2         // Pin which is connected to the DHT sensor.

// Uncomment the type of sensor in use:
#define DHTTYPE           DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);   // initialize the library with the numbers of the interface pins

void setup() {
  lcd.begin(16, 2);                     // set up the LCD's number of columns and rows
  lcd.clear();                          // Clear LCD
  lcd.setCursor(0,0);                   // Set cursor to x=0 and y=0
  lcd.print("AD:s");            				// Print text on LCD
  lcd.setCursor(0,1);
  lcd.print("Termometer");
  delay(3000);
  //lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("Temperatur ute:");
}

//void setup() {
  //Serial.begin(9600); 
  // Initialize device.
  dht.begin();
  //lcd.println("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  //lcd.println("------------------------------------");
  //lcd.println("Temperature");
  //lcd.print  ("Sensor:       "); Serial.println(sensor.name);
  //lcd.print  ("Driver Ver:   "); Serial.println(sensor.version);
  //lcd.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  //lcd.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  //Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  //Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  //Serial.println("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  //Serial.println("------------------------------------");
  //Serial.println("Humidity");
  //Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  //Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  //Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  //Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  //Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  //Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  //Serial.println("------------------------------------");
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  lcd.begin(16, 2);                     // set up the LCD's number of columns and rows
  lcd.clear();                          // Clear LCD
  lcd.setCursor(0,0);                   // Set cursor to x=0 and y=0
  lcd.print("Innetemperatur:");
  lcd.setCursor(0,1);
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    lcd.print("Error reading temperature!");
  }
  else {
    //lcd.print("Temperatur: ");
    lcd.print(event.temperature);
    lcd.println(" *C");
  }
  // Get humidity event and print its value.
  lcd.begin(16, 2);                     // set up the LCD's number of columns and rows
  lcd.clear();                          // Clear LCD
  lcd.setCursor(0,0);                   // Set cursor to x=0 and y=0
  lcd.print("Luftfuktighet:");
  lcd.setCursor(0,1);
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    lcd.print("Error reading humidity!");
  }
  else {
    //lcd.print("Luftfuktighet: ");
    lcd.print(event.relative_humidity);
    lcd.println("%");
  }
}
