#include <IRremote.h>
#include <LiquidCrystal.h>

#define IR_RECEIVE_PIN 5

#define IR_BUTTON_0 22
#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_FUNC_STOP 71

#define LED_1_PIN 12
#define LED_2_PIN 11
#define LED_3_PIN 10

#define LCD_RS_PIN A5 //use A5 as digital pin
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

#define LED_ARRAY_SIZE 3

byte LEDArray[LED_ARRAY_SIZE] = {LED_1_PIN, LED_2_PIN, LED_3_PIN};

byte LEDStateArray[LED_ARRAY_SIZE] = { LOW, LOW, LOW };

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN,
                  LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

void initLEDModes() {
  for (int i = 0; i < LED_ARRAY_SIZE; i++) {
    pinMode(LEDArray[i], OUTPUT);
  }
}

void powerOffAllLEDs() {
  for (int i = 0; i < LED_ARRAY_SIZE; i++) {
    LEDStateArray[i] = LOW;
    digitalWrite(LEDStateArray[i], LOW);
  }
}

void toggleLEDs(int index) {
  if (index >= LED_ARRAY_SIZE) {
    return;
  }
  if (LEDStateArray[index] == HIGH) {
    LEDStateArray[index] = LOW;
  }
  else {
    LEDStateArray[index] = HIGH;
  }
  digitalWrite(LEDArray[index], LEDStateArray[index]);
}

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  lcd.begin(16,2);
  initLEDModes();
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    
    int command = IrReceiver.decodedIRData.command;

    switch (command) {
      case IR_BUTTON_0: {
        powerOffAllLEDs();
        lcd.setCursor(0,0);
        lcd.print("All LEDs off.      ");
        break;
      }
      case IR_BUTTON_1: {
        toggleLEDs(0);
        lcd.setCursor(0,0);
        lcd.print("Toggle LED 1.     ");
        break;
      }
      case IR_BUTTON_2: {
        toggleLEDs(1);
        lcd.setCursor(0,0);
        lcd.print("Toggle LED 2.      ");
        break;
      }
      case IR_BUTTON_3: {
        toggleLEDs(2);
        lcd.setCursor(0,0);
        lcd.print("Toggle LED 3.      ");
        break;
      }
      case IR_BUTTON_FUNC_STOP: {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Clear LCD.        ");
        delay(250);
        lcd.clear();
        break;
      } 
    }
  }
}
  
  
  


// map buttons 0,1,2,3, FUNC/STOP (5 buttons)
//0 -> power off all leds
//1 -> toggle led 1 (12)
//2 -> toggle led 2
//3 -> toggle led 3

//lcd first line -> print data recieved ("toggle led 1")
//func/stop -> clear lcd

