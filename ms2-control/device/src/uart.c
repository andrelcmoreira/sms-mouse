#include "hw.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

void setup_uart() {
  const uint16_t baudrate = 9600;
  // set baud rate
  unsigned int baud = (((F_CPU / (baudrate * 16UL))) - 1);

  UBRR1H = (unsigned char)(baud >> 8 );
  UBRR1L = (unsigned char)baud;

  // enable received and transmitter
  UCSR1B = (1 << RXEN1) | (1 << TXEN1);

  // set frame format (8data, 2stop)
  UCSR1C = (1 << USBS1 ) | (3 << UCSZ10);
}

void send_uart_data(const char *data) {
  size_t i = 0;

  for (; i < strlen(data); i++) {
    // wait for empty transmit buffer
    while (!(UCSR1A & ( 1 << UDRE1)));

    // put data into buffer, sends data
    UDR1 = data[i];
  }
}