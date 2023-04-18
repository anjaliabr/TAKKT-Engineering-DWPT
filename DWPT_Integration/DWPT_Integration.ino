// import libraries
#include <NewPing.h>
#include <LiquidCrystal.h>

// defining pins
#define maxDistance 300
#define sonarNum 3

// defining pins
const int TRIG_PIN[sonarNum] = {35, 33, 31};
const int ECHO_PIN[sonarNum] = {34, 32, 30};
const int RELAY_PIN[sonarNum] = {7, 6, 5};

// calling NewPing
NewPing sonar[sonarNum] = {
  NewPing(TRIG_PIN[0], ECHO_PIN[0], maxDistance),
  NewPing(TRIG_PIN[1], ECHO_PIN[1], maxDistance),
  NewPing(TRIG_PIN[2], ECHO_PIN[2], maxDistance)
};

// calling LiquidCrystal
//LiquicCrystal lcd(12, 11, 5, 4, 3, 2);

// declaring the distance calculated
long currentDist;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN[0], OUTPUT);
  pinMode(RELAY_PIN[1], OUTPUT);
  pinMode(RELAY_PIN[2], OUTPUT);
  //lcd.begin(16,2);
  //lcd.print("Coil 1");
}

void loop() {
  //lcd.setCursor(0, 1);
  for(uint8_t i = 0; i < sonarNum; i++) {
    currentDist = sonar[i].ping_cm();
    if(currentDist < 25 && currentDist  > 0){
      delay(500);
      digitalWrite(RELAY_PIN[i], HIGH);

      Serial.print("Coil ");
      Serial.println(i+1);
      Serial.print("Distance: ");
      Serial.println(sonar[i].ping_cm());
    }
    else {
      digitalWrite(RELAY_PIN[i], LOW);

    }
  }
}