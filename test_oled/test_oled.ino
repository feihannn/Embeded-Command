/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("My Name Is Feihan");
  //Banner
  display.drawRect(0,0,128,10,WHITE);
  //Kepala dan Badan
  display.drawCircle(64, 20, 8, WHITE);
  display.fillCircle(64, 20, 8, WHITE);
  display.drawRect(54, 28, 20, 15, WHITE);
  //Tangan
  display.drawLine(54, 28, 44, 10, WHITE);
  display.drawLine(74, 28, 84, 10, WHITE);
  display.display(); 
  delay(100);
 
}

void loop() {
  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(500);
  display.stopscroll();
  delay(250);
  display.startscrollleft(0x00, 0x0F);
  delay(500);
  display.stopscroll();
  delay(250);
  display.startscrolldiagright(0x00, 0x07);
  delay(500);
  display.startscrolldiagleft(0x00, 0x07);
  delay(500);
  display.stopscroll();
  delay(250);
}
