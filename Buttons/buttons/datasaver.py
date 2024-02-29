#!/usr/bin/python3
# TCU Tropicalización de la Tecnología
# Creado por: Andrés Chaves Vargas
import serial

ser = serial.Serial(
    port = '/tmp/ttyS1',\  
    baudrate = 9600,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,
    timeout=0\
    )

# Se crea un archivo tipo csv o se sobreescribe
f = open('Satisfaccion_Clientes.csv', 'w+')

print("connected to: "+ ser.portstr)
# se leen las lineas provenientes del puerto serial, y se guardan en el .csv:
try:
    while True:
        for c in ser.read():
            c=chr(c)
            print(c, end= "")
            f.write(c)
except KeyboardInterrupt:
    # para que se pare la ejecución y se guarde el archivo .csv utilizar ctrl+c en linux    
    print("\nInterrupción de Programa debido al usuario.")

finally:
    
    ser.close()
    f.close()


