// Sanitary Water Recirculation System

import processing.serial.*;

Serial puerto; 
PImage estado_0, estado_1, estado_2, estado_3, estado_4, estado_5;

void setup() {
  size(1018, 720);
  
  println(Serial.list()); //Imprimimos los puertos conectados
  puerto = new Serial(this, Serial.list()[4], 9600);

  estado_0=loadImage("estado_0.jpg");
  estado_1=loadImage("estado_1.jpg");
  estado_2=loadImage("estado_2.jpg");
  estado_3=loadImage("estado_3.jpg");
  estado_4=loadImage("estado_4.jpg");
  estado_5=loadImage("estado_5.jpg");
  
  background(estado_0);
}
void draw() { 
  String entrada = puerto.readStringUntil('\n');

  if (entrada!=null) { 
    int [] valores = int(split(entrada, ",")); //Generamos un array con cada valor en una posición
    
    //Cargamos el fondo
    switch (valores[0]){
      case 0:
        background(estado_0);
        break;
      case 1:
        background(estado_1);
        break;
      case 2:
        background(estado_2);
        break;
      case 3:
        background(estado_3);
        break;
      case 4:
        background(estado_4);
        break;
      case 5:
        background(estado_5);
        break;
    }
      
    //Dibujamos N1  
    fill(31,73,125); //Azul oscuro
    rect(636,629,105,-map(valores[1],0,100,0,148));
    
    textSize(30);
    textAlign(RIGHT);
    fill(0);
    text(valores[1],705,600);
    text("%",730,600);
    
    //Dibujamos N2   
    fill(79,129,189); //Azul claro
    rect(450,629,105,-map(valores[2],0,100,0,148));
    
    textSize(30);
    textAlign(RIGHT);
    fill(0);
    text(valores[2],517,600);
    text("%",542,600);
    
    //Dibujamos N3   
    fill(192,80,77); //Rojo
    rect(263,629,105,-map(valores[3],0,100,0,148));
    
    textSize(30);
    textAlign(RIGHT);
    fill(0);
    text(valores[3],330,600);
    text("%",355,600);
    
    //Dibujamos T1
    textSize(20);
    textAlign(RIGHT);
    fill(0);
    text(valores[4],230,580);
    text("ºC",255,580);
    
    //Dibujamos C1
    if (valores[5]==0) fill(192,80,77); //Rojo
    if (valores[5]==1) fill(155,187,89); //Verde
    rect(500,60,13,13);
  }
}
