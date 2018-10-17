/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "MPX4115A.h"
#include "Vcc.h"

MPX4115A::MPX4115A(uint8_t pin, double vccCorrection) {
  _pin = pin;
  _vcc = new Vcc(vccCorrection);
}

double MPX4115A::readKPa() {
  double vcc;
  double vout;
  double pressure;

  vcc = _vcc->Read_Volts();
  vout = ( analogRead( _pin ) / 1024.0 ) * vcc;

  // Vout = Vcc * ( 0.009p - 0.095 ) => p = ( ( Vout / Vcc ) + 0.095 ) / 0.009
  return ( ( vout / vcc ) + 0.095 ) / 0.009;
}

double MPX4115A::readMBar() {
  return readKPa() * 10.0;
}

double MPX4115A::readMmHg() {
  return readKPa() * 7.5;
}
