
#ifndef __RETARGET_H__
#define __RETARGET_H__

#include "stm32f4xx_hal.h"
#include <stdio.h>

void RetargetInit(UART_HandleTypeDef *huart);

#endif
