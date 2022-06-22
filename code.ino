// gerekli kütüphaneleri eklemek

#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>
Adafruit_INA219 ina219;



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  ina219.begin();   
  Lcd.begin(16, 2) ; 
  Serial.begin(9600);
}
void loop()
{
  
  float shuntvoltage = 0;
  float current_mA = 0;
  float bloodglucose = 0;
  
  shuntvoltage = ina219.getShuntVoltage_mV();
  current_mA = ina219.getCurrent_mA();

 
  Lcd.setcursor (0, 0);
  Lcd.print("Current: ");
  Lcd.print(current_mA);
  Lcd.println(" mA");
  Lcd.setcursor (0, 1);
  Lcd.print("Blood Glucose: ");
  Lcd.print(bloodglucose);
  Lcd.println(" mMole");
  Lcd.println(""); 
  
  delay(500);
}
