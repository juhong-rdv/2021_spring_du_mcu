// C++ code
//
#define RS  11
#define RW  12
#define EN  13

void LCD_Command_Write(unsigned char cmd)
{
  digitalWrite(RS, LOW) ; //RS -> LOW -> 명령
  digitalWrite(RW, LOW) ; //RW -> LOW -> 쓰기
  digitalWrite(EN, HIGH) ;  //E -> HIGH
  
  PORTD = cmd ;   
  delayMicroseconds(1) ;
  
  digitalWrite(EN, LOW) ; //E -> LOW
  delayMicroseconds(1) ;
  
  //4.1msec delay
  delayMicroseconds(4100) ;

}

void LCD_Data_Write(unsigned char data)
{
  digitalWrite(RS, HIGH) ;  //RS -> HIGH -> 데이터
  digitalWrite(RW, LOW) ; //RW -> LOW -> 쓰기
  digitalWrite(EN, HIGH) ;  //E -> HIGH
  
  PORTD = data ;    
  delayMicroseconds(1) ;
  
  digitalWrite(EN, LOW) ; //E -> LOW
  delayMicroseconds(1) ;
  
  //4.1msec delay
  delayMicroseconds(4100) ;
}

void LCD_String_Write(const int x, const int y, char *string, const int size)
{
  unsigned char line_address = 0x00 ;
  
  if( y == 0 )
  {
    line_address = 0x00 ;
  }
  else if( y == 1 )
  {
    line_address = 0x40 ;
  }
  else
  {
    line_address = 0x00 ;
  }
  
  for( int i=0 ; i<size ; i++ )
  {
    LCD_Command_Write(0x80 | (line_address+x+i)) ;  //위치를 변경
    LCD_Data_Write(string[i]) ;
  
  }
}

void setup()
{
  pinMode(RS, OUTPUT) ;
  pinMode(RW, OUTPUT) ;
  pinMode(EN, OUTPUT) ;
  
  DDRD = 0xFF ; //1111 1111  
  
  //LCD 초기화
  
  //0x30 명령 전달
  LCD_Command_Write(0x30) ;
  //0x30 명령 전달
  LCD_Command_Write(0x30) ;
  //0x30 명령 전달
  LCD_Command_Write(0x30) ;
  
  //초기화 완료
  
  //0x38 명령 전달
  LCD_Command_Write(0x38) ;
  
  //0x0D 명령 전달
  LCD_Command_Write(0x0C) ; //0000 1100
  
  //0x01 명령 전달
  LCD_Command_Write(0x01) ;
  
  //0x04 명령 전달
  LCD_Command_Write(0x04) ;
  
  
}

void loop()
{
  for( int x=16 ; x>=0 ; x-- )
  {
    LCD_String_Write(x,0, "Dong Seoul Univ.", 16) ;
  }
  
  //clear
  LCD_Command_Write(0x01) ;
}
