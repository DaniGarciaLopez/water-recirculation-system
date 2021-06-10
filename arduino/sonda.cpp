#include "Arduino.h"
#include "sonda.h"
#include <OneWire.h>
#include <DallasTemperature.h>


Sonda::Sonda(int _pin) : wire(_pin),sensor(&wire){
  pin=_pin;
  sensor.begin();
}

float Sonda::Read(){
  sensor.requestTemperatures();
  return sensor.getTempCByIndex(0); 
}

