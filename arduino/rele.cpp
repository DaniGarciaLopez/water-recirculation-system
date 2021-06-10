#include "Arduino.h"
#include "rele.h"

Rele::Rele(int _pin){
  pin=_pin;
  pinMode(pin,OUTPUT);
}

void Rele::Set(const char modo[]){
  if (modo=="ABRIR"){
    digitalWrite(pin,LOW);
  }
  if (modo=="CERRAR"){
    digitalWrite(pin,HIGH);
  }
}

