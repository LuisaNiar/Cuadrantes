#include <Wire.h>

void setup() {
  Serial.begin(19200);    // Inicializa la comunicación serial
  Wire.begin();           // Inicia como maestro I2C
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Lee el comando hasta el salto de línea

    // Envía el comando correspondiente al PIC según el texto recibido
    if (command.equalsIgnoreCase("Right Up")) {
      sendCommand('A');  // Envía 'A' para Right Up
    } else if (command.equalsIgnoreCase("Left Up")) {
      sendCommand('B');  // Envía 'B' para Left Up
    } else if (command.equalsIgnoreCase("Right Down")) {
      sendCommand('C');  // Envía 'C' para Right Down
    } else if (command.equalsIgnoreCase("Left Down")) {
      sendCommand('D');  // Envía 'D' para Left Down
    } else if (command.equalsIgnoreCase("Off")) {
      sendCommand('O');  // Envía 'O' para Off
    }
  }
}

// Función para enviar un comando al PIC a través de I2C
void sendCommand(char command) {
  Wire.beginTransmission(0x11);  // Dirección I2C del PIC (0x11)
  Wire.write(command);           // Escribe el comando en I2C
  Wire.endTransmission();        // Finaliza la transmisión
}
