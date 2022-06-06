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
    unsigned int uS = sonar.ping();
    unsigned int distance = uS / US_ROUNDTRIP_CM;
    String data_to_send = String(distance);
    Serial.println(data_to_send); 
    delay(1000);  
}
