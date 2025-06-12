#include "i2c.h"

uint8_t I2C_ReadBytes(I2C_HandleTypeDef *hi2c, uint8_t DevAddress, uint8_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    if (HAL_I2C_Mem_Read(hi2c, DevAddress, MemAddress, I2C_MEMADD_SIZE_8BIT, pData, Size, Timeout) == HAL_OK)
    {
        return 0; // success
    }
    return 1; // failure
}

uint8_t I2C_WriteBytes(I2C_HandleTypeDef *hi2c, uint8_t DevAddress, uint8_t MemAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    if (HAL_I2C_Mem_Write(hi2c, DevAddress, MemAddress, I2C_MEMADD_SIZE_8BIT, pData, Size, Timeout) == HAL_OK)
    {
        return 0; // success
    }
    return 1; // failure
}
