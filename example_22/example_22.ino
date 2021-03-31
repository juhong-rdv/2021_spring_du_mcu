int melody[8] = {262, 293, 330, 349, 392, 440, 466, 523} ;

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
    int i = 0 ;
    for( i=0 ; i<8 ; i++ )
    {
      tone(8, melody[i], 500);
      delay(500);
    }
}
