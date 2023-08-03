

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display



#define pump_pin 12


uint8_t row_pin[4] = {7, 6, 5, 4};
uint8_t col_pin[4] = {8, 9, 10, 11};



const char values [4][4][5] =  {

  {{"1"}, {"2"}, {"3"}, {"ENT"}},
  {{"4"}, {"5"}, {"6"}, {"CANC"}},
  {{"7"}, {"8"}, {"9"}, {"CLR"}},
  {{"<"}, {"0"}, {">"}, {"F"}},
};



void setup() {


  for (uint8_t i = 0; i < 4; i++) {
    pinMode(row_pin[i], INPUT_PULLUP);
  }

  for (uint8_t i = 0; i < 4; i++) {
    pinMode(col_pin[i], INPUT_PULLUP);
  }


  Serial.begin(115200);
  Wire.setClock(400000);
 
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Hai premuto:");

  pinMode(pump_pin, OUTPUT);
  digitalWrite(pump_pin, LOW);
}

void loop() {



  for (uint8_t i = 0; i < 4; i++) {

    pinMode(row_pin[i], OUTPUT);
    digitalWrite(row_pin[i], LOW);
    
    delay(1);


    for (uint8_t j = 0; j < 4; j++) {

      if (digitalRead(col_pin[j]) == LOW) {
        
        Serial.println(values[i][j]);
        lcd.setCursor(0,1);
        lcd.print(values[i][j]);
        lcd.print("   ");

        digitalWrite(pump_pin, HIGH);
        delay(2000);
       digitalWrite(pump_pin, LOW);
      }
      
    }

    pinMode(row_pin[i], INPUT_PULLUP);

    delay(1);

  }
}
