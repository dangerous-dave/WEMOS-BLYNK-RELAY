
 #define BLYNK_PRINT Serial  // Comment this out to disable prints and save space  
 #define RELAY_PIN D1  
 #define BLYNK_DEBUG        // Optional, this enables more detailed prints
 #include <ESP8266WiFi.h>  
 #include <BlynkSimpleEsp8266.h>  
 #include <SimpleTimer.h>      // Essential for almost all sketches
 #include <Ticker.h>  
 // You should get Auth Token in the Blynk App.  
 // Go to the Project Settings (nut icon).  
 char auth[] = "AUTH";  
 // Your WiFi credentials.  
 // Set password to "" for open networks.  
 char ssid[] = "SSID";  
 char pass[] = "PASS";  
 bool vPinState = false;        // Set the default virtual pin state  
 Ticker doorLatch;           // Callback fuction instance  
 void setPinLow()  
 {  
  digitalWrite(RELAY_PIN, 0);  
  doorLatch.detach();  
 }  
 void setup()  
 {  
  Serial.begin(9600);  
  Blynk.begin(auth, ssid, pass);  
  pinMode(RELAY_PIN, OUTPUT);  
  digitalWrite(RELAY_PIN, 0);  
 }  
 void loop()  
 {  
  Blynk.run();  
 }  
 BLYNK_WRITE(V0)  
 {  
  // Get the virtual input state  
  vPinState = param.asInt();  
  // If the virtual input went high  
  if(vPinState)  
  {  
   // Open the relay  
   digitalWrite(RELAY_PIN, 1);   
  }  
 }  
