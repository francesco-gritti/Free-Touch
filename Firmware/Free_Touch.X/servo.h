/* 
 * File:   Servo.h
 * Author: francesco
 *
 * Created on May 20, 2021, 6:38 AM
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
    
// servo values go from 124 to 249
#define IDLE_SERVO_ANGLE_VAL    180
#define PRESSED_SERVO_ANGLE_VAL 249
    
    
inline void servoPress (void);
inline void servoRelease (void);




#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

