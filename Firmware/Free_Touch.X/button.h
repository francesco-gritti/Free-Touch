/* 
 * File:   button.h
 * Author: francesco
 *
 * Created on May 20, 2021, 6:39 AM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#ifdef	__cplusplus
extern "C" {
#endif
    

#define MAX_BUTTONS  25
#define BUTTON_DESC_LEN 10
#define LABEL_LEN   6

#define MAX_ROWS    5
#define MAX_COLS    5
   

    
    
#pragma pack(1)

typedef struct {

    char label [6];

    int8_t xPos;
    int8_t yPos;
    int8_t ID;
} button_t;



int getIdxForButtonWithID (button_t * button_list, int ID, int len);

int createButtonList (const uint8_t * data, int len, button_t * buttonList);

void arrangeButtonsInMatrix (button_t *button_list, int N, uint8_t id_grid[5][5]);





#ifdef	__cplusplus
}
#endif

#endif	/* BUTTON_H */


