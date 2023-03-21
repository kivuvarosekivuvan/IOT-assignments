#include <Servo.h>

#define temperature A1


Servo mainServo;
int position = 0;
int previousPosition;

void setup() {
  
  pinMode(temperature, INPUT);
  mainServo.attach(5);
  
  Serial.begin(9000);

}

void loop() {
  
  int tempReading = analogRead(temperature);
  float voltage = tempReading * 5.0; 
  
  voltage /= 1024.0;
  float tempC = (voltage - 0.5) * 100;
  
  int position = map(tempC, 0, 50, 0, 180);
  Serial.println(position);
  if(previousPosition >30 ){
     mainServo.write(90);
     delay(1200);
  }
}
