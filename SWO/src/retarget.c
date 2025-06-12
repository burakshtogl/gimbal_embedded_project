
#include "retarget.h"
#include "stm32f4xx_hal.h"

static UART_HandleTypeDef *gHuart;

void RetargetInit(UART_HandleTypeDef *huart)
{
    gHuart = huart;
    setvbuf(stdout, NULL, _IONBF, 0); // Disable buffering
}

int __io_putchar(int ch)
{
    HAL_UART_Transmit(gHuart, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}
