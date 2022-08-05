#include <avr/io.h>

#ifndef F_CPU
  #define F_CPU  16000000UL // 16 MHz
#endif

#include <util/delay.h>

#include <stdint.h>
#include <string.h>

// controller pin mapping
#define B_UP     PINF0
#define B_DOWN   PINF1
#define B_LEFT   PINF4
#define B_RIGHT  PINF5
#define B_1      PINF6
#define B_2      PINF7

void setup_io() {
  // configure controller port as input
  DDRF &= ~((1 << B_UP) | (1 << B_DOWN) | (1 << B_LEFT) | (1 << B_RIGHT) |
      (1 << B_1) | (1 << B_2));
  PORTF = 0x00;  // disable the pull-up resistors
}

void setup_uart() {
  const uint16_t baudrate = 9600;
  const uint16_t baud = (((F_CPU / (baudrate * 16UL))) - 1);

  // set baud rate
  UBRR1H = (uint8_t)(baud >> 8 );
  UBRR1L = (uint8_t)baud;
  // enable transmitter
  UCSR1B = 1 << TXEN1;
  // set frame format with 8 bytes of data and 2 stop-bits
  UCSR1C = (1 << USBS1 ) | (3 << UCSZ10);
}

void send_uart_data(const char *data) {
  for (size_t i = 0; i < strlen(data); i++) {
    // wait untill the last transmission is finished
    while (!(UCSR1A & ( 1 << UDRE1)));
    // put data into the buffer
    UDR1 = data[i];
  }
}

int app_mainloop() {
  while (1) {
    if (bit_is_set(PINF, B_UP)) {
      send_uart_data("u");
    } else if (bit_is_set(PINF, B_DOWN)) {
      send_uart_data("d");
    } else if (bit_is_set(PINF, B_LEFT)) {
      send_uart_data("l");
    } else if (bit_is_set(PINF, B_RIGHT)) {
      send_uart_data("r");
    } else if (bit_is_set(PINF, B_1)) {
      send_uart_data("1");
    } else if (bit_is_set(PINF, B_2)) {
      send_uart_data("2");
    }

    _delay_ms(100);
  }

  return 0;  // never reached
}

int main() {
  setup_io();
  setup_uart();

  return app_mainloop();
}
