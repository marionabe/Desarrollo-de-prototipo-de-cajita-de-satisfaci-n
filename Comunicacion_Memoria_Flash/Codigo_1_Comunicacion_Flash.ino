//Codigo guia 1 para establecer comunicacion(lectura y escritura) entre Arduino y memoria flash
//Se debe instalar la libreria 'SPIFlash' con repositorio: https://github.com/LowPowerLab/SPIFlash

//Este codigo no ha sido probado todavia y debe ser modificado para la comunicacion con el Fio V3
//Justhin Hernandez y Melissa Rodriguez

#include <SPI.h>
#include <SPIFlash.h>

#define FLASH_SS 10 // Pin de selección de esclavo (Slave Select)
#define MEM_SIZE 32768 // Tamaño de la memoria en bytes (por ejemplo, 32KB)

SPIFlash flash(FLASH_SS, 0xEF30); // Inicialización de la memoria flash (0xEF30 es el ID del chip)

void setup() {
  Serial.begin(9600);
  
  // Inicialización de la comunicación SPI
  SPI.begin();
  
  // Inicialización de la memoria flash
  flash.begin();
}

void loop() {
  // Escribir datos en la memoria flash
  const char data[] = "Hola, mundo!";
  flash.writeBytes(0, (uint8_t*)data, strlen(data));
  delay(1000); // Esperar un segundo
  
  // Leer datos desde la memoria flash
  char readData[strlen(data) + 1];
  flash.readBytes(0, (uint8_t*)readData, strlen(data));
  readData[strlen(data)] = '\0'; // Añadir el carácter nulo al final
  
  // Imprimir los datos leídos
  Serial.println(readData);
  
  delay(5000); // Esperar 5 segundos antes de repetir el proceso
}
