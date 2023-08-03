/* 
 * File:   RN4871.h
 * Author: francesco
 *
 * Created on May 19, 2021, 11:32 AM
 */

#ifndef RN4871_H
#define	RN4871_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#define GET_CONFIG_CMD      0x01
#define SET_CONFIG_CMD      0x02
#define PRESS_BUTTON_CMD    0x03

#define RESPONSE_TO_GET_CONFIG  0x04
#define ACK                 0x05
    
    
    
// export USART flags defined in RN4871.c source file
extern volatile uint8_t err_flag, aok_flag, cmd_flag, reboot_flag;
extern volatile uint8_t connection_status, data_available;
extern volatile uint16_t data_len;
extern volatile uint8_t payload [256];




void USART_Handler (void);   

void enterCommandMode (void);
void exitCommandMode (void);
void reboot (void);
void setAdvertisementManufacturerData (uint8_t * data, uint8_t len);
void setRandomAddress (void);

void sendACK (void);





#ifdef	__cplusplus
}
#endif

#endif	/* RN4871_H */

