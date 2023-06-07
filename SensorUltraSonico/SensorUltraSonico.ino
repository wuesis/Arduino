
const int trigger = 2;
const int echo = 3;
const int led = 4;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(trigger,LOW);
}

void loop() {
   long t;
   long d;

  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);

  t = pulseIn(echo,HIGH);
  d = t/59;
 
  if(d<10)
    digitalWrite(led,HIGH);
  else
     digitalWrite(led,LOW);

 
  delay(100);
}
