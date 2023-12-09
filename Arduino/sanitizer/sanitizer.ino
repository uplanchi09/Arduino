#include<Servo.h>  // Include the Servo library   
#define trigPin 12  //Defines the pins number 
#define echoPin 11  
#define buzzer 13
#define ledPin 8  

Servo servo;    // created a servo object
long duration;  //defines variables
int distance;   
int safetyDistance;  

void setup() {
Serial.begin (9600);  // starts the serial communication
pinMode(trigPin, OUTPUT);  // sets the trigpin as an output 
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
servo.attach(9);         //We need to attach the servo to the used pin number 
servo.write(0);          // make servo to 0 degree
}
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);   // Clears the trigPin
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);    // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);       // Reads the echoPin, returns the sound wave travel time in microseconds
distance = duration*0.034/2;             // Calculating the distance

safetyDistance = distance;
if (safetyDistance <= 26)   
{
  digitalWrite(buzzer, HIGH);
  tone(buzzer,523,300);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

if (distance < 29) {
Serial.println("the distance is less than 29");
servo.write(90);    //Make servo go to 90 degrees 
delay(400);
servo.write(0);     // it will come to original degrre
}
if (distance > 30 || distance <= 0){
Serial.println("The distance is more than 30");}
else {
Serial.print(distance);       // Prints the distance on the Serial Monitor
Serial.println("distance");
}delay(400);
}




