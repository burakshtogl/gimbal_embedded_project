#ifndef PID_H
#define PID_H

typedef struct {
    float Kp;
    float Ki;
    float Kd;

    float setpoint;
    float prev_error;
    float integral;
} PID_t;

void PID_Init(PID_t* pid, float kp, float ki, float kd);
float PID_Compute(PID_t* pid, float input, float dt);

#endif
