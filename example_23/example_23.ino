void setup() {
  pinMode(9, OUTPUT);  // 핀을 출력으로 설정
}

void loop() {
  for( int i=0 ; i<255 ; i++ )
  {
    analogWrite(9, i); //analogWrite 값은 0 부터 255까지  
    delay(30) ;
  }

  for( int i=0 ; i<255 ; i++ )
  {
    analogWrite(9, 255-i); //analogWrite 값은 0 부터 255까지  
    delay(30) ;
  }
  
}
