void setup() {
  pinMode(8, OUTPUT) ;   
}

void loop() {

  digitalWrite(8, HIGH);  
  delayMicroseconds(1400);     
  
  digitalWrite(8, LOW);   
  delayMicroseconds(20000-1400);   
}
