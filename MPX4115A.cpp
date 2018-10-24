/*
  MPX4115A.h - Library for reading preassure values from MPX4115A type sensors.
  Created by Jan-Luca Klees, 2018-10-17
*/

#include "Arduino.h"
#include "MPX4115A.h"
#include "Vcc.h"

MPX4115A::MPX4115A(uint8_t pin, double vccCorrection) {
  _pin = pin;
  _vcc = new Vcc(vccCorrection);
}

/**
 * Reads out the pressure measured by the MPX4115A sensor in kPa
 * and corrects the value for the current supply voltage.
 *
 * This is the formular describing the sensor's readouts:
 * Vout = Vs * ( 0.009p - 0.095 )
 *
 * This can be rearranged so that we can calculate the pressure p with it:
 * p = ( ( Vout / Vs ) + 0.095 ) / 0.009
 *
 * As we connect the sensor to our Arduino, Vs will be equal to the Vcc.
 */
double MPX4115A::readKPa() {
  return ( ( readVout() / readVcc() ) + 0.095 ) / 0.009;
}

double MPX4115A::readMBar() {
  return readKPa() * 10.0;
}

double MPX4115A::readMmHg() {
  return readKPa() * 7.5;
}

/**
 * Function for reading out the Vcc as calculated by the Vcc library.
 * Use this function to calculate the Vcc correction to get more accurate
 * measurements.
 */
double MPX4115A::readVcc() {
  return _vcc->Read_Volts();
}

/**
 * Function for reading out the Vout, meaning the actual analog value outputted
 * by the  MPX4115A pressure sensor.
 */
double MPX4115A::readVout() {
  return ( analogRead( _pin ) / 1023.0 ) * readVcc();
}
