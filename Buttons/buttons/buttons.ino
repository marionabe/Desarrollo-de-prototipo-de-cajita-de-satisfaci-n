// BOTONES PARA CAJITA DE SATISFACCIÓN
// TCU TC-691 Tropicalización de la Tecnología 
// Creador: Andrés Chaves Vargas - B92198

#include "GFButton.h"
 

GFButton btn_bad = GFButton(19);
GFButton btn_meh = GFButton(18);
GFButton btn_good = GFButton(17);
GFButton btn_vgood = GFButton(16);
 
void setup() {
  Serial.begin(9600);
  Serial.println("Se inicializo el programa:");
  
  Serial.print("Very Good");
  Serial.print(", ");
  Serial.print("Good");
  Serial.print(", ");
  Serial.print("Meh");
  Serial.print(", ");
  Serial.println("Bad");
  
  
  // Temporizador de rebotes:
  btn_bad.setDebounceTime(100);
  btn_meh.setDebounceTime(100);
  btn_good.setDebounceTime(100);
  btn_vgood.setDebounceTime(100);
  
  // Manejo del botones presionados:
  btn_bad.setPressHandler(button1_on_press);
  btn_meh.setPressHandler(button2_on_press);
  btn_good.setPressHandler(button3_on_press);
  btn_vgood.setPressHandler(button4_on_press);

  //Habilitación de pines como salida para leds:
  pinMode(5, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(2, OUTPUT); 
}
 
void loop() {
  // LLamar al método process SIEMPRE al inicio:
  btn_bad.process();
  btn_meh.process();
  btn_good.process();
  btn_vgood.process();
  
}

//Funciones que permiten imprimir de forma serial los valores de los botones:

void button1_on_press(GFButton & btn_bad)
{
  // Use of the press count field
  digitalWrite(5, HIGH);enciende el led rojo
  Serial.print(btn_vgood.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_good.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_meh.getPressCount()-1);
  Serial.print(", ");
  Serial.println(btn_bad.getPressCount()-1);
  delay(1000);
  digitalWrite(5, LOW);
  
  
}

void button2_on_press(GFButton & btn_meh)
{
  // Use of the press count field
  digitalWrite(4, HIGH);//Enciende el led anaranjado
  Serial.print(btn_vgood.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_good.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_meh.getPressCount()-1);
  Serial.print(", ");
  Serial.println(btn_bad.getPressCount()-1);
  delay(1000);
  digitalWrite(4, LOW);
}

void button3_on_press(GFButton & btn_good)
{
  // Use of the press count field
  digitalWrite(3, HIGH); //Enciende el Led Amarillo
  Serial.print(btn_vgood.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_good.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_meh.getPressCount()-1);
  Serial.print(", ");
  Serial.println(btn_bad.getPressCount()-1);
  delay(1000);
  digitalWrite(3, LOW);
}

void button4_on_press(GFButton & btn_vgood)
{
  // Use of the press count field
  digitalWrite(2, HIGH); //Enciende el Led Verde
  Serial.print(btn_vgood.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_good.getPressCount()-1);
  Serial.print(", ");
  Serial.print(btn_meh.getPressCount()-1);
  Serial.print(", ");
  Serial.println(btn_bad.getPressCount()-1);
  delay(1000);
  digitalWrite(2, LOW);
}
