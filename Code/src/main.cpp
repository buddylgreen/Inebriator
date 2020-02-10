#include <Arduino.h>
#include <LiquidCrystal.h>
#include "PumpController.cpp"

const int RIGHT_BUTTON = 60;
const int UP_BUTTON = 200;
const int DOWN_BUTTON = 400;
const int LEFT_BUTTON = 600;
const int SELECT_BUTTON = 800;


int pump_number = 0;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
PumpController pumps(0, 1, 2, 3);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Pump: ");
}

void loop() {
  delay(100);
  lcd.setCursor(6,0);
  lcd.print(pump_number);

  int btn_new;
  btn_new = analogRead (0);
  
  if (btn_new < RIGHT_BUTTON) {
    pump_number = abs(pump_number + 1) % 5;
  }
  else if (btn_new < UP_BUTTON) {
    if(pump_number == 1){
      pumps.set_status(ON,OFF,OFF,OFF);
    }else if(pump_number == 2){
      pumps.set_status(OFF,ON,OFF,OFF);
    }else if(pump_number == 3){
      pumps.set_status(OFF,OFF,ON,OFF);
    }else if(pump_number == 4) {
      pumps.set_status(OFF,OFF,OFF,ON);
    }
  }
  else if (btn_new < DOWN_BUTTON){
    if(pump_number == 1){
      pumps.set_status(OFF,OFF,OFF,OFF);
    }else if(pump_number == 2){
      pumps.set_status(OFF,OFF,OFF,OFF);
    }else if(pump_number == 3){
      pumps.set_status(OFF,OFF,OFF,OFF);
    }else if(pump_number == 4) {
      pumps.set_status(OFF,OFF,OFF,OFF);
    }
  }
  else if (btn_new < LEFT_BUTTON){
    pump_number = abs(pump_number - 1) % 5;
  }
  else if (btn_new < SELECT_BUTTON){
  }

}


/*
classes:
  Main
  LCD
  Bottle
  Cocktail
  Pump
  Menu
*/

