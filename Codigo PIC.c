#include <16F877A.h>
#fuses XT, NOWDT, NOPROTECT, NOLVP
#use delay(clock=4000000)
#use i2c(SLAVE, SDA=PIN_C4, SCL=PIN_C3, address=0x22, FORCE_HW)

// Definici�n de pines para los LEDs de direcci�n
#define LED_RIGHT_UP   PIN_B0
#define LED_LEFT_UP    PIN_B1
#define LED_RIGHT_DOWN PIN_B2
#define LED_LEFT_DOWN  PIN_B3

// LED indicador de recepci�n de se�al
#define LED_SIGNAL     PIN_B4

void main() {
   set_tris_b(0x00); // Configura todos los pines del puerto B como salidas

   // Apaga todos los LEDs al inicio
   output_low(LED_RIGHT_UP);
   output_low(LED_LEFT_UP);
   output_low(LED_RIGHT_DOWN);
   output_low(LED_LEFT_DOWN);
   output_low(LED_SIGNAL); // Apaga el LED de se�al

   while (true) {
      // Lee el comando recibido por I2C
      char command = i2c_read();

      // Enciende el LED de se�al para indicar que se ha recibido un comando
      output_high(LED_SIGNAL);

      // Apaga todos los LEDs de direcci�n antes de encender el correspondiente
      output_low(LED_RIGHT_UP);
      output_low(LED_LEFT_UP);
      output_low(LED_RIGHT_DOWN);
      output_low(LED_LEFT_DOWN);

      // Activa el LED correspondiente seg�n el comando recibido
      if (command == 'A') {
         output_high(LED_RIGHT_UP);    // Comando 'A' enciende LED Right Up
      } else if (command == 'B') {
         output_high(LED_LEFT_UP);     // Comando 'B' enciende LED Left Up
      } else if (command == 'C') {
         output_high(LED_RIGHT_DOWN);  // Comando 'C' enciende LED Right Down
      } else if (command == 'D') {
         output_high(LED_LEFT_DOWN);   // Comando 'D' enciende LED Left Down
      } else if (command == 'O') {
         // Comando 'O' apaga todos los LEDs de direcci�n (ya est�n apagados)
      }

      // Agrega un breve retardo para que el LED de se�al se mantenga encendido
      delay_ms(100);
      
      // Apaga el LED de se�al despu�s del retardo
      output_low(LED_SIGNAL);
   }
}

