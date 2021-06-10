#ifndef SONDA
#define SONDA

#include <OneWire.h> 
#include <DallasTemperature.h>

class Sonda {
  private:
    int pin;
    OneWire wire;
    DallasTemperature sensor;
  public:
    Sonda(int _pin);
    float Read();
};



#endif
