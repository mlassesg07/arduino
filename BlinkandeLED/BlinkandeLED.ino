const int PinLed1 = 10; //Led1 till pinne 10
const int PinLed2 = 11; //Led2 till pinne 11
const int PinLed3 = 12; //Led3 till pinne 12
const int PinLed4 = 13; //Led4 till pinne 13

void setup() {
  // put your setup code here, to run once:
  pinMode(PinLed1, OUTPUT); //Sätter PinLed1 till OUTPUT
  pinMode(PinLed2, OUTPUT); //Sätter PinLed2 till OUTPUT
  pinMode(PinLed3, OUTPUT); //Sätter PinLed3 till OUTPUT
  pinMode(PinLed4, OUTPUT); //Sätter PinLed4 till OUTPUT

}

int delayTime = 1000; //Sätter variabel delayTime som integer

void loop() {
  // put your main code here, to run repeatedly:



  /*{
    delayTime = delayTime - 100;
    if(delayTime <= 0)
    { // If the delay time is zero or !! "" less, reset it.
    delayTime = 1000;
    } */

  {
    digitalWrite(PinLed1, HIGH);  //Sätter Led1 till hög
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed1, LOW);   //Sätter Led1 till låg
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed2, HIGH);  //Sätter Led2 till hög
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed2, LOW);   //Sätter Led2 till låg
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed3, HIGH);  //Sätter Led3 till hög
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed3, LOW);   //Sätter Led3 till låg
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed4, HIGH);  //Sätter Led4 till hög
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed4, LOW);   //Sätter Led4 till låg
    delay(1000);                  //Väntar 1sek
    digitalWrite(PinLed1, HIGH);  //Sätter Led1 till hög
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed1, LOW);   //Sätter Led1 till låg
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed2, HIGH);  //Sätter Led2 till hög
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed2, LOW);   //Sätter Led2 till låg
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed3, HIGH);  //Sätter Led3 till hög
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed3, LOW);   //Sätter Led3 till låg
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed4, HIGH);  //Sätter Led4 till hög
    delay(500);                   //Väntar 0,5sek
    digitalWrite(PinLed4, LOW);   //Sätter Led4 till låg
    delay(500);                   //Väntar 0,5sek

  }
}
