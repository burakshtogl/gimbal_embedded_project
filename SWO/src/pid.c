#include "pid.h"

void PID_Init(PID_t* pid, float kp, float ki, float kd)
{
    pid->Kp = kp;
    pid->Ki = ki;
    pid->Kd = kd;
    pid->setpoint = 0.0f;
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
}

float PID_Compute(PID_t* pid, float input, float dt)
{
    float error = pid->setpoint - input;
    pid->integral += error * dt;
    float derivative = (error - pid->prev_error) / dt;
    pid->prev_error = error;

    return pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;
}
