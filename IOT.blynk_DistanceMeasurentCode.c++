#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<HCSR04.h>
#define trig D6
#define echo D5
HCSR04 hc(trig,echo);

char auth[] = "l_XwI8U149d1GpzW8_Nd25nEte8eNzuh";
char ssid[] = "Redmi Note 9";   // your ssid 
char pass[] = "123456789"; // your pass

 

BlynkTimer timer;

void sendSensor()
{
  int c = hc.dist();
  if ( c == 0 ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  Blynk.virtualWrite(V5, c);  // select virtual pin (v5) in blynk app
  
 
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();    }
