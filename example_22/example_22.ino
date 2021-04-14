void setup() {
  pinMode(9, OUTPUT);  // 핀을 출력으로 설정
}

void loop() {
  analogWrite(9, 0); //analogWrite 값은 0 부터 255까지
}
