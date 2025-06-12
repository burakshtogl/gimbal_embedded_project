#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stm32f4xx_hal.h"

typedef struct {
    int16_t Ax, Ay, Az;
    int16_t Gx, Gy, Gz;
} MPU6050_t;

void MPU6050_Init(I2C_HandleTypeDef *hi2c);
void MPU6050_Read_Accel(MPU6050_t *data);
void MPU6050_Read_Gyro(MPU6050_t *data);
void MPU6050_Read_All(I2C_HandleTypeDef *hi2c, MPU6050_t *data);
void MPU6050_Calibrate(MPU6050_t *data);

#endif /* INC_MPU6050_H_ */
