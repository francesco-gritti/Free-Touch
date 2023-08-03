

#include "main.h"



//#define DEBUG

// unique ID identifier of the device
const uint8_t manufacturerData[16] = "1234567890abcdef";


// GLOBAL VARIABLES
volatile int16_t posX, posY;
volatile int16_t targetX, targetY;
volatile int16_t posX_reached, posY_reached;

uint8_t matrix_enabled = 1;
int8_t prev_col = -1;
int8_t prev_row = -1;


uint8_t buttonToPress_buffer[5];
uint8_t btopress_idx = 0;
button_t buttonList [MAX_BUTTONS];
int8_t ID_grid [MAX_ROWS][MAX_COLS]; 
int buttonList_len;

bool toPress = false;


void pressButton (int buttonID);

uint8_t prev_connection_status = 0;

void main(void) {
    
    // initialize the device
    SYSTEM_Initialize();
    
    // keep RN4871 in a reset state
    BT_RST_SetHigh();
    
    // stop buzzer from playing
    TRISC |= 0b00001000;
    __delay_ms(2000);
    
    
    EUSART2_SetRxInterruptHandler(USART_Handler);
    IOCCF7_SetInterruptHandler (encoder1A_InterruptHandler);
    IOCCF6_SetInterruptHandler (encoder1B_InterruptHandler);
    IOCCF5_SetInterruptHandler (encoder2A_InterruptHandler);
    IOCCF4_SetInterruptHandler (encoder2B_InterruptHandler);
    
    TMR1_SetInterruptHandler (TMR1_ISRHandler);
    
    
    // load keypad configuration from EEPROM
    
    uint16_t addr = FIRST_EE_ADDR;
    uint8_t len = DATAEE_ReadByte (addr);
    if(len > 250) len = 250;
    addr += 1;
    for (uint8_t i=0;i<len; i+=1, addr += 1)
        payload[i] = DATAEE_ReadByte(addr);
    
    
    buttonList_len = createButtonList (payload, len, buttonList);
    arrangeButtonsInMatrix (buttonList, buttonList_len, ID_grid);

    
    
    // home the structure and set zero position. This
    // has to be done before interrupts are enables
#ifndef DEBUG
    homeMotorX();
    homeMotorY();
    __delay_ms(100);
    posX = 0;
    posY = 0;
    posX_reached = 1;
    posY_reached = 1;
#endif

   
    servoRelease();
    setAddress(0);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();


    
    // ------------------------------------------//
    //            RN4871 COFNIGURATION           //
    // ------------------------------------------//
    
    reboot_flag = 0;
    BT_RST_SetLow();
    while(reboot_flag == 0);
    reboot_flag = 0;
    
    // enter command mode for configuration
    enterCommandMode ();
    while(cmd_flag == 0);
    cmd_flag = 0;
    
    // set  advertisement data
    setAdvertisementManufacturerData (manufacturerData, 16);
    while (aok_flag == 0);
    aok_flag = 0;
    
    setRandomAddress ();
    while(cmd_flag == 0);
    cmd_flag = 0;
    
    exitCommandMode();
    
    playTone(400);
    
    
    while (1)  {
        
        if(connection_status != prev_connection_status){
            
            prev_connection_status = connection_status;
            playTone(400);
        }
        
        
        // handle BT communication
        if (data_available) {
            
            data_available = 0;
            
            // write configuration into EEPROM memory
            if (payload[0] == SET_CONFIG_CMD) {
                // write data length
                uint16_t addr = FIRST_EE_ADDR;
                DATAEE_WriteByte (addr, data_len-1);
                // write data
                addr += 1;
                for (uint8_t i=1;i<data_len; i++, addr+=1)
                    DATAEE_WriteByte (addr, payload[i]);
                
                sendACK();
                
                
                buttonList_len = createButtonList (&payload[1], data_len-1, buttonList);
                arrangeButtonsInMatrix (buttonList, buttonList_len, ID_grid);
                
                // LOAD CONFIGURATION ()
            }

            
            // get configuration from EEPROM memory and send it
            else if (payload[0] == GET_CONFIG_CMD) {
                
                uint16_t addr = FIRST_EE_ADDR;
                uint8_t len = DATAEE_ReadByte (addr);
                if(len > 250) len = 250;
                
                
                // set payload start sequence
                payload [0] = 0x01;
                payload [1] = 0x02;
                payload [2] = 0x03;
                payload [3] = len+1;
                payload [4] = RESPONSE_TO_GET_CONFIG;
                
                addr += 1;
                for (uint8_t i=0;i<len; i+=1, addr += 1)
                    // set payload length and data content
                    payload[i+5] = DATAEE_ReadByte(addr);
                
                
                // send data in chunks of 150 Bytes. wait 10ms between a packet and the following
                uint8_t sent = 0;
                for (uint8_t i=0;i<len+5; i+=1, addr += 1) {
                    // send data
                    EUSART2_Write (payload[i]);
                    sent += 1;
                    if(sent >= 150) {
                        sent = 0;
                        __delay_ms(10);
                    }
                }
            }
            
            else if (payload[0] == PRESS_BUTTON_CMD) {
                
                playTone (200);
                
                int buttonID = payload[1];
                
                if (toPress == false)
                    pressButton(buttonID);
                
                else {
                    if(btopress_idx<5) {
                        
                        buttonToPress_buffer[btopress_idx++] = buttonID;
                    }
                }
            }
        }
        
        
        
     
        
        if(posX_reached && posY_reached && toPress){
            
            // press servo sequence
            servoPress();
            __delay_ms(300);
            servoRelease();
            
            toPress = 0;
            
            if (btopress_idx != 0) {
                
                pressButton (buttonToPress_buffer[0]);
                btopress_idx --;
                
                // move all IDS to the left
                for(int8_t i=1; i<=btopress_idx; i++)
                    buttonToPress_buffer[i-1] = buttonToPress_buffer[i];
            }
        }
   
        
        
        int8_t row = -1, col = -1;
        
        uint8_t i;
        for (i=0; i<5; i++){
            
            setAddress(i);
            __delay_ms(10);
            
            ADCC_StartConversion(channel_ANB0);
            while(!ADCC_IsConversionDone());
            uint16_t val = ADCC_GetConversionResult();
            
            if(val < IR_SENSOR_THRESHOLD){
                row = i;
                break;
            }
        }
        if(row != -1) {
            for (i = 5; i<10; i++){

                setAddress(i);
                __delay_ms(10);

                ADCC_StartConversion(channel_ANB0);
                while(!ADCC_IsConversionDone());
                uint16_t val = ADCC_GetConversionResult();
                if(val < IR_SENSOR_THRESHOLD){
                    col = i-5;
                    break;
                }
            }
            if(col != -1 && matrix_enabled) {
                
                matrix_enabled = 0;
                
                // if there is a button press running, add this ID to the stack.
                // otherwise go for pressing the button
                int buttonID = ID_grid[row][col];
                if (buttonID != -1) {
                    playTone (200);
                    if (toPress == false)
                        pressButton(buttonID);
                    
                    else {
                        if(btopress_idx < 5) {

                            buttonToPress_buffer[btopress_idx++] = buttonID;
                        }
                    }
                }
            }
        }
        
        if(row == -1 && col == -1){
            matrix_enabled = 1;
        }
    }
}



void playTone (int duration_ms) {
    
    
    double timerValue = 0xffff - (duration_ms * 15.5);
    TMR1_WriteTimer((uint16_t) timerValue);
    
    TRISC &= 0b11110111;
    TMR1_StartTimer();
}



void TMR1_ISRHandler (void) {
    
    TMR1_StopTimer();
    TRISC |= 0b00001000;
}





void pressButton (int buttonID) {
    
    int button_idx = getIdxForButtonWithID (buttonList, buttonID, buttonList_len);

    int targetPosX = 39 - buttonList[button_idx].xPos;
    int targetPosY = buttonList[button_idx].yPos - 49;

    setTargetX (targetPosX);
    setTargetY (targetPosY);

    toPress = true;
}   







// thrown by RC4
void encoder1A_InterruptHandler (void) {
    
    if (ENC1A_GetValue() == 1){
        if (ENC1B_GetValue() == 1) posX +=1;
        else posX -=1;
    }
    else {
        if (ENC1B_GetValue() == 1) posX -=1;
        else posX +=1;
    }
    
    
    if(posX > targetX+1){
        MOTOR1A_SetLow();
        MOTOR1B_SetHigh();
        posX_reached = 0;
    }
    else if(posX < targetX-1) {
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

// thrown by RC5
void encoder1B_InterruptHandler (void){
    
   // if (ENC1A_GetValue() == 1) return;
    
    /*if (ENC1A_GetValue() == 1) posX ++;
    else posX --;*/
}

// thrown by RC6
void encoder2A_InterruptHandler (void){
    
    
    if(ENC2A_GetValue() == 1) {
        if (ENC2B_GetValue() == 1) posY ++;
        else posY --;
    }
    else {
        if (ENC2B_GetValue() == 1) posY --;
        else posY ++;
    }
    
    if(posY > targetY+1){
        MOTOR2A_SetLow();
        MOTOR2B_SetHigh();
        posY_reached = 0;
    }
    else if(posY < targetY-1) {
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



// thrown by RC7
void encoder2B_InterruptHandler (void){
    
    /*if (ENC2A_GetValue() == 1) posY ++;
    else posY --;*/
}



inline void setAddress (uint8_t addr) {
     
    addr &= 0b00001111;
    LATA &= 0b11100001;
    LATA |= (addr << 1);
}