# include <NewPing.h>

# define maxDistance 200
# define sonarNum 4

NewPing sonar[sonarNum] = {
  NewPing(13, 12, maxDistance),
  NewPing(10, 9, maxDistance),
  NewPing(7, 6, maxDistance),
  NewPing(4, 3, maxDistance)
};

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (uint8_t i = 0; i < sonarNum; i++) {
    if(sonar[i].ping_cm() > 10) {
      delay(1000);
      Serial.print("Sensor ");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(sonar[i].ping_cm());
      Serial.println(" cm");
    }
    else {
      Serial.println("No signal detected");
    }
    
  }
  Serial.println();
}
