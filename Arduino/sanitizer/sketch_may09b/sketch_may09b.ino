#include <Servo.h>
#define trigPin 12
#define echoPin 11
Servo servo;
int sound = 250;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(8);
}
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 28) {
Serial.println("the distance is less than 28");
servo.write(180);
delay(1000);
}
else {
servo.write(0);
}
if (distance > 30 || distance <= 0){
Serial.println("The distance is more than 30");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
}

