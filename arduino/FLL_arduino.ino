#include "sonda.h"
#include "rele.h"
#include "ultrasonico.h"
#include "pulsador.h"
#include "caudalimetro.h"

#define temperatura 16
#define nivel 10

Rele V1(29);
Rele V2(30);
Rele V3(31);
Rele V4(32);
Rele BI(34);
Rele B2(33);
Rele B3(35);
Rele R1(36);
Sonda T1(14);
Ultrasonico N1(3, 2);
Ultrasonico N2(5, 4);
Ultrasonico N3(7, 6);
Pulsador P1(10);
Pulsador P2(9);
Pulsador P3(8);
Caudalimetro C1(37);

void setup() {
  Serial.begin(9600);
  N1.SetMaxMin(15,5);
  N2.SetMaxMin(8,3);
  N3.SetMaxMin(15,5);
}

void loop(){
  
  bool check=0;  

  if (P2.Read() && !P1.Read() && !P3.Read() && !check) { //Estado 1
    V1.Set("CERRAR");
    V2.Set("ABRIR");
    V3.Set("CERRAR");
    V4.Set("CERRAR");
    BI.Set("CERRAR");
    B2.Set("ABRIR");
    B3.Set("CERRAR");
    R1.Set("CERRAR");

    //1,50,70,30,21,0
    
    Serial.print(1); //Definimos el estado
    valores();
    Serial.print(0); //Definimos el valor de C1, siempre es 0 en este estado
    Serial.print(",\n");
    check++;
  }

  if (P3.Read() && !P1.Read() && !P2.Read() && T1.Read()>=temperatura && !check) { //Estado 2
    V1.Set("CERRAR");
    V2.Set("CERRAR");
    V3.Set("ABRIR");
    V4.Set("CERRAR");
    BI.Set("ABRIR");
    B2.Set("CERRAR");
    B3.Set("CERRAR");
    R1.Set("CERRAR");
    Serial.print(2); //Definimos el estado
    valores();
    Serial.print(C1.Read()); //Definimos el valor de C1
    Serial.print(",\n");
    check++;
  }

  if (P3.Read() && !P1.Read() && !P2.Read() && T1.Read()<temperatura && !check) { //Estado 3
    V1.Set("CERRAR");
    V2.Set("CERRAR");
    V3.Set("CERRAR");
    V4.Set("ABRIR");
    BI.Set("ABRIR");
    B2.Set("CERRAR");
    B3.Set("CERRAR");
    R1.Set("ABRIR");
    Serial.print(3); //Definimos el estado
    valores();
    Serial.print(C1.Read()); //Definimos el valor de C1
    Serial.print(",\n");
    check++;
  }

  if (P1.Read() && !P2.Read() && !P3.Read() && N1.ReadPorcentaje()<nivel && !check) { //Estado 4
    V1.Set("ABRIR");
    V2.Set("CERRAR");
    V3.Set("CERRAR");
    V4.Set("CERRAR");
    BI.Set("CERRAR");
    B2.Set("ABRIR");
    B3.Set("CERRAR");
    R1.Set("CERRAR");
    Serial.print(4); //Definimos el estado
    valores();
    Serial.print(0); //Definimos el valor de C1, siempre es 0 en este estado
    Serial.print(",\n");
    check++;
    delay(3000);
  }

  if (P1.Read() && !P2.Read() && !P3.Read() && N1.ReadPorcentaje()>=nivel && !check) { //Estado 5
    V1.Set("CERRAR");
    V2.Set("CERRAR");
    V3.Set("CERRAR");
    V4.Set("CERRAR");
    BI.Set("CERRAR");
    B2.Set("CERRAR");
    B3.Set("ABRIR");
    R1.Set("CERRAR");
    Serial.print(5); //Definimos el estado
    valores();
    Serial.print(0); //Definimos el valor de C1, siempre es 0 en este estado
    Serial.print(",\n");
    check++;
    delay(3000);
  }

  if (!check) { //Estado 0
    V1.Set("CERRAR");
    V2.Set("CERRAR");
    V3.Set("CERRAR");
    V4.Set("CERRAR");
    BI.Set("CERRAR");
    B2.Set("CERRAR");
    B3.Set("CERRAR");
    R1.Set("CERRAR");
    Serial.print(0); //Definimos el estado
    valores();
    Serial.print(0); //Definimos el valor de C1, siempre es 0 en este estado
    Serial.print(",\n");
    check++;
  }
}

void valores(){
  Serial.print(",");
  Serial.print(N1.ReadPorcentaje()); //Definimos el valor de N1
  Serial.print(",");
  Serial.print(N2.ReadPorcentaje()); //Definimos el valor de N2
  Serial.print(",");
  Serial.print(N3.ReadPorcentaje()); //Definimos el valor de N3
  Serial.print(",");
  Serial.print(int(T1.Read())); //Definimos el valor de T1
  Serial.print(",");
}

