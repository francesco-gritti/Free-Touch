/* 
 * File:   motor_handler.h
 * Author: francesco
 *
 * Created on May 18, 2021, 4:27 PM
 */

#ifndef MOTOR_HANDLER_H
#define	MOTOR_HANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "mcc_generated_files/mcc.h"
    
    
    
    
#define FORWARD 1
#define BACKWARD 0


inline void homeMotorX (void);
inline void setTargetX (int16_t _targetX);


inline void homeMotorY (void);
inline void setTargetY (int16_t targetY);




#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_HANDLER_H */

