/**
 * @brief This file contains all implementations related to hardware peripherals
 * configuration.
 */
#ifndef HW_H_
#define HW_H_

#include <avr/io.h>

#include <stdint.h>

#ifndef F_CPU
  #define F_CPU                 16000000UL /* 16 MHz */
#endif

/**
 * @brief configures all hardware peripherals.
 */
void sys_config();

/**
 * @brief send a message to uart interface.
 *
 * @param data The message to be sent.
 */
void send_uart_data(const char *data);

/**
 * @brief
 *
 * @return
 */
uint8_t get_controller_status();

#endif // HW_H_
