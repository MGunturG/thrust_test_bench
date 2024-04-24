// muhamad guntur 2/22/24
// scaling some weight

#include <Arduino.h>
#include <HX711.h>

// hx711 pin
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

// data from calibration
float calibration_scale = 0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial.println("Initializing scale...");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); 

  Serial.println("Set calibration factor...");
  scale.set_scale(calibration_scale); // edit by your own reading on calibration code

  Serial.println("Tare...");
  scale.tare();

  Serial.println("Start reading!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 5);

  delay(3000);
}
