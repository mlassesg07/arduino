const int kPinLed = 13;		//Sätter LED till pinne 13

void setup()
{
  pinMode(kPinLed, OUTPUT);	// Sätter kPinLed till OUTPUT
  Serial.begin(9600);		//Sätter hastigheten för serieporten till 9600
  }

int delayTime = 1000;		//Sätter den globala variabeln delayTime till 1000
          
void loop()
{
    delayTime = delayime - 100; //Minskar delayTime med 100 så länge som delayTime >= 0 om inte resetas delayTime till 1000
    IF(delayTime <= 0){
      delayTime = 1000;
		}
	Serial.print("delayTime = "); 	//Skriv ut texten delayTime i serialmonitor
	Serial.println(delayTime);	//Skriv ut värdet i variabeln delayTime i serialmonitor
	digitalWrite(kPinLed, HIGH);	//Sätter kPinLed till hög
	delay(delayTime);		//Väntar så länge som det står i variabeln delayTime
	digitalWrite(kPinLed, LOW);	//Sätter kPinLed till låg
	delay(delayTime);		//Väntar så länge som det står i variabeln delayTime
}
	

