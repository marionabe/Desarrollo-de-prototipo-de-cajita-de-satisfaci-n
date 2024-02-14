#include <Wire.h> // librería para la comunicación I2C
#include <RCTlib.h> // librería para usar el modulo real time clock

RTC_DS1307 rtc; // Para el módulo del prototipo

void setup () {
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Modulo RTC no encontrado !");
    while (1);
  }
  rtc.adjust(DateTime(__DATE__, __TIME__)); // Para inicializar el reloj; luego de inicializado, se puede comentar esta línea
}

void loop () {
  DateTime fecha = rtc.now();

  Serial.print(fecha.day());
  Serial.print("/");
  Serial.print(fecha.month());
  Serial.print("/");
  Serial.print(fecha.year());
  Serial.print(" ");

  Serial.print(fecha.hour());
  Serial.print(":");
  Serial.print(fecha.minute());
  Serial.print(":");
  Serial.print(fecha.second());

  delay(1000);
}