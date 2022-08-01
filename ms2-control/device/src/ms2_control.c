#include "ms2_control.h"

#include "hw.h"
#include "uart.h"

#include <util/delay.h>

// controller mapping
#define BUTTON_UP     0x11 // 0b00010001
#define BUTTON_DOWN   0x12 // 0b00010010
#define BUTTON_LEFT   0x14 // 0b00010100
#define BUTTON_RIGHT  0x18 // 0b00011000
#define BUTTON_1      0x90 // 0b10010000
#define BUTTON_2      0x30 // 0b00110000

void run_app() {
  while (1) {
    uint8_t status = get_controller_status();

    switch (status) {
    case BUTTON_UP:
      send_uart_data("up");
      break;
    case BUTTON_DOWN:
      send_uart_data("down");
      break;
    case BUTTON_LEFT:
      send_uart_data("left");
      break;
    case BUTTON_RIGHT:
      send_uart_data("right");
      break;
    case BUTTON_1:
      send_uart_data("1");
      break;
    case BUTTON_2:
      send_uart_data("2");
      break;
    default:
      break;
    }

    _delay_ms(100);
  }
}
