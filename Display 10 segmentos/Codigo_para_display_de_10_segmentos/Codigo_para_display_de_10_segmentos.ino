
//Escribir los pines a los que se asigna cada display de 10 segmentos:
int display1=2;
int display2=3;
int display3=4;
int display4=5;


void setup(){
  pinMode(display1, OUTPUT); 
  pinMode(display2, OUTPUT); 
  pinMode(display4, OUTPUT); 
  pinMode(display4, OUTPUT); 
}


void loop(){

  //Ejemplos para encender displays de 10 segmentos
  on_display(1);
  on_display(2);
  on_display(3);
  on_display(4);
}


//Función para encender cada display de 10 segmentos
//Parametros de entrada: un numero de 1 a 4, indicando el numero de display
void on_display(int num_display){
  if (num_display==1){
    digitalWrite(display1, HIGH);
  }  
  else if (num_display==2){
    digitalWrite(display2, HIGH);
  } 
  else if (num_display==3){
    digitalWrite(display3, HIGH);
  } 
  else if (num_display==4){
    digitalWrite(display4, HIGH);
  } 
}


//Función para apagar cada display de 10 segmentos
//Parametros de entrada: un numero de 1 a 4, indicando el numero de display
void off_display(int num_display){
  if (num_display=1){
    digitalWrite(display1, LOW);
  } 
  else if (num_display=2){
    digitalWrite(display2, LOW);
  } 
  else if (num_display=3){
    digitalWrite(display3, LOW);
  } 
  else if (num_display=4){
    digitalWrite(display4, LOW);
  } 
}
  
