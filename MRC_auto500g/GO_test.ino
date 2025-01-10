void GO_test(int Speed,int attack) {
  while (1) {
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
  int light_L = analogRead(Light_L);
  int light_R = analogRead(Light_R);
  if (light_R > 500) {//L
    motor(-50,-50);
    delay(300);
    motor(50,-50);
    delay(355);
  }
  // if (light_R < 500) {//R
  //   motor(-50,-50);
  //   delay(300);
  //   motor(-50,50);
  //   delay(225);
  // }
  else {
    Track(attack);
  }
}
}