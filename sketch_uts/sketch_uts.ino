#include <Ultrasonic.h>
#include "AudioGeneratorAAC.h"
#include "AudioOutputI2S.h"
Ultrasonic ultrasonic(13, 12);
AudioGeneratorAAC *aac;
AudioOutputI2S *out;
int threshold=//suatu nilai thershold yang ditetapkan;
void setup() {
  Serial.begin(115200);
  bool success=setupsound();
  if(!success){
    for(;;){
    }
  }
  else{
  }
}
void loop(){
  if(ultrasonic.read()<threshold){
    soundup();  
  }
  else{
    sounddown();
  }
}
