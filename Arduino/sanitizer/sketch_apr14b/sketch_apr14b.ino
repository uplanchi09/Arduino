
const int trigPin =9;
const int echoPin =10;
const int buzzer =11;


long duration;
int distance;
int safetyDistance;

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
}
void loop() {
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance =duration*0.034/2;


safetyDistance = distance;
if (safetyDistance <= 25)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer, HIGH);
}
else{
digitalWrite(buzzer, LOW);

}

Serial.print(distance);
Serial.println(" cm");
}





