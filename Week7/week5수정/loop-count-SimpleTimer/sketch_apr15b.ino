#include <SimpleTimer.h>

SimpleTimer timerCnt;  

unsigned long loopCnt; 

void timerFun() {
  Serial.println(loopCnt);  
  loopCnt = 0;
}

void setup() {
  Serial.begin(115200);  
  Serial.println();  
  loopCnt = 0;

  timerCnt.setInterval(1000, timerFunc);  
}

void loop() {
  timerCnt.run();  
  loopCnt++;  
}

