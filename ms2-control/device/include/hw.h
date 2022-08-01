/**
 * @brief This file contains all implementations related to hardware I/O config.
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
void hw_setup();

/**
 * @brief
 *
 * @return
 */
uint8_t get_controller_status();

#endif // HW_H_
