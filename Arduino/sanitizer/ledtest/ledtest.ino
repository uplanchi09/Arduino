








#define BLYNK_PRINT Serial



#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>



// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "1F_4_Z19ke-crgtl8cO3NhArAFJSBmCG";



// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "ETPL-4G";

char pass[] = "Fifi@0910";



BLYNK_WRITE(V0)

{

  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  // You can also use:

  // String i = param.asStr();

  // double d = param.asDouble();

  analogWrite(D1,pinValue);

  Blynk.virtualWrite(V1, pinValue);

  Serial.print("V0 Slider value is: ");

  Serial.println(pinValue);

}



void setup()

{

  // Debug console

  Serial.begin(9600);



  Blynk.begin(auth, ssid, pass);

  // You can also specify server:

  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);

  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

}
