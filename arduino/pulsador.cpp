#include "Arduino.h"
#include "pulsador.h"

Pulsador::Pulsador(int _pin){
  pin=_pin;
  pinMode(pin,INPUT);
}

bool Pulsador::Read(){
  return digitalRead(pin);
}

