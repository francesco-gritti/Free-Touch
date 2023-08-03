


#include "mcc_generated_files/mcc.h"
#include "servo.h"








inline void servoPress (void) {
    
    TMR4_LoadPeriodRegister (PRESSED_SERVO_ANGLE_VAL);
}

inline void servoRelease (void) {
    
    TMR4_LoadPeriodRegister (IDLE_SERVO_ANGLE_VAL);
}

