#include <Servo.h>

const int rightPin = 3; 
const int leftPin = 4;
const int buttonPin = 2;

int saltoQty=10;

Servo servoMotor;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  servoMotor.attach(2);
  servoMotor.write(0);
}
 
void loop() {
  
   if (digitalRead(leftPin) == LOW) { 
    saltoQty+=10;      
    delay(200);
  }

  if (digitalRead(rightPin) == LOW) { 
    saltoQty-=10;      
    delay(200);
  }

  // Desplazamos a la posición 0º
  servoMotor.write(saltoQty);
  // Esperamos 1 segundo
  delay(200);

  if(saltoQty==180){
    saltoQty=10;
    servoMotor.write(0);
  }else{
    if(saltoQty==0){
        saltoQty=170;
        servoMotor.write(170);
      }
  }

   
 
}