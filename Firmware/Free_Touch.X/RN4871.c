
#include "mcc_generated_files/mcc.h"
#include "RN4871.h"


/*
    The library now implements the following features:
 
    - detect CMD>, AOK, Err, END messages in response to command
    
    - detects %CONNECT,,%, %DISCONNECT,,% messages sent on connect/disconnect events 
 
    
 
    To implement:
 
    - detect characteristic written event and get data out of it
 
*/



// flags use throughout the main application
volatile uint8_t err_flag = 0;
volatile uint8_t aok_flag = 0;
volatile uint8_t cmd_flag = 0;
volatile uint8_t reboot_flag = 0;
volatile uint8_t stropen_flag = 0;
volatile uint8_t data_available = 0;
volatile uint8_t connection_status = 0;



const uint8_t enter_command_mode_sequence [3] = "$$$";
const uint8_t exit_command_mode_sequence [5] = "\n---\n";
const uint8_t reboot_command [4] = "R,1\n";
const uint8_t setManufacturerDataCommand[6] = "IA,FF,";



volatile uint8_t _waiting_stropen = 0;
volatile uint8_t special_command_flag = 0;


const uint8_t cmdMessage[4] = "CMD>";
const uint8_t errorMessage[4] = "Err\n";
const uint8_t aokMessage[4] = "AOK\n";
const uint8_t stdMessageLen = 4;


volatile uint8_t aok_idx = 0;
volatile uint8_t cmd_idx = 0;
volatile uint8_t err_idx = 0;



const uint8_t rebootMessage[6] = "REBOOT";
const uint8_t rebootMessageLen = 6;
volatile uint8_t reboot_idx = 0;

const uint8_t connectMessage[7] = "CONNECT";
const uint8_t connMessageLen = 7;
volatile uint8_t conn_idx = 0;

const uint8_t disconnectMessage[10] = "DISCONNECT";
const uint8_t disconnectMessageLen = 10;
volatile uint8_t disconn_idx = 0;

const uint8_t characteristicWriteMessage[2] = "WV";
const uint8_t characteristicWriteMessageLen = 2;
volatile uint8_t chw_idx = 0;

const uint8_t streamOpenMessage [11] = "STREAM_OPEN";
const uint8_t streamOpenMessageLen = 11;
volatile uint8_t stropen_idx = 0;



const uint8_t frameStartSequence [3] = {0x01, 0x02, 0x03};
volatile  uint8_t fstart_idx = 0;




void sendACK (void) {
    
    payload [0] = 0x01;
    payload [1] = 0x02;
    payload [2] = 0x03;
    payload [3] = 0x01;
    payload [4] = ACK;

    for(uint8_t i=0;i<5;i++)
        EUSART2_Write(payload[i]);
}


void setRandomAddress (void) {
    
    cmd_flag = 0;
    EUSART2_Write('&');
    EUSART2_Write('R');
    EUSART2_Write('\n');
}


void setAdvertisementManufacturerData (uint8_t * data, uint8_t len) {
    
    aok_flag = 0;
    for(uint8_t i=0;i<6; i++)
        EUSART2_Write (setManufacturerDataCommand[i]);
    
    for (uint8_t i=0;i<len; i++)
        EUSART2_Write (data[i]);
     
    EUSART2_Write('\n');
}



void reboot (void) {
    
    reboot_flag = 0;
    for(uint8_t i=0;i<4; i++)
        EUSART2_Write(reboot_command[i]);
}



void enterCommandMode (void) {
    
    cmd_flag = 0;
    for(uint8_t i=0;i<3; i++)
        EUSART2_Write(enter_command_mode_sequence[i]);
}

void exitCommandMode (void) {
    
    for(uint8_t i=0;i<5; i++)
        EUSART2_Write(exit_command_mode_sequence[i]);
}

   

volatile uint8_t prev_data;

volatile uint8_t valid_data = 0;
volatile uint16_t data_len = 0;
volatile uint8_t data_read_started = 0;
volatile uint8_t payload [256];
volatile uint8_t payload_idx = 0;

// on stream open: %STREAM_OPEN%%CONN_PARAM,0018,0000,0200%
// after stream open there could be %CONN_PARAM,,,% or %ERR_CONNPARAM%
// there is no stream close, just device disconnection => need to look for DISCONNECT

// since the ASCII value of % is still a valid value, we need to discard it only if it is followed
// by CONN_PARAM or ERR_CONNPARAM. To do so, we could save the index of % in the byte, and then if we detect 
// one of the two keywords, all the data in between the previous '%' and the next one are discarded.


// another possible implementation is to form the frame so that the first byte (or a sequence of Bytes) is
// unique and so all the data received before the starting sequence can be discarded.


void USART_Handler (void) {
    
    uint8_t data = RC2REG;
    
    
    if (valid_data == 1) {
        
        if (data_read_started == 0) {
            payload_idx = 0;
            data_len = data;
            data_read_started = 1;
        }
        else {
            payload[payload_idx] = data;
            
            if (++payload_idx == data_len) {
                valid_data = 0;
                data_available = 1;
            }
        }
        
        prev_data = data;
        return;
    }
    
    if (data == frameStartSequence[fstart_idx]) {
        fstart_idx += 1;
        
        if (fstart_idx == 3) {
            valid_data = 1;
            data_read_started = 0;
            payload_idx = 0;
            fstart_idx = 0;
        }
        
    }else fstart_idx = 0;
    
    
    
    if (data == '%') {
        
        if(prev_data == '%'){
            special_command_flag = 1;
            return;
        }
        // toggle special command flag
        if(special_command_flag == 0)
            special_command_flag = 1; 
        
        else {
            special_command_flag = 0;
            if (_waiting_stropen){
                _waiting_stropen = 0;
                stropen_flag = 1;
            }
        }
        prev_data = data;
        return;     // nothing else to do 
    }
    
    
    // look for standard command (CMD>, AOK, Err, END)
    if (special_command_flag == 0) {
        
        // command CMD>
        if (data == cmdMessage[cmd_idx]){
            cmd_idx += 1;

            if(cmd_idx == stdMessageLen){
                cmd_idx = 0;
                cmd_flag = 1;
            }
        }else cmd_idx = 0;
        
        // command AOK
        if (data == aokMessage[aok_idx]){
            aok_idx += 1;

            if(aok_idx == 3){
                aok_idx = 0;
                aok_flag = 1;
            }
        }else aok_idx = 0;
        
        // command Err
        if (data == errorMessage[err_idx]){
            err_idx += 1;

            if(err_idx == stdMessageLen){
                err_idx = 0;
                err_flag = 1;
            }
        }else err_idx = 0;
    }
    
    // look for commands between '%' like CONNECT, DISCONNECT, REBOOT characteristic write, ecc.
    else {
        
        
        // REBOOT
        if (data == rebootMessage[reboot_idx]){
            reboot_idx += 1;

            if(reboot_idx == rebootMessageLen){
                reboot_idx = 0;
                reboot_flag = 1;
            }
        }else reboot_idx = 0;
        
        
        // CONNECT
        if (data == connectMessage[conn_idx]){
            conn_idx += 1;

            if(conn_idx == connMessageLen){
                conn_idx = 0;
                connection_status = 1;
            }
        }else conn_idx = 0;
        
        
        // DISCONNECT
        if (data == disconnectMessage[disconn_idx]){
            disconn_idx += 1;

            if(disconn_idx == disconnectMessageLen){
                disconn_idx = 0;
                connection_status = 0;
            }
        }else disconn_idx = 0;    
            
        
       
        
    }
    prev_data = data;
}
