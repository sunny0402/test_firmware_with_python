#include <NewPing.h>

String cmd;

#define TRIGGER_PIN  4  // Arduino pin 4 tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     3  // Arduino pin 3 tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 20 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

#define ULTRASONIC

void setup()
{
  Serial.begin(115200);

}

void loop()
{
  ////No data available. Do nothing.
  while(Serial.available()==0){}
  //Read command from python
  cmd = Serial.readStringUntil("\r");
  if(cmd=="Measure"){
    //delay(1000);                      // Wait 1000ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    Serial.print("Ping: ");
    Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
  }
     if(cmd=="OFF"){
     Serial.println("OFF");
   }
}
