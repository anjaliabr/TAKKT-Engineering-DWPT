#include <LiquidCrystal.h>
#define ANALOG_IN_PIN A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;
 
void setup()
{
    lcd.begin (16,2 );
   // Setup Serial Monitor
   Serial.begin(9600);
  
}
 
void loop(){
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 

  lcd.setCursor (0, 0);
  lcd.print("Voltage Measured");
   // Print results to Serial Monitor to 2 decimal places
  lcd.setCursor (0, 1);
  lcd.print("Battery= ");
  lcd.print(in_voltage, 2);
  lcd.print (" volts");
  
  // Short delay
  delay(500);
}
