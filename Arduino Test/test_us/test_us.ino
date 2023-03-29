# include <NewPing.h>

// defines pin numbers
# define trigPin 10
# define echoPin 9

// maximum distance in cm
# define maxDistance 300

NewPing sonar(trigPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
