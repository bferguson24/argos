#include "pca9685.h"
#include "motor.h"




void motorSetAngle(motor_t *motor, uint16_t angleDeg) {
    // Clip the angle between 0 and 180
    if (angleDeg < 0) {
        angleDeg = 0;
    } else if (angleDeg > 180) {
        angleDeg = 180;
    }
    //Off Time Calculation
    uint16_t offTime = (((2.0 / 180.0 * angleDeg) + 0.5) * (4096.0 / 20));
    setPWM(motor->motorPin, 0, offTime);
}


