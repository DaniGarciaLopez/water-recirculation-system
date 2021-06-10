#ifndef CAUDALIMETRO
#define CAUDALIMETRO


class Caudalimetro{
  private: //Atributos=variables
    int pin;
  public: //Metodos=funciones
    Caudalimetro(int _pin);
    bool Read();
};

#endif
