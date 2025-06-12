#ifndef I2C_H_
#define I2C_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

uint8_t I2C_ReadBytes(I2C_HandleTypeDef *hi2c, uint8_t DevAddress, uint8_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
uint8_t I2C_WriteBytes(I2C_HandleTypeDef *hi2c, uint8_t DevAddress, uint8_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);

#endif /* I2C_H_ */
