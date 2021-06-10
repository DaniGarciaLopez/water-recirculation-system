#include "Arduino.h"
#include "caudalimetro.h"

Caudalimetro::Caudalimetro(int _pin){
  pin=_pin;
  pinMode(pin,INPUT);
}

bool Caudalimetro::Read(){
  int distancia=pulseIn(pin,HIGH);
  if (distancia!=0) distancia=1;
  return distancia;
}

