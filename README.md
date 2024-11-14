## Sistema de Detección y Control de LEDs Basado en Visión por Computadora, Arduino y PIC16F877A

Este proyecto integra tres componentes: visión por computadora para detección de gestos, comunicación serial con Arduino, y control de LEDs con un microcontrolador PIC16F877A mediante I2C.

### Descripción del Funcionamiento
1. **Visión por Computadora**: Un script en Python detecta la posición del dedo índice y determina en qué cuadrante de la pantalla se encuentra.
2. **Arduino**: Según el cuadrante detectado, el script envía un comando al Arduino vía comunicación serial. El Arduino actúa como intermediario, reenviando el comando al microcontrolador a través del protocolo I2C.
3. **PIC16F877A**: El microcontrolador recibe el comando y activa el LED correspondiente al cuadrante detectado, proporcionando una respuesta visual en tiempo real.

### Estructura del Repositorio
- **Detección de Gestos**: Código en Python para identificar la posición del dedo y enviar comandos al Arduino.
- **Arduino**: Código que interpreta los comandos recibidos del script de Python y los envía al PIC.
- **PIC16F877A**: Código que controla los LEDs basándose en los comandos I2C recibidos del Arduino.

### Requisitos
- Python con OpenCV y Mediapipe para detección de gestos.
- Arduino y su IDE para la comunicación serial e I2C.
- Compilador CCS para programar el PIC16F877A.

Este proyecto demuestra la interacción entre visión por computadora y microcontroladores para crear una interfaz de control simple basada en gestos.
