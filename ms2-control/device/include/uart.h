#ifndef UART_H_
#define UART_H_

/**
 * @brief
 */
void setup_uart();

/**
 * @brief send a message to uart interface.
 *
 * @param data The message to be sent.
 */
void send_uart_data(const char *data);

#endif  // UART_H_
