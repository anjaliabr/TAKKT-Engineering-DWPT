// Define analog input
#define ANALOG_IN_PIN A0
#define ANALOG_DWC_PIN A1

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
 
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
int dwc_value = 0;

// Floats for DWC values
float dwc_voltage = 0.0;
float dwc_in_voltage = 0.0;

// Enter amount of batterys in pack
float battery_num = 4;

// Enter High Voltage of batterys
float battery_fullvolt = 2;
float battery_full = 0;

// Enter Low Voltage of batterys
float battery_lowvolt = 1.1;
float battery_low = 0;

// percent
float percent = 0;

// pins for led
int redPin= 9;
int greenPin = 8;
int bluePin = 7;

 
void setup()
{


   
  lcd.begin(16, 2);
  // Clears the LCD screen
  lcd.clear();
}
 
void loop(){
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   dwc_value = analogRead(ANALOG_DWC_PIN);

   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   dwc_voltage  = (dwc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = (adc_voltage / (R2/(R1+R2))) ; 
   dwc_in_voltage = (dwc_voltage / (R2/(R1+R2))) ; 

   
if (in_voltage >= 9) {
        analogWrite(greenPin, 255);
        analogWrite(redPin,   0);
    analogWrite(bluePin,   0);         
        percent = 100;
}
    else if (in_voltage >= (8)) {   // 90-100% range
      percent = map(in_voltage, (8), 9, 90, 100);
         analogWrite(greenPin, 100);
      analogWrite(redPin,   150);  
      analogWrite(bluePin,   0);         
    }
    else if (in_voltage >= (6))  {  // 10-90% range
      percent = map(in_voltage, 6, (8), 10, 90);
       analogWrite(redPin,   255);
        analogWrite(greenPin, 20); 
       analogWrite(bluePin,   0);         
        
    }
    else if (in_voltage >= 5.9) {   // 0-10% range
      percent = map(in_voltage, 4, 5.9, 0, 10);
            analogWrite(redPin,   201);
           analogWrite(greenPin, 0);  
       analogWrite(bluePin,   0);         

    }
    else{ 
      percent = 0;
           analogWrite(greenPin, 0);
           analogWrite(redPin,   255);
        analogWrite(bluePin,   0);         

    }

    
    lcd.setCursor(0, 0);
    lcd.print("Battery: ");
    lcd.setCursor(10, 0); 
    lcd.print(in_voltage,DEC);

    lcd.setCursor(0, 1);
    lcd.print("Input: ");
    lcd.setCursor(10, 1); 
    lcd.print(dwc_in_voltage,DEC);



  // Short delay
  delay(1000);





}
