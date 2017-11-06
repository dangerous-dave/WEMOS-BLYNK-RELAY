 #define BLYNK_PRINT Serial  // Comment this out to disable prints and save space  
 #define RELAY_PIN D1  
 #include <ESP8266WiFi.h>  
 #include <BlynkSimpleEsp8266_SSL.h>  
 #include <Ticker.h>  
 // You should get Auth Token in the Blynk App.  
 // Go to the Project Settings (nut icon).  
 char auth[] = "AUTH";  
 // Your WiFi credentials.  
 // Set password to "" for open networks.  
 char ssid[] = "WIFI";  
 char pass[] = "PASS";  
 bool vPinState = false;        // Set the default virtual pin state  
 int maxRelayOnTime = 10;       // Set the max on time of the relay   
 int minRelayOnTime = 1;        // Set the minimum on time of the relay  
 int vDelayTime = minRelayOnTime;   // Set the initial delay time value  
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
   // Turn off the relay after the defined delay time  
   doorLatch.attach(vDelayTime, setPinLow);  
  }  
 }  
 BLYNK_WRITE(V1)  
 {  
  // Get the input from the virtual input slider  
  vDelayTime = param.asInt();  
  // Constrain the virtual slider input to within the preset bounds  
  vDelayTime = constrain(vDelayTime, minRelayOnTime, maxRelayOnTime);  
 }  
