// Example for reading out the MPX4115A pressure sensor
// Written by Jan-Luca Klees

#include <MPX4115A.h>

// initialize the MPX4115A
#define MPX4115A_PIN 1 // the analoge pin to use
MPX4115A mpx4115a(MPX4115A_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the pressure in various units
  double kPa = mpx4115a.readKPa();
  double mBar = mpx4115a.readMBar();
  double mmHg = mpx4115a.readMmHg();

  Serial.print("Pressure: ");
  Serial.print(kPa);
  Serial.print(" kPa, ");
  Serial.print(mBar);
  Serial.print(" mBar, ");
  Serial.print(mmHg);
  Serial.println(" mmHg");

  delay(1000);
}
