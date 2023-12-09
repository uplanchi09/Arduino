 #include <Servo.h>
#define trigPin 12
#define echoPin 11
Servo servo;
int sound = 250;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(9);
servo.write(0);
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
if (distance < 20) {
Serial.println("the distance is less than 20");
servo.write(180);
delay(2000);

servo.write(0);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(500);
}


