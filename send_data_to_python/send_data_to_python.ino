#include <NewPing.h>

String cmd;

#define TRIGGER_PIN  4  
#define ECHO_PIN     3  
#define MAX_DISTANCE 20 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

#define ULTRASONIC

void setup()
{
  Serial.begin(115200);

}

void loop()
{               
    unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
    Serial.print("Ping: ");
    Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
    delay(1000);  
}
