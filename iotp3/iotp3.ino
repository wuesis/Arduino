#include "arduino_secrets.h"
#include <Wire.h>
#include <DHTesp.h>
#include "thingProperties.h"
#include <ACROBOTIC_SSD1306.h>

DHTesp dht;
int contadorPantalla = 0;
int buttonPin = 1;  

void setup() {
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(23, OUTPUT);
  dht.setup(4,DHTesp::DHT22);

  pinMode(buttonPin, INPUT_PULLUP); 
  Wire.begin();	
  oled.init();                       
  oled.clearDisplay();               
  oled.setTextXY(0,0); 
  oled.setTextXY(4,3); 
  oled.putString(String(contador)+ "  click's"); 
}

void loop() {
  //Configuracion y asignacion de variables
  ArduinoCloud.update();
  sensor_DHT22_Temperatura = dht.getTemperature();
  sensor_DHT22_Humedad = dht.getHumidity();
  oled.setTextXY(4,1); 
  oled.putString(String(contadorPantalla)+ "  click's");
  
  //Foco
  if(foco){
    digitalWrite(23, HIGH); 
    oled.setTextXY(3,1); 
    oled.putString("Foco: On");
  }
  else{
   digitalWrite(23, LOW);
   oled.setTextXY(3,1);
   oled.putString("Foco: Off");
  }
 
  //Pantalla
  if (digitalRead(buttonPin) == HIGH) { 
    oled.setTextXY(4,1); 
    contadorPantalla++;
    oled.putString(String(contador)+ "  click's");
    onContadorChange();
  }


  //Sensor de temperatura y humedad
  oled.setTextXY(0,1); 
  oled.putString(String(sensor_DHT22_Humedad) + "% humedo");
  oled.setTextXY(7,1); 
  oled.putString(String(sensor_DHT22_Temperatura) + " °C");

  delay(5000);
}

void onContadorChange()  {
  contador = contadorPantalla;
}

void onFocoChange(){

}