#ifndef PULSADOR
#define PULSADOR


class Pulsador{
  private: //Atributos=variables
    int pin;
  public: //Metodos=funciones
    Pulsador(int _pin); //Constructor 
    bool Read();     
};

#endif

