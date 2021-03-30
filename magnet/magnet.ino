int val = 0;
const int ledPin = 16;
const int lampu2= 15;

void setup() {
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
  pinMode(lampu2, OUTPUT);
}

// put your main code here, to run repeatedly
void loop() {
  // read hall effect sensor value
  val = hallRead();
  if (val>50){
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(lampu2,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    delay(500);
    digitalWrite(lampu2,LOW);
    delay(500);
  }
  else{
    digitalWrite(ledPin,LOW);
    digitalWrite(lampu2,LOW);
  }
  // print the results to the serial monitor
  Serial.println(val); 
  //delay(1000);
}
