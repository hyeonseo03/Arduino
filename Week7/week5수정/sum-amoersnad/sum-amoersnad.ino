int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(9600);
  Serial.println();

  // a1, a2, a3를 sum 함수로 전달하여 a3에 합계 저장
  sum(a1, a2, a3);

  Serial.println(a3);  // 합계 출력
}

void loop() {
  // loop 함수는 현재 필요하지 않음
}

void sum(int a, int b, int& c) {
  c = a + b;  // c에 a와 b의 합을 저장
}

