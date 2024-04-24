// muhamad guntur 2/22/24
// oled lcd testing hello world

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// screen resolution
#define SCREEN_W 128
#define SCREEN_H 64

// declare ssd1306
Adafruit_SSD1306 display(SCREEN_W, SCREEN_H, &Wire, -1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  // setting for text displayed on screen
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

  // displaying static text
  display.println("Hello, World!");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  // no need
}
