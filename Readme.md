# HC-SR04
[![hc-sr04-bb.png](https://i.postimg.cc/cJWJVQxS/hc-sr04-bb.png)](https://postimg.cc/Wd9jZqqW)
Leer distancias usando el sensor ultrasonico [HC-SR04](https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/).

Usando el sensor, se puede medir distancias de 3 a 300 cm. Para lograr esto, enviamos un pulso de 4 microsegundos al sensor desdeel pin de salida (Trigger ```sensor[1]```) y esperamos 4 microsegundos para que el sensor reciba el pulso (Echo ```sensor[0]```) usando la función [```pulseIn()```](https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/).

[![hc-sr04-esquem-tico.png](https://i.postimg.cc/7LNLDfhT/hc-sr04-esquem-tico.png)](https://postimg.cc/mct4yZQb)

