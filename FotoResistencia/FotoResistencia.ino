const int LEDPin = 2;
const int LDRPin = A0;

void setup()
{
pinMode(LEDPin, OUTPUT); 
pinMode(LDRPin, INPUT);
} 

void loop()
{
  int value = digitalRead(LDRPin);
  if (value == HIGH)
  {
    digitalWrite(LEDPin, HIGH);
  }else {
    digitalWrite(LEDPin, LOW);
    delay(500);
  }
}