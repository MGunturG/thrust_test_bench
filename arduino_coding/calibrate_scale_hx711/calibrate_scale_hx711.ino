// muhamad guntur feb 2/22/24
// code for calibrate your load cell with hx711 interface

#include <HX711.h>

// hx711 pin 
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  if (scale.is_ready()) {
    // 1. call set_scale() with no parameter.
    // 2. call tare() with no parameter.
    // 3. place a known weight on the scale and call set_units(10)
    // 4. divide the result in step 3 to your known weight. the result are parameter that
    //    will be used later for set_scale().
    //    
    //    calibration factor = (reading)/(known weight)
    //
    // 5. adjust the parameter in step 4 until get accurate reading.

    // 1
    scale.set_scale();
    Serial.println("Tare... remove any weights!");
    Serial.println("wait 5s.");
    delay(5000);

    // 2
    scale.tare();
    Serial.println("Tare done!");

    // 3
    Serial.println("Place a known weight on the scale!");
    delay(5000);
    long reading = scale.get_units(10);

    Serial.print("Result:");
    Serial.print(reading);

  } else {
    Serial.println("HX711 not found, check wiring!");
  }

  delay(1000);
}
