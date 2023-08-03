

#include "motor_handler.h"
#include "mcc_generated_files/mcc.h"


extern int16_t targetX, posX, posX_reached;
extern int16_t targetY, posY, posY_reached;



void homeMotorX (void) {
    
    MOTOR1A_SetLow();
    MOTOR1B_SetHigh();
    while(BTN_X_GetValue() == 1);
    MOTOR1B_SetLow();
}

void setTargetX (int16_t _targetX) {
    
    if(_targetX < 0) _targetX = 0;
    if(_targetX > 88)_targetX = 88;
    targetX = _targetX;
    
    if(posX > _targetX+1){
        MOTOR1A_SetLow();
        MOTOR1B_SetHigh();
        posX_reached = 0;
    }
    else if(posX < _targetX-1) {
        MOTOR1B_SetLow();
        MOTOR1A_SetHigh();
        posX_reached = 0;
    }
    else {
        MOTOR1A_SetLow();
        MOTOR1B_SetLow();
        posX_reached = 1;
    }
}




void homeMotorY (void) {
    
    MOTOR2A_SetLow();
    MOTOR2B_SetHigh();
    while(BTN_Y_GetValue() == 1);
    MOTOR2B_SetLow();
}


void setTargetY (int16_t _targetY) {
    
    if(_targetY < 0) _targetY = 0;
    if(_targetY > 88)_targetY = 88;
    targetY = _targetY;
    
    if(posY > _targetY+1){
        MOTOR2A_SetLow();
        MOTOR2B_SetHigh();
        posY_reached = 0;
    }
    else if(posY < _targetY-1) {
        MOTOR2B_SetLow();
        MOTOR2A_SetHigh();
        posY_reached = 0;
    }
    else {
        MOTOR2A_SetLow();
        MOTOR2B_SetLow();
        posY_reached = 1;
    }
}