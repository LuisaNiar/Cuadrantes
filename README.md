# Sistema de Detección y Control de LEDs Basado en Visión por Computadora, Arduino y PIC16F877A

Este proyecto integra tres componentes: visión por computadora para la detección de gestos, comunicación serial con Arduino, y control de LEDs con un microcontrolador PIC16F877A mediante I2C.

## Descripción del Funcionamiento

El sistema funciona en tres etapas principales:

1. **Visión por Computadora**: Un script en Python utiliza OpenCV y Mediapipe para detectar la posición del dedo índice y determinar en qué cuadrante de la pantalla se encuentra. Dependiendo del cuadrante detectado, el script envía un comando específico al Arduino a través de comunicación serial.

2. **Arduino**: El Arduino recibe el comando desde el script de Python y actúa como intermediario, enviando el comando al microcontrolador PIC16F877A mediante el protocolo I2C.

3. **PIC16F877A**: El microcontrolador interpreta el comando recibido y activa el LED correspondiente al cuadrante detectado. Esto proporciona una respuesta visual en tiempo real en función de la posición del dedo.

## Estructura del Repositorio

- **detección_de_gestos**: Código en Python para identificar la posición del dedo índice en la pantalla y enviar comandos al Arduino.
- **arduino**: Código que interpreta los comandos recibidos del script de Python y los retransmite al PIC16F877A a través de I2C.
- **pic16f877a**: Código en lenguaje C para el PIC que controla los LEDs basándose en los comandos I2C recibidos desde el Arduino.

## Requisitos

- **Python** con las librerías **OpenCV** y **Mediapipe** para la detección de gestos.
- **Arduino IDE** para programar la comunicación serial e I2C en el Arduino.
- **Compilador CCS** para programar el PIC16F877A.

## Instalación y Configuración

1. **Configuración del Script de Detección de Gestos**:
   - Asegúrate de tener Python instalado.
   - Instala las librerías necesarias:
     ```bash
     pip install opencv-python mediapipe pyserial
     ```
   - Ejecuta el script en Python para iniciar la detección de gestos.

2. **Configuración del Arduino**:
   - Sube el código del Arduino desde el IDE de Arduino.
   - Conecta el Arduino al PIC16F877A siguiendo las conexiones I2C necesarias.

3. **Configuración del PIC16F877A**:
   - Compila y sube el código al PIC16F877A utilizando el compilador CCS.
   - Conecta los LEDs a los pines del PIC especificados en el código.

## Uso

1. Ejecuta el script en Python para comenzar la detección del dedo índice en la pantalla.
2. Mueve el dedo para cambiar de cuadrante y ver cómo se encienden los LEDs correspondientes.
3. El Arduino recibirá los comandos y los retransmitirá al PIC para controlar los LEDs en función del cuadrante detectado.

## Contribuciones

Si tienes sugerencias o mejoras para este proyecto, ¡no dudes en hacer un fork y enviar un pull request!

