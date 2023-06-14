int Liquid_level=0;
#define RELAY_PIN 7
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int light;    // variable to read the value from the analog pin
 
 
void setup() {
 
Serial.begin(9600);
pinMode(5,INPUT);
pinMode(RELAY_PIN, OUTPUT);
myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}
 
void loop() {
 
  Liquid_level=digitalRead(5);
 
  light=analogRead(0);   //connect grayscale sensor to Analog 0
 
  Serial.print("Liquid_level=");
  Serial.print(Liquid_level,DEC);
  Serial.print(" - Φως=");
  Serial.println(light,DEC);//print the value to serial
 
  if (Liquid_level==0 && light>500){
    digitalWrite(RELAY_PIN, HIGH);
  } else {
     digitalWrite(RELAY_PIN, LOW)  ;
  }
  
  if (light>500){
    myservo.write(0);
  } else {
    myservo.write(180);
  }
 
delay(100);
 
}
 
