// set pin numbers
const int touchPin = 4; 
const int ledPin = 16;
const int lampu2= 15;
const int lampu3=17;


// change with your threshold value
const int threshold = 20;
// variable for storing the touch pin value 
int touchValue;

void setup(){
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  // initialize the LED pin as an output:
  pinMode (ledPin, OUTPUT);
  pinMode (lampu2, OUTPUT);
   pinMode (lampu3, OUTPUT);
}

void loop(){
  // read the state of the pushbutton value:
  touchValue = touchRead(touchPin);
  Serial.print(touchValue);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(ledPin,HIGH);
    delay(200);
    digitalWrite(lampu2,HIGH);
    delay(200);
    digitalWrite(lampu3,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    delay(200);
    digitalWrite(lampu2,LOW);
    delay(200);
    digitalWrite(lampu3,LOW);
    delay(200);
  }
  else{
    // turn LED off
    digitalWrite(ledPin, LOW);
    digitalWrite(lampu2,LOW);
    digitalWrite(lampu3,LOW);
  }
}
