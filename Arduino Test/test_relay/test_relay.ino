#define Relaypin 6

void setup() {
  pinMode(Relaypin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(Relaypin, LOW);
  delay(3000);
  digitalWrite(Relaypin, HIGH);
  delay(3000);
  
  // put your main code here, to run repeatedly:

}
