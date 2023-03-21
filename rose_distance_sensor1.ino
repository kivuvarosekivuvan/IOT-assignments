#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); 
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
void setup() {
lcd.begin(16,2); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.5/2;
distanceInch = duration*0.0195/2;
lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm); 
lcd.print(" cm");
delay(7);
lcd.setCursor(0,5);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(7);
}









































