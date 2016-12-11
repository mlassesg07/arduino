const int kPinLed = 12;		//Sätter LED till pinne 12

void setup()
{
  pinMode(kPinLed, OUTPUT);	// Sätter kPinLed till OUTPUT
  Serial.begin(9600);		//Sätter hastigheten för serieporten till 9600
  }

int delayTime = 1000;		//Sätter den globala variabeln delayTime till 1000
          
void loop()
{
    delayTime = delayTime - 130; //Minskar delayTime med 100 så länge som delayTime >= 0 om inte resetas delayTime till 1000
      if(delayTime <= 0){
      delayTime = 1000;
		}
	Serial.print("delayTime = "); 	//Skriv ut texten delayTime i serialmonitor
	Serial.println(delayTime);	//Skriv ut värdet i variabeln delayTime i serialmonitor
	digitalWrite(kPinLed, HIGH);	//Sätter kPinLed till hög
	delay(delayTime);		//Väntar så länge som det står i variabeln delayTime
	digitalWrite(kPinLed, LOW);	//Sätter kPinLed till låg
	delay(delayTime);		//Väntar så länge som det står i variabeln delayTime
}
	

