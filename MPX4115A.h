/*
  MPX4115A.h - Library for reading preassure values from MPX4115A type sensors.
  Created by Jan-Luca Klees, 2018-10-17
*/

#ifndef MPX4115A_H
#define MPX4115A_H

#include "Arduino.h"
#include "Vcc.h"

class MPX4115A {
  public:
    MPX4115A( uint8_t pin, double vccCorrection = 1 );
    double readKPa();
    double readMBar();
    double readMmHg();
  private:
    uint8_t _pin, _type;
    Vcc* _vcc;
};

#endif
