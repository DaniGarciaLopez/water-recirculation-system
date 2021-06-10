#include "Arduino.h"
#include "ultrasonico.h"


Ultrasonico::Ultrasonico(int _pinEcho, int _pinTrig){
  pinEcho=_pinEcho;
  pinTrig=_pinTrig;
  pinMode(pinEcho,INPUT);
  pinMode(pinTrig,OUTPUT);
}

void Ultrasonico::SetMaxMin(int _max, int _min){
  Max=_max;
  Min=_min;
}

float Ultrasonico::Read(){
  float tiempo;
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10); //Hacemos un delay para estabilizar los valores
  digitalWrite(pinTrig, LOW);
  tiempo = (pulseIn(pinEcho, HIGH)/2); //Medimos el pulso de respuesta
  float distancia=tiempo * 0.0343;
  return distancia;
}

int Ultrasonico::ReadPorcentaje(){
  float distancia=this->Read();
  if (distancia>Max){
    distancia=Max;
  } 
  if (distancia<Min){
    distancia=Min;
  } 
  delay(10);
  return map(distancia,Min,Max,100,0);
}


