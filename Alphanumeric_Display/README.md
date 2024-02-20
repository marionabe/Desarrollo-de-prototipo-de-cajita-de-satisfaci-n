# SparkFun Qwiic Alphanumeric Display - Red
> Enlace a la página oficial del componente: [https://www.sparkfun.com/products/16916](https://www.sparkfun.com/products/16916)

## Detalles generales:

- **Descripción General**: el SparkFun Qwiic Alphanumeric Display es un dispositivo que permite mostrar números gracias a sus 14 leds segmentados, caracteres y símbolos gracias a sus dígitos de catorce segmentos. Se conecta fácilmente mediante el sistema Qwiic sin necesidad de soldadura.

- **Facilidad de Uso**: la biblioteca Arduino de SparkFun facilita la impresión de cadenas de texto en el display, utilizando la función `print()`. Además, se puede controlar el chip controlador de LED VK16K33 para iluminar segmentos y desplazar textos.

- **Configuración de Dirección I2C**: el chip VK16K33 permite configurar la dirección I2C, lo que posibilita la comunicación con hasta cuatro displays en el mismo bus.

- **Características Clave**: el display es de color rojo, opera a 3.3V, tiene un oscilador RC integrado, puede mostrar hasta 128 patrones diferentes, incluye un circuito de escaneo de matriz de teclas 13x3 y un circuito de atenuación de 16 pasos.

- **Tamaño**: [Alphanumeric Display Board Dimensions](Imagenes/Dimensiones.png)


## Uso del código:

### Intancia de la librería y conexión con el Arduino

```cpp
/* Librería utilizada para la comunicación por I2C */
#include <Wire.h>

/* Se incluye la librería. Esta puede ser encontrada en la misma carpeta de
 * este Repo con el nombre de Libreria_Original */
#include <SparkFun_Alphanumeric_Display.h>
```

### Creación del objeto para utilizar los métodos (funciones) del display

```cpp
/* Clase "HT16K33" y objeto "display" */
HT16K33 display;
```

### Comprobación de la conexión del display al arduino
```cpp
/* Creación de la función setup(), esta sirve para iniciar las comunicaciones
 * por I2C llamando la clase Seria y el método begin. Luego hace comprobaciones
 * de la conexión */
void setup()
{ 
    // Comunicación serial con una comunicación de 115200 baudios
    Serial.begin(115200);
    // Inicio de la comunicación I2C
    Wire.begin();

    // Comprueba si la comunicación si se estableció
    if (display.begin() == false)
    {
        Serial.println("El dispositivo no se conectó! Enciclando...");
        while(1);
    }
    Serial.println("El dispositivo se conectó!.");
  

    /* Resto del código */
}
```

### Uso de los métodos de la clase *HT16K33* con el objeto *display*

***print(const char[])***: imprime palabras en el display
```cpp
/* El argumento debe ser una cadena de texto (string) */
display.print("Milk")
```

***print(const char[])***: imprime palabras en el display.
```cpp
/* El argumento debe ser una cadena de texto (string) */
display.print("Milk")
```

***illuminateSegment(segment, digit)***: ilumina unicamente los segmentos de uno de los digitos. Los segmentos a encender podrían ser escogidos manualmente o usando las contantes de la librería.
```cpp
/* Ilumina los segmentos (leds) correspondientes a la 'A' en el primer digito (0) */
display.illuminateSegment('A', 0);
/* Ilumina los segmentos (leds) correspondientes a la 'L' en el segundo digito (1) */
display.illuminateSegment('L', 1);
/* Ilumina los segmentos (leds) correspondientes a la 'I' en el tercer digito (2) */
display.illuminateSegment('I', 2);
/* Ilumina los segmentos (leds) correspondientes a la 'G' en el cuarto digito (3) */
display.illuminateSegment('G', 3);
```

***updateDisplay()***: actualiza la ram del display (vuelve a leer el valor de los wires).
```cpp
display.updateDisplay();
```

***printChar(displayChar, digit)***: imprime una letra para un display dado.
```cpp
/* Imprime la letra 'W' en el primer digito (0) */
display.printChar('W', 0);
/* Imprime la letra 'H' en el segundo digito (1) */
display.printChar('H', 1);
/* Imprime la letra 'A' en el tercer digito (2) */
display.printChar('A', 2);
/* Imprime la letra 'T' en el cuarto digito (3) */
display.printChar('T', 3);
```

***setBrightness(duty)***: cambiando el ciclo de tabla se ajusta el brillo del display, siendo el valor más bajo 0 y el más alto 15. Lo ingresado debe ser un número entero (duty).
```cpp
/* Se coloca el brillo al máximo en el display */
display.setBrightness(15);
```

***setBrightness(duty)***: cambiando el ciclo de tabla se ajusta el brillo del display, siendo el valor más bajo 0 y el más alto 15. Lo ingresado debe ser un número entero (duty).
```cpp
/* Se coloca el brillo al máximo en el display */
display.setBrightness(15);
```

***setBlinkRate(rate)***: se configura la velocidad de parpadeo (blink) en Hz (1/s). Lo ingresado debe ser un flotante (rate).
```cpp
/* Parpadea cada 0.5s */
display.setBlinkRate(2.0);
```

***shiftLeft(), shiftRight()***: desplaza hacia la izquierda o derecha lo que se esta mostrando en el display. Esto se coloca dentro de la función `void loop()`.
```cpp
void loop() 
{
    /* Desplaza a la izquierda cada 0.3s */  
    delay(300);
    display.shiftLeft();
}
```

***defineChar(displayChar, segmentsToTurnOn)***: se le asigna un patron de segmentos a encender a una letra dependiendo de lo que se deseé. Incluso se pueden redifinir los patros ya asignados.
```cpp
void loop() 
{
/* Define 14 segment bits: nmlkjihgfedcba */
display.defineChar('a', 0b01000001011000);                              
display.defineChar('e', 0b10000001011000);
display.defineChar('f', 0b01010101000000);
/* También se pueden utilizar constantes */
display.defineChar('s', SEG_L | SEG_I | SEG_D); // 0b00100100001000  
display.defineChar('z', SEG_N | SEG_G | SEG_D); // 0b10000001001000
}
```

***Otros métodos auxileares***:
```cpp
//Turn decimals on
display.decimalOn();
//Turn decimals off
display.decimalOff();
//Turn decimal on for one display
display.decimalOnSingle(0);
//Turn colons on
display.colonOn();
//Turn colons off
display.colonOff();
//Turn colon on for one display
display.colonOnSingle(1);
```