#include "mpu6050.h"

#define MPU6050_ADDR 0xD0 // 0x68 << 1
#define SMPLRT_DIV_REG 0x19
#define PWR_MGMT_1_REG 0x6B
#define CONFIG_REG 0x1A
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H 0x3B

I2C_HandleTypeDef *_hi2c;

void MPU6050_Init(I2C_HandleTypeDef *hi2c) {
    _hi2c = hi2c;
    uint8_t check, data;

    HAL_I2C_Mem_Read(_hi2c, MPU6050_ADDR, 0x75, 1, &check, 1, HAL_MAX_DELAY);
    if (check == 0x68) {
        data = 0;
        HAL_I2C_Mem_Write(_hi2c, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &data, 1, HAL_MAX_DELAY);
        data = 0x07;
        HAL_I2C_Mem_Write(_hi2c, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &data, 1, HAL_MAX_DELAY);
        data = 0x00;
        HAL_I2C_Mem_Write(_hi2c, MPU6050_ADDR, CONFIG_REG, 1, &data, 1, HAL_MAX_DELAY);
        data = 0x00;
        HAL_I2C_Mem_Write(_hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, HAL_MAX_DELAY);
        data = 0x00;
        HAL_I2C_Mem_Write(_hi2c, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, HAL_MAX_DELAY);
    }
}

void MPU6050_Read_All(I2C_HandleTypeDef *hi2c, MPU6050_t *data) {
    uint8_t Rec_Data[14];
    HAL_I2C_Mem_Read(hi2c, MPU6050_ADDR, ACCEL_XOUT_H, 1, Rec_Data, 14, HAL_MAX_DELAY);

    data->Ax = (int16_t)(Rec_Data[0] << 8 | Rec_Data[1]);
    data->Ay = (int16_t)(Rec_Data[2] << 8 | Rec_Data[3]);
    data->Az = (int16_t)(Rec_Data[4] << 8 | Rec_Data[5]);
    data->Gx = (int16_t)(Rec_Data[8] << 8 | Rec_Data[9]);
    data->Gy = (int16_t)(Rec_Data[10] << 8 | Rec_Data[11]);
    data->Gz = (int16_t)(Rec_Data[12] << 8 | Rec_Data[13]);
}

void MPU6050_Read_Accel(MPU6050_t *data) {
    // Dummy wrapper if needed
}

void MPU6050_Read_Gyro(MPU6050_t *data) {
    // Dummy wrapper if needed
}

void MPU6050_Calibrate(MPU6050_t *data) {
    // Optional: add calibration logic if desired
}
