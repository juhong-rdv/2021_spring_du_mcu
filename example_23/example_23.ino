void setup() 
{
  pinMode(9, OUTPUT);
  pinMode(8, INPUT_PULLUP); 
}
 
void loop() 
{
  if (digitalRead(8) == LOW)
  {
    tone(8, 262, 500) ;
    delay(500) ;
  }
}
