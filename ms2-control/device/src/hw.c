#include "hw.h"

#include "uart.h"

void hw_setup() {
  // configure control port
  DDRD = 0x00;
  PORTD = 0x00;

  setup_uart(9600);
}

uint8_t get_controller_status() {
  return (uint8_t)PORTD;
}
