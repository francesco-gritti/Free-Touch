/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF18456
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set ADDR_0 aliases
#define ADDR_0_TRIS                 TRISAbits.TRISA1
#define ADDR_0_LAT                  LATAbits.LATA1
#define ADDR_0_PORT                 PORTAbits.RA1
#define ADDR_0_WPU                  WPUAbits.WPUA1
#define ADDR_0_OD                   ODCONAbits.ODCA1
#define ADDR_0_ANS                  ANSELAbits.ANSA1
#define ADDR_0_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ADDR_0_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ADDR_0_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ADDR_0_GetValue()           PORTAbits.RA1
#define ADDR_0_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ADDR_0_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ADDR_0_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define ADDR_0_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define ADDR_0_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define ADDR_0_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define ADDR_0_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define ADDR_0_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set ADDR_1 aliases
#define ADDR_1_TRIS                 TRISAbits.TRISA2
#define ADDR_1_LAT                  LATAbits.LATA2
#define ADDR_1_PORT                 PORTAbits.RA2
#define ADDR_1_WPU                  WPUAbits.WPUA2
#define ADDR_1_OD                   ODCONAbits.ODCA2
#define ADDR_1_ANS                  ANSELAbits.ANSA2
#define ADDR_1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define ADDR_1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define ADDR_1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define ADDR_1_GetValue()           PORTAbits.RA2
#define ADDR_1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define ADDR_1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define ADDR_1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define ADDR_1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define ADDR_1_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define ADDR_1_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define ADDR_1_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define ADDR_1_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set ADDR_2 aliases
#define ADDR_2_TRIS                 TRISAbits.TRISA3
#define ADDR_2_LAT                  LATAbits.LATA3
#define ADDR_2_PORT                 PORTAbits.RA3
#define ADDR_2_WPU                  WPUAbits.WPUA3
#define ADDR_2_OD                   ODCONAbits.ODCA3
#define ADDR_2_ANS                  ANSELAbits.ANSA3
#define ADDR_2_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define ADDR_2_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define ADDR_2_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define ADDR_2_GetValue()           PORTAbits.RA3
#define ADDR_2_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define ADDR_2_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define ADDR_2_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define ADDR_2_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define ADDR_2_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define ADDR_2_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define ADDR_2_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define ADDR_2_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set ADDR_3 aliases
#define ADDR_3_TRIS                 TRISAbits.TRISA4
#define ADDR_3_LAT                  LATAbits.LATA4
#define ADDR_3_PORT                 PORTAbits.RA4
#define ADDR_3_WPU                  WPUAbits.WPUA4
#define ADDR_3_OD                   ODCONAbits.ODCA4
#define ADDR_3_ANS                  ANSELAbits.ANSA4
#define ADDR_3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ADDR_3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ADDR_3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ADDR_3_GetValue()           PORTAbits.RA4
#define ADDR_3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ADDR_3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ADDR_3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ADDR_3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ADDR_3_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define ADDR_3_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define ADDR_3_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ADDR_3_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set MOTOR1A aliases
#define MOTOR1A_TRIS                 TRISAbits.TRISA6
#define MOTOR1A_LAT                  LATAbits.LATA6
#define MOTOR1A_PORT                 PORTAbits.RA6
#define MOTOR1A_WPU                  WPUAbits.WPUA6
#define MOTOR1A_OD                   ODCONAbits.ODCA6
#define MOTOR1A_ANS                  ANSELAbits.ANSA6
#define MOTOR1A_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define MOTOR1A_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define MOTOR1A_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define MOTOR1A_GetValue()           PORTAbits.RA6
#define MOTOR1A_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define MOTOR1A_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define MOTOR1A_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define MOTOR1A_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define MOTOR1A_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define MOTOR1A_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define MOTOR1A_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define MOTOR1A_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set MOTOR1B aliases
#define MOTOR1B_TRIS                 TRISAbits.TRISA7
#define MOTOR1B_LAT                  LATAbits.LATA7
#define MOTOR1B_PORT                 PORTAbits.RA7
#define MOTOR1B_WPU                  WPUAbits.WPUA7
#define MOTOR1B_OD                   ODCONAbits.ODCA7
#define MOTOR1B_ANS                  ANSELAbits.ANSA7
#define MOTOR1B_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define MOTOR1B_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define MOTOR1B_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define MOTOR1B_GetValue()           PORTAbits.RA7
#define MOTOR1B_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define MOTOR1B_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define MOTOR1B_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define MOTOR1B_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define MOTOR1B_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define MOTOR1B_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define MOTOR1B_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define MOTOR1B_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set channel_ANB0 aliases
#define channel_ANB0_TRIS                 TRISBbits.TRISB0
#define channel_ANB0_LAT                  LATBbits.LATB0
#define channel_ANB0_PORT                 PORTBbits.RB0
#define channel_ANB0_WPU                  WPUBbits.WPUB0
#define channel_ANB0_OD                   ODCONBbits.ODCB0
#define channel_ANB0_ANS                  ANSELBbits.ANSB0
#define channel_ANB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define channel_ANB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define channel_ANB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define channel_ANB0_GetValue()           PORTBbits.RB0
#define channel_ANB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define channel_ANB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define channel_ANB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define channel_ANB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define channel_ANB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define channel_ANB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define channel_ANB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define channel_ANB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set BT_RST aliases
#define BT_RST_TRIS                 TRISBbits.TRISB1
#define BT_RST_LAT                  LATBbits.LATB1
#define BT_RST_PORT                 PORTBbits.RB1
#define BT_RST_WPU                  WPUBbits.WPUB1
#define BT_RST_OD                   ODCONBbits.ODCB1
#define BT_RST_ANS                  ANSELBbits.ANSB1
#define BT_RST_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BT_RST_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BT_RST_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BT_RST_GetValue()           PORTBbits.RB1
#define BT_RST_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BT_RST_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BT_RST_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BT_RST_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BT_RST_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define BT_RST_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define BT_RST_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BT_RST_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BTN_X aliases
#define BTN_X_TRIS                 TRISBbits.TRISB2
#define BTN_X_LAT                  LATBbits.LATB2
#define BTN_X_PORT                 PORTBbits.RB2
#define BTN_X_WPU                  WPUBbits.WPUB2
#define BTN_X_OD                   ODCONBbits.ODCB2
#define BTN_X_ANS                  ANSELBbits.ANSB2
#define BTN_X_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BTN_X_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BTN_X_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BTN_X_GetValue()           PORTBbits.RB2
#define BTN_X_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BTN_X_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BTN_X_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BTN_X_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BTN_X_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define BTN_X_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define BTN_X_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BTN_X_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set BTN_Y aliases
#define BTN_Y_TRIS                 TRISBbits.TRISB3
#define BTN_Y_LAT                  LATBbits.LATB3
#define BTN_Y_PORT                 PORTBbits.RB3
#define BTN_Y_WPU                  WPUBbits.WPUB3
#define BTN_Y_OD                   ODCONBbits.ODCB3
#define BTN_Y_ANS                  ANSELBbits.ANSB3
#define BTN_Y_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define BTN_Y_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define BTN_Y_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define BTN_Y_GetValue()           PORTBbits.RB3
#define BTN_Y_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define BTN_Y_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define BTN_Y_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define BTN_Y_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define BTN_Y_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define BTN_Y_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define BTN_Y_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define BTN_Y_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set MOTOR2A aliases
#define MOTOR2A_TRIS                 TRISCbits.TRISC0
#define MOTOR2A_LAT                  LATCbits.LATC0
#define MOTOR2A_PORT                 PORTCbits.RC0
#define MOTOR2A_WPU                  WPUCbits.WPUC0
#define MOTOR2A_OD                   ODCONCbits.ODCC0
#define MOTOR2A_ANS                  ANSELCbits.ANSC0
#define MOTOR2A_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define MOTOR2A_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define MOTOR2A_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define MOTOR2A_GetValue()           PORTCbits.RC0
#define MOTOR2A_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define MOTOR2A_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define MOTOR2A_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define MOTOR2A_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define MOTOR2A_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define MOTOR2A_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define MOTOR2A_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define MOTOR2A_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set MOTOR2B aliases
#define MOTOR2B_TRIS                 TRISCbits.TRISC1
#define MOTOR2B_LAT                  LATCbits.LATC1
#define MOTOR2B_PORT                 PORTCbits.RC1
#define MOTOR2B_WPU                  WPUCbits.WPUC1
#define MOTOR2B_OD                   ODCONCbits.ODCC1
#define MOTOR2B_ANS                  ANSELCbits.ANSC1
#define MOTOR2B_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define MOTOR2B_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define MOTOR2B_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define MOTOR2B_GetValue()           PORTCbits.RC1
#define MOTOR2B_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define MOTOR2B_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define MOTOR2B_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define MOTOR2B_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define MOTOR2B_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define MOTOR2B_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define MOTOR2B_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define MOTOR2B_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set ENC2B aliases
#define ENC2B_TRIS                 TRISCbits.TRISC4
#define ENC2B_LAT                  LATCbits.LATC4
#define ENC2B_PORT                 PORTCbits.RC4
#define ENC2B_WPU                  WPUCbits.WPUC4
#define ENC2B_OD                   ODCONCbits.ODCC4
#define ENC2B_ANS                  ANSELCbits.ANSC4
#define ENC2B_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define ENC2B_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define ENC2B_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define ENC2B_GetValue()           PORTCbits.RC4
#define ENC2B_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define ENC2B_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define ENC2B_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define ENC2B_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define ENC2B_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define ENC2B_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define ENC2B_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define ENC2B_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set ENC2A aliases
#define ENC2A_TRIS                 TRISCbits.TRISC5
#define ENC2A_LAT                  LATCbits.LATC5
#define ENC2A_PORT                 PORTCbits.RC5
#define ENC2A_WPU                  WPUCbits.WPUC5
#define ENC2A_OD                   ODCONCbits.ODCC5
#define ENC2A_ANS                  ANSELCbits.ANSC5
#define ENC2A_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define ENC2A_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define ENC2A_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define ENC2A_GetValue()           PORTCbits.RC5
#define ENC2A_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define ENC2A_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define ENC2A_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define ENC2A_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define ENC2A_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define ENC2A_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define ENC2A_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define ENC2A_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set ENC1B aliases
#define ENC1B_TRIS                 TRISCbits.TRISC6
#define ENC1B_LAT                  LATCbits.LATC6
#define ENC1B_PORT                 PORTCbits.RC6
#define ENC1B_WPU                  WPUCbits.WPUC6
#define ENC1B_OD                   ODCONCbits.ODCC6
#define ENC1B_ANS                  ANSELCbits.ANSC6
#define ENC1B_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define ENC1B_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define ENC1B_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define ENC1B_GetValue()           PORTCbits.RC6
#define ENC1B_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define ENC1B_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define ENC1B_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define ENC1B_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define ENC1B_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define ENC1B_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define ENC1B_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define ENC1B_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set ENC1A aliases
#define ENC1A_TRIS                 TRISCbits.TRISC7
#define ENC1A_LAT                  LATCbits.LATC7
#define ENC1A_PORT                 PORTCbits.RC7
#define ENC1A_WPU                  WPUCbits.WPUC7
#define ENC1A_OD                   ODCONCbits.ODCC7
#define ENC1A_ANS                  ANSELCbits.ANSC7
#define ENC1A_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define ENC1A_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define ENC1A_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define ENC1A_GetValue()           PORTCbits.RC7
#define ENC1A_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define ENC1A_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define ENC1A_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define ENC1A_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define ENC1A_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define ENC1A_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define ENC1A_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define ENC1A_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF4 pin functionality
 * @Example
    IOCCF4_ISR();
 */
void IOCCF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_InterruptHandler);

*/
extern void (*IOCCF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_DefaultInterruptHandler);

*/
void IOCCF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF5 pin functionality
 * @Example
    IOCCF5_ISR();
 */
void IOCCF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_InterruptHandler);

*/
extern void (*IOCCF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);

*/
void IOCCF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF6 pin functionality
 * @Example
    IOCCF6_ISR();
 */
void IOCCF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF6_SetInterruptHandler() method.
    This handler is called every time the IOCCF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(IOCCF6_InterruptHandler);

*/
extern void (*IOCCF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF6_SetInterruptHandler() method.
    This handler is called every time the IOCCF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF6_SetInterruptHandler(IOCCF6_DefaultInterruptHandler);

*/
void IOCCF6_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF7 pin functionality
 * @Example
    IOCCF7_ISR();
 */
void IOCCF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_InterruptHandler);

*/
extern void (*IOCCF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF7_SetInterruptHandler() method.
    This handler is called every time the IOCCF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF7_SetInterruptHandler(IOCCF7_DefaultInterruptHandler);

*/
void IOCCF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/