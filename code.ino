#include <LiquidCrystal.h>;
#include <SoftwareSerial.h> // Hc-06 Bluetooth Modülü kütüphanesi tanımladık. 
#include <Wire.h>
#include <Adafruit_INA219.h> 


SoftwareSerial hc06(8, 9);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Adafruit_INA219 ina219;

int differential_data;
void setup() {
  hc06.begin(9600);  // Hc-06 Bluetooth Modülü serial haberleşmesini aktif hale getirdik.

  lcd.begin(16, 2);
  lcd.print("welcome");
 // lcd.setCursor(0, 1);
}
void loop() {

  float shuntvoltage = 0;
  float current_mA = 0;
  float bloodglucose = 0;
  
  shuntvoltage = ina219.getShuntVoltage_mV();
  current_mA = ina219.getCurrent_mA();


  differential_data = chan_diff();
  for (int i = 0; i < 10; i++) //Get 10 sample value from the sensor for smooth the value
  {
    buf[i] = differential_data;
    delay(10);
  }
  for (int i = 0; i < 9; i++) //sort the analog from small to large
  {
    for (int j = i + 1; j < 10; j++)
    {
      if (buf[i] > buf[j])
      {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (int i = 2; i < 8; i++) //take the average value of 6 center sample
    avgValue += buf[i];
  overal_data = (float)avgValue / 6; //convert the analog into millivolt
  volt_gluco = overal_data * 5 / 1023; //to get voltage value in V
  gluco = (volt_gluco - 2.6835) / 0.00185; //to get glucose level in mg/dl
  gluco_mmol = gluco / 18; //to get glucose level in mmol/L


  lcd.println("GLCS" + gluco_mmol);
  hc06.print("GLCS" + gluco_mmol);
  
  if (hc06.available()) {
      Serial.print("Bluetooth hc06'den gelen deger:"); // Ekrana yazı yazdırdık.
      Serial.write(hc06.read()); // Hc-06 Bluetooth Modülünden gelen verileri ekrana yazdırdık.
      Serial.println(" "); // Bir alt satıra geçmesini sağladık.
    }
  
}



int chan_diff () //function for differential mode
{
  analogRead (0) ;
  delay (10) ;
  int ch1 = analogRead (0) ;
  analogRead (glucoinput2) ;
  delay (10) ;
  int ch2 = analogRead (1) ;
  ch1 += analogRead (0) ;
  ch1 >>= 1 ;
  return ch1 - ch2 ;
}
