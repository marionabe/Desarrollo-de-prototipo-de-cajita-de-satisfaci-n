/*******************************************************************************************
 * This example tests illuminating individual segments of the display. Pass in the segment
 * and digit you wish to illuminate to illuminateSegement().
 * 
 * Priyanka Makin @ SparkFun Electronics
 * Original Creation Date: January 31, 2020
 * 
 * SparkFun labored with love to create this code. Feel like supporting open source hardware?
 * Buy a board from SparkFun! https://www.sparkfun.com/products/16391
 * 
 * This code is Lemonadeware; if you see me (or any other SparkFun employee) at the 
 * local, and you've found our code helpful, please buy us a round!
 * 
 * Hardware Connections:
 * Attach Red Board to computer using micro-B USB cable.
 * Attach Qwiic Alphanumeric board to Red Board using Qwiic cable.
 * 
 * Distributed as-is; no warranty is given.
 *****************************************************************************************/
/* Librería utilizada para la comunicación por I2C */
#include <Wire.h>

/* Se incluye la librería. Esta puede ser encontrada en la misma carpeta de
 * este Repo con el nombre de Libreria_Original */
#include <SparkFun_Alphanumeric_Display.h>

/* Se crea un objeto (display) a partir de la clase HT16K33. La cual se define
 * en SparkFun_Alphanumeric_Display.h*/
HT16K33 display;

/* Creación de la función setup(), esta sirve para iniciar las comunicaciones
 * por I2C llamando la clase Seria y el método begin. Luego hace comprobaciones
 * de la conexión */
void setup()
{
  Serial.begin(115200);
  Serial.println("SparkFun Qwiic Alphanumeric - Example 2:",
                 "Turn On One Segment");
  Wire.begin(); //Join I2C bus

  // Check if display will acknowledge
  if (display.begin() == false)
  {
    Serial.println("Device did not acknowledge! Freezing.");
    while(1);
  }
  Serial.println("Display acknowledged.");

  // Utiliza el método "illuminateSegment"
  display.illuminateSegment('A', 0);
  display.illuminateSegment('L', 1);
  display.illuminateSegment('I', 2);
  display.illuminateSegment('G', 3);
  display.updateDisplay();
}

void loop()
{
}
