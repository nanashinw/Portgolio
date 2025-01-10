#include "Newkub.h"

void tn(float Speed, float Kp, float Kd) {
  position = ReadObs();
  error = position - 2000;
  powermotor = (Kp * error) + (Kd * (error - lasterror));
  lasterror = error;
  leftmotor = Speed + powermotor;
  rightmotor = Speed - powermotor;
  if (leftmotor > 100) leftmotor = 100;
  if (leftmotor < -100) leftmotor = -100;
  if (rightmotor > 100) rightmotor = 100;
  if (rightmotor < -100) rightmotor = -100;
  motor(leftmotor, rightmotor);
}

void TrackPID(float Speed, float Kp, float Kd){
  ReadObs();
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
  ReadObs();
  if (ll == 1 && l == 1 && m == 0 && r == 1 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 0 && m == 0 && r == 0 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 0 && m == 0 && r == 1 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 0 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(50);
  } else if (ll == 0 && l == 0 && m == 1 && r == 1 && rr == 1) {
    tn(Speed,Kp,Kd);
  } else if (ll == 0 && l == 1 && m == 1 && r == 1 && rr == 1) {
    tn(Speed,Kp,Kd);
  } else if (ll == 1 && l == 1 && m == 0 && r == 0 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 1) {
    motor(Speed,-Speed);
    delay(50);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 0) {
    tn(Speed,Kp,Kd);
  } else if (ll == 1 && l == 1 && m == 1 && r == 1 && rr == 0) {
    tn(Speed,Kp,Kd);
  } else {
    motor(30,30);
  }

}

void routine_pid(int Speed, int attack , float Kp,float Kd) {
  while (1) {
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
  int light_L = analogRead(Light_L);
  int light_R = analogRead(Light_R);
  if (light_L > 500 && light_R < 500) {
    motor(-Speed,-Speed);
    delay(200);
    motor(Speed,-Speed);
    delay(230);
  }
  if (light_L < 500 && light_R > 500) {
    motor(-Speed,-Speed);
    delay(200);
    motor(-Speed,Speed);
    delay(230);
  }
  else {
    TrackPID(attack, Kp, Kd);
  }
}
}