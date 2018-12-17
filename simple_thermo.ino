// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.
// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
/*
Writing Sensor Data to an SD card
//
This example shows how to write data
to an SD card using the SD library.
//
The circuit:
* SD card attached to SPI bus as follows:
** MOSI - pin 11
** MISO - pin 12
** CLK - pin 13
** CS - pin 10 Uno (53 on Mega)
Based on code by Tom Igoe
*/
//
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SD.h>
#include <SPI.h>

#define DHTPIN            2         // Pin which is connected to the DHT sensor.

// Uncomment the type of sensor in use:
#define DHTTYPE           DHT11     // DHT 11 
//#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

//the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD
// library functions will not work.

const int CSpin = 10;

String dataString =""; // holds the data to be written to the SD card

//float sensorReading1 = 0.00; // value read from your first sensor
//float sensorReading2 = 0.00; // value read from your second sensor
//float sensorReading3 = 0.00; // value read from your third sensor

File sensorData;

//
//

const int PinLed2 = 11; //Led1 till pinne 11

const int PinLed3 = 12; //Led2 till pinne 12

const int PinLed4 = 13; //Led3 till pinne 13

void setup() {

  // put your setup code here, to run once:

  pinMode(PinLed1, OUTPUT); //Sätter PinLed1 till OUTPUT

  pinMode(PinLed2, OUTPUT); //Sätter PinLed2 till OUTPUT

  pinMode(PinLed3, OUTPUT); //Sätter PinLed3 till OUTPUT

  Serial.begin(9600); 

  Serial.print("Initializing SD card...");

  pinMode(CSpin, OUTPUT);

  // Initialize device.

  dht.begin();

  Serial.println("DHTxx Unified Sensor Example");

  // Print temperature sensor details.

  sensor_t sensor;

  dht.temperature().getSensor(&sensor);

  Serial.println("------------------------------------");

  Serial.println("Temperature");

  Serial.print  ("Sensor:       "); Serial.println(sensor.name);

  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);

  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);

  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");

  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");

  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  

  Serial.println("------------------------------------");

  // Print humidity sensor details.

  dht.humidity().getSensor(&sensor);

  Serial.println("------------------------------------");

  Serial.println("Humidity");

  Serial.print  ("Sensor:       "); Serial.println(sensor.name);

  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);

  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);

  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");

  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");

  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  

  Serial.println("------------------------------------");

  // Set delay between sensor readings based on sensor details.

  //delayMS = sensor.min_delay / 1000;

  delayMS = 3000;

}

}

int delayTime = 1000; //Sätter variabel delayTime som integer


void loop() {
// put your main code here, to run repeatedly:
// Delay between measurements.

  delay(delayMS);

  // Get temperature event and print its value.

  sensors_event_t event;  

  dht.temperature().getEvent(&event);

  if (isnan(event.temperature)) {

    Serial.println("Error reading temperature!");

  }

  else {

    Serial.print("Temperatur: ");

    Serial.print(event.temperature);

    Serial.println(" *C");

    if ((event.temperature) <= 16)
    {
      //Tänder Led1
      digitalWrite(PinLed1, HIGH);  //Sätter Led1 till hög

      delay(400);                  //Väntar 0,4sek

      digitalWrite(PinLed1, LOW);   //Sätter Led1 till låg

      delay(400);                  //Väntar 0,4sek
    }
    
    else if ((event.temperature) >= 17 && (event.temperature) < 19)
{
  //Tänder Led2      
      digitalWrite(PinLed2, HIGH);  //Sätter Led2 till hög

      delay(400);                  //Väntar 0,4sek

      digitalWrite(PinLed2, LOW);   //Sätter Led2 till låg

      delay(400);                  //Väntar 0,4sek
}
  else
{
  //Tänder Led3
      digitalWrite(PinLed2, HIGH);  //Sätter Led2 till hög

      delay(400);                  //Väntar 0,4sek

      digitalWrite(PinLed2, LOW);   //Sätter Led2 till låg

      delay(400);                  //Väntar 0,4sek
}
    
  }

  // Get humidity event and print its value.

  dht.humidity().getEvent(&event);

  if (isnan(event.relative_humidity)) {

    Serial.println("Error reading humidity!");

  }

  else {

    Serial.print("Luftfuktighet: ");

    Serial.print(event.relative_humidity);

    Serial.println("%");

  }

}
