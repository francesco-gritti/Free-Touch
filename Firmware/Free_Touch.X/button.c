



#include "mcc_generated_files/mcc.h"
#include "button.h"
#include <math.h>



void arrangeButtonsInMatrix (button_t *button_list, int N, uint8_t id_grid[MAX_ROWS][MAX_COLS]) {
     
    for (uint8_t y=0;y<MAX_ROWS; y++){
        for (uint8_t x=0;x<MAX_COLS; x++) {
            
            id_grid[y][x] = -1;
    }}
    
    
    int columns = 0, rows = 0;

    int rowPosition[10];
    int columnPosition[10];

    int delta_max = 6;

    do {

        for (int i = 0; i < N; i += 1) {

            bool existingRow = false;
            for (int j = 0; j < rows; j++) {

                if (abs(button_list[i].yPos - rowPosition[j]) < delta_max) {
                    existingRow = true;
                    break;
                }
            }
            if (!existingRow) {
            rowPosition[rows] = button_list[i].yPos;

            for (int pos = rows; pos > 0; pos -= 1) {

                if (button_list[i].yPos < rowPosition[pos - 1]) {
                rowPosition[pos] = rowPosition[pos - 1];
                rowPosition[pos - 1] = button_list[i].yPos;
                } else break;
            }
            rows += 1;
            }

            bool existingColumn = false;
            for (int j = 0; j < columns; j++) {

                if (abs(button_list[i].xPos - columnPosition[j]) < delta_max) {
                    existingColumn = true;
                    break;
                }
            }
            if (!existingColumn) {
            columnPosition[columns] = button_list[i].xPos;

            for (int pos = columns; pos > 0; pos -= 1) {

                if (button_list[i].xPos < columnPosition[pos - 1]) {
                columnPosition[pos] = columnPosition[pos - 1];
                columnPosition[pos - 1] = button_list[i].xPos;
                } else break;
            }
            columns += 1;
            }
        }
        delta_max ++;
    }
    while (rows > MAX_ROWS || columns > MAX_COLS);

    
    --delta_max;
    
    
    for (uint8_t i = 0; i < N; i++) {

        uint8_t c, r;

        for (c = 0; c < columns; c++) 
            if (abs(button_list[i].xPos - columnPosition[c]) < delta_max)break;
        
        for (r = 0; r < rows; r++) 
            if (abs(button_list[i].yPos - rowPosition[r]) < delta_max)break;
            
        id_grid[r][c] = button_list[i].ID;
    }
}





int getIdxForButtonWithID (button_t * button_list, int ID, int len) {

    for (int i=0;i<len; i++) {

        if(button_list[i].ID == ID)
            return i;
    }
    return -1;
}



int createButtonList (const uint8_t * data, int len, button_t * button_list) {


    int N_buttons = len / BUTTON_DESC_LEN;

    int offset = 0;
    for (int i=0; i<N_buttons; i++) {

        // assign label data
        for (int j = 0; j<LABEL_LEN; j++)
            button_list[i].label[j] = data[offset++];

        int xPos = data [offset++];
        int yPos = data [offset++];
        int ID = data[++offset];

        ++offset;
        button_list[i].xPos = xPos > 127 ? (-255 + xPos) : xPos;
        button_list[i].yPos = yPos > 127 ? (-255 + yPos) : yPos;
        button_list[i].ID = ID & 0x7f;
    }

    return N_buttons;
}