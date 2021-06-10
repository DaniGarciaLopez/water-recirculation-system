#ifndef ULTRASONICO
#define ULTRASONICO

class Ultrasonico {
  private:
    int pinTrig;
    int pinEcho;
    int Max;
    int Min;
  public:
    Ultrasonico(int _pinEcho, int _pinTrig);
    void SetMaxMin(int _max, int _min);
    float Read();
    int ReadPorcentaje();
};


#endif
