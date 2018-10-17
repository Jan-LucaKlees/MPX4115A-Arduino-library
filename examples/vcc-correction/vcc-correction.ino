// Example to setup Vcc correction for more accurate readings for the MPX4115 pressure sensor.
// Written by Jan-Luca Klees

#include <MPX4115A.h>

/**
 * This small guide assumes that you have your MPX4115A pressure sensor wired up to the 5V and
 * GND of your Arduino.
 * 
 * To understand why you would need to correct your Vcc readings, we need to first understand
 * how the MPX4115A pressure sensor and this library works.
 * 
 * HOW DOES THIS LIBRARY TAKE READINGS?
 * 
 * Due to the nature of the MPX4115A pressure sensor, the output voltage is dependent on the
 * input voltage. This means to take accurate readings you need to put the output voltage
 * into context of the input voltage. This library does that for you automatically.
 * 
 * 
 * If everything happens automatically, then why do I still need to correct my Vcc readings?
 * 
 * WHY SHOULD I CORRECT MY VCC READINGS?
 * 
 * With your sensor wired up to your Arduino, we can use the Vcc library by Yveaux [1] to
 * determine the current Vcc of your Arduino and thus the input voltage of our MPX4115A
 * pressure sensor.
 * However, chances are that this reading might not be quite on point. It will definitely be
 * better than just assuming - or hard-coding - the Vcc of your Arduino, but we can improve
 * it by correcting the Vcc readings and thus improve the accuracy of our measurements.
 * 
 * HOW TO CORRECT YOUR VCC:
 * 
 * 1. Run this example and put the reported Vcc into the REPORTED_VCC constant
 *    In my case it was 4.69 volts.
 */

const double REPORTED_VCC = 4.69; // replace the 4.69 with the actually reported value

/**
 * 2. Take your multi-meter and measure the voltage across 5V and GND of your Arduino.
 *    In my case it measured was 4.74 volts.
 */

const double MEASURED_VCC = 4.74; // again, replace the 4.74 with what you measured with your multi-meter.

/**
 * 3. Check if the reported Vcc now shows the value you measured with your multi-meter
 * 
 * 
 * [1] https://github.com/Yveaux/Arduino_Vcc
 */

// initialize the MPX4115A
#define MPX4115A_PIN 1 // the analoge pin to use
const double VCC_CORRECTION = MEASURED_VCC/REPORTED_VCC;  // Measured Vcc by multimeter divided by reported Vcc
MPX4115A mpx4115a(MPX4115A_PIN, VCC_CORRECTION); // feed in the Vcc correction as well


// 4.73/4.69

void setup() {
    Serial.begin(9600);
}

void loop(){
  double kPa = mpx4115a.readKPa();
  double vcc = mpx4115a.readVcc();
    
  Serial.print("Pressure in kPa: ");
  Serial.print(kPa);
  Serial.print(", reported Vcc: ");
  Serial.println(vcc);
    
  delay(1000);
}
