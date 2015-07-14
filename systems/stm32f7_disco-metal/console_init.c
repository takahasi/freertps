#include "console.h"
#include "pin.h"

// pin connections for stm32f7-discovery board
// PC6 = UART6 TX on AF8
// PC7 = UART6 RX on AF8

#define PORTC_TX_PIN 6
#define PORTC_RX_PIN 7

USART_TypeDef *g_console_usart = USART6;

void console_init()
{
  RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
  pin_set_alternate_function(GPIOC, PORTC_RX_PIN, 8);
  pin_set_alternate_function(GPIOC, PORTC_TX_PIN, 8);
  g_console_usart->CR1 &= ~USART_CR1_UE;
  g_console_usart->CR1 |=  USART_CR1_TE | USART_CR1_RE;
  // we want 1 megabit. do this with mantissa=5 and fraction (sixteenths)=4
  g_console_usart->BRR  = (((uint16_t)5) << 4) | 4;
  g_console_usart->CR1 |=  USART_CR1_UE;
}
