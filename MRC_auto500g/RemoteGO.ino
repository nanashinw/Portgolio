#include "Newkub.h"


void GO_remote(int Speed,int attack) {
  while (digitalRead(13)) {
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
  int light_L = analogRead(Light_L);
  int light_R = analogRead(Light_R);
  if (light_L > 500 && light_R < 500) {//L
    motor(-50,-50);
    delay(275);
    motor(50,-50);
    delay(175);
  }
  if (light_L < 500 && light_R > 500) {//R
    motor(-50,-50);
    delay(275);
    motor(-50,50);
    delay(175);
  }
  else {
    Track(attack);
  }
}
}



