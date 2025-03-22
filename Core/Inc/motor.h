#pragma once
#include <stdint.h>


typedef struct{
const int motorPin;
int motorAngle;
}motor_t;


//Motor Functions

void motorSetAngle(motor_t *motor,uint16_t angle);
