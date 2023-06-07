#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

const int buttonPin = 2;   
int contador = 0;

void setup() {
  Serial.begin(9600);    
  pinMode(buttonPin, INPUT_PULLUP); 
  Wire.begin();	
  oled.init();                       
  oled.clearDisplay();               
  oled.setTextXY(0,0);               
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { 
    
    oled.setTextXY(4,3); 
    oled.putString(String(contador)+ "  click's");
    contador++; 
    delay(500);
  }
}