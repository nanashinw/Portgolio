#include "Newkub.h"

void Track(int Speed) {
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
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
    motor(-Speed,Speed);
    delay(100);
  } else if (ll == 0 && l == 1 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(150);
  } else if (ll == 1 && l == 1 && m == 0 && r == 0 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 1) {
    motor(Speed,-Speed);
    delay(50);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 0) {
    motor(Speed,-Speed);
    delay(100);
  } else if (ll == 1 && l == 1 && m == 1 && r == 1 && rr == 0) {
    motor(Speed,-Speed);
    delay(150);
  } else {
    motor(30,30);
  }
}


void Track_turn(int Speed) {
  int ll = digitalRead(LL);
  int l = digitalRead(L);
  int m = digitalRead(M);
  int r = digitalRead(R);
  int rr = digitalRead(RR);
  if (ll == 1 && l == 1 && m == 0 && r == 1 && rr == 1) {
    motor(0,0);
  } else if (ll == 1 && l == 0 && m == 0 && r == 0 && rr == 1) {
    motor(0,0);
  } else if (ll == 1 && l == 0 && m == 0 && r == 1 && rr == 1) {
    motor(0,0);
  } else if (ll == 1 && l == 0 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(40);
  } else if (ll == 0 && l == 0 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(100);
  } else if (ll == 0 && l == 1 && m == 1 && r == 1 && rr == 1) {
    motor(-Speed,Speed);
    delay(130);
  } else if (ll == 1 && l == 1 && m == 0 && r == 0 && rr == 1) {
    motor(Speed,Speed);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 1) {
    motor(Speed,-Speed);
    delay(40);
  } else if (ll == 1 && l == 1 && m == 1 && r == 0 && rr == 0) {
    motor(Speed,-Speed);
    delay(100);
  } else if (ll == 1 && l == 1 && m == 1 && r == 1 && rr == 0) {
    motor(Speed,-Speed);
    delay(130);
  } else {
    motor(0,0);
  }
}

