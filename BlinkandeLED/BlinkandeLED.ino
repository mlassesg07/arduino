const int PinLed1 = 10; //Led1 till pinne 10
const int PinLed2 = 11; //Led2 till pinne 11
const int PinLed3 = 12; //Led3 till pinne 12
const int PinLed4 = 13; //Led4 till pinne 13

void setup() {
  // put your setup code here, to run once:
  pinMode(PinLed1, OUTPUT);
  pinMode(PinLed2, OUTPUT);
  pinMode(PinLed3, OUTPUT);
  pinMode(PinLed4, OUTPUT);

}

int delayTime = 1000;

void loop() {
  // put your main code here, to run repeatedly:



  /*{
    delayTime = delayTime - 100;
    if(delayTime <= 0)
    { // If the delay time is zero or !! "" less, reset it.
    delayTime = 1000;
    } */

  {
    digitalWrite(PinLed1, HIGH);
    delay(1000);
    digitalWrite(PinLed1, LOW);
    delay(1000);
    digitalWrite(PinLed2, HIGH);
    delay(1000);
    digitalWrite(PinLed2, LOW);
    delay(1000);
    digitalWrite(PinLed3, HIGH);
    delay(1000);
    digitalWrite(PinLed3, LOW);
    delay(1000);
    digitalWrite(PinLed4, HIGH);
    delay(1000);
    digitalWrite(PinLed4, LOW);
    delay(1000);
    digitalWrite(PinLed1, HIGH);
    delay(500);
    digitalWrite(PinLed1, LOW);
    delay(500);
    digitalWrite(PinLed2, HIGH);
    delay(500);
    digitalWrite(PinLed2, LOW);
    delay(500);
    digitalWrite(PinLed3, HIGH);
    delay(500);
    digitalWrite(PinLed3, LOW);
    delay(500);
    digitalWrite(PinLed4, HIGH);
    delay(500);
    digitalWrite(PinLed4, LOW);
    delay(500);

  }
}
