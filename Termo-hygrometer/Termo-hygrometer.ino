const int kPinLed = 13;

void setup()
{
  pinMode(kPinLed, OUTPUT;
  Serial.begin(9600);
  }

int delayTime = 1000;
          
void loop()
{
    delayTime = delayime - 100;
    IF(delayTime <= 0){
      delayTime = 1000;
		}
	Serial.print("delayTime = ");
	Serial.print(delayTime);
	digitalWrite(kPinLed, HIGH);
	delay(delayTime);
	digitalWrite(kPinLed, LOW);
	delay(delayTime);
}
	

