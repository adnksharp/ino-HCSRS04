# HC-SR04
[![hc-sr04-bb.png](https://i.postimg.cc/cJWJVQxS/hc-sr04-bb.png)](https://postimg.cc/Wd9jZqqW)

Leer distancias usando el sensor ultrasonico [HC-SR04](https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/).

## Hardware y software necesarios
- Placa de desarrollo Arduino 
- Sensor ultrasonico HC-SR04
- [Arduino IDE](https://www.arduino.cc/en/software) o [Arduino CLI](https://arduino.github.io/arduino-cli/0.23/installation/)

## Funcionamiento
### Variables
- ```Sensor```: Vector que contiene los pines a los que se conecta el sensor.
    - ```Sensor[0]```: Pin de salida (Trigger al pin 5 del microcontrolador).
    - ```Sensor[1]```: Pin de entrada (Echo al pin 6 del microcontrolador).
- ```Out```: Estado de ```Sensor[0]```.
- ```mdelay```: Vector que contiene el tiempo en microsegundos que el programa permanecera pausado mientras ```Sensor[0]``` esté en alto o bajo.
- ```c``` e ```i```: Variables usadas para bucles for.
- ```Time```: Tiempo que el pin ```Sensor[1]``` tarda en recibir el pulso de ```Sensor[0]```.
- ```Dist```: Distancia actual leida.
- ```Cache```: Distancia anterior.
- ```Trash```: Vector usado para leer el promedio de varios tiempos leidos.

### Funcionamiento

 Dentro de un bucle se leen 13 veces el tiempo que tarda **Echo** en leer el pulso de **Trigger**:

 - Dentro de un bucle se pone el Pin **Sensor[0]** en ```Out``` (0 o 1) ```mdelay``` microsegundos.
 - Usando [```pulseIn()```](https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/) se lee el tiempo que tarda el pin **Sensor[1]** en recibir la señal de **Sensor[0]** en la variable ```Time```.
 - Usando

    ![](https://www.luisllamas.es/wp-content/ql-cache/quicklatex.com-83780eae753d9e35a70b0ebb4f6803fa_l3.png)

    se calcula la distancia en cm para cambiar la variable ```Time``` a distancia en cm.
    
Si la distancia cambia respecto a la lectura anterior, se imprime la distancia en pantalla.

[![hc-sr04-esquem-tico.png](https://i.postimg.cc/7LNLDfhT/hc-sr04-esquem-tico.png)](https://postimg.cc/mct4yZQb)

###### Fuente: [Luis Llamas](https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/)
