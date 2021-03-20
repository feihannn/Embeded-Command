#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BME280 bme;

unsigned long delayTime;
float suhu;

void setup() {
  Serial.begin(115200);
  bool status;
  //Setting BME
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  delayTime = 1000;
  //Setting OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Terhubung");
  display.display(); 
}
void loop(){
  //Membersihkan display dan mempersiapkan posisi awal print
  display.clearDisplay();
  display.setCursor(0, 0);
  //Menampilkan suhu sebelum diproses ke layar
  suhu=bme.readTemperature();
  display.print("Temperature= ");
  display.print(suhu);
  display.println("C");
  //Menampikan ketinggian sebelum diproses ke layar
  display.print("Altitude= ");
  display.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  display.println("m");
  //Menampilkan kelembapan sebelum diproses ke layar
  display.print("Humidity= ");
  display.print(bme.readHumidity());
  display.println("%");
  //Menampilkan tekanan sebelum diproses ke layar
  display.print("Pressure= ");
  display.print(bme.readPressure() / 100.0F);
  display.println("hPa");
  //Menampilkan suhu,tinggi,kelembapan,tekanan ke layar
  display.display(); 
  delay(delayTime);
  
}
