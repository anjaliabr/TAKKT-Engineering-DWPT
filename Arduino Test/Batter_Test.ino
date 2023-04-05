// Define analog input
#define ANALOG_IN_PIN A0
 
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

// Check Battery State of charge chart

// Enter amount of batterys in pack
float battery_num = 4;

// Enter High Voltage of batterys
float battery_fullvolt = 2;
float battery_full = 0;

// Enter Low Voltage of batterys
float battery_lowvolt = 1.1;
float battery_low = 0;


float percent = 0;
 
void setup()
{
   // Setup Serial Monitor
   Serial.begin(9600);
   Serial.println("DC Voltage Test");
}
 
void loop(){
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = (adc_voltage / (R2/(R1+R2))) ; 

   battery_full = battery_num * battery_fullvolt;
   battery_low = battery_num * battery_lowvolt;

   
    //if (in_voltage >= battery_full) percent = 100;
    //else if (in_voltage >= (battery_full*0.9))    // 90-100% range
      //percent = map(in_voltage, (battery_full*0.9), battery_full, 90, 100);
    //else if (in_voltage >= (battery_full*0.8))    // 10-90% range
     // percent = map(in_voltage, battery_low, (battery_full*0.9), 10, 90);
    //else if (in_voltage >= battery_low)    // 0-10% range
     // percent = map(in_voltage, 4, battery_low, 0, 10);
    //else percent = 0;

        if (in_voltage >= 9) percent = 100;
    else if (in_voltage >= (8))    // 90-100% range
      percent = map(in_voltage, (8), 9, 90, 100);
    else if (in_voltage >= (6))    // 10-90% range
      percent = map(in_voltage, 6, (8), 10, 90);
    else if (in_voltage >= 5.9)    // 0-10% range
      percent = map(in_voltage, 4, 5.9, 0, 10);
    else percent = 0;

   //Calculate Battery Percentage
  // percent = map(in_voltage, battery_low, battery_full, 0, 100);;
   
   // Print Battery Percentage to Serial Monitor
    Serial.print("Battery Percentage = ");
  Serial.println(in_voltage,3);
    Serial.println(percent);

  
  // Short delay
  delay(1000);
}
