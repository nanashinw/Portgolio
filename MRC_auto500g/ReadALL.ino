#include "Newkub.h"

void ReadIR() {
  int x = 0;
  for (int i = 0; i < 2; i++) {
    x = map(analogRead(pins[i]), MINS[i], MAXS[i], 1000, 0);
    if (x > 1000) x = 1000;
    if (x < 0) x = 0;
    S[i] = x;
  }

}

void Read() {
  int x = 0;
  for (int i = 0; i < numsensor; i++) {
    x = map(nashi(pin[i]), MIN, MAX, 1000, 0);
    F[i] = x;
  }
}


int ReadObs() {
  unsigned long avg = 0, sum = 0;
  int detect = 0;
  Read();
  for (int i = 0; i < numsensor; i++) {
    if (F[i] > 200) {
      detect = 1;
    }
    if (F[i] > 50) {
      avg = avg + (F[i] * (i * 1000));
      sum = sum + F[i];
    }
  }
  if (detect == 0) {
    if (last_value > 2000) {
      return 4000;
    } else {
      return 0;
    }
  } else {
    last_value = avg / sum;
  }
  return last_value;
}

int readDipSwitch(void)
{
  int adc = analogRead(MODE);
  if (adc > 933) return 0;
  if (adc > 773) return 1;
  if (adc > 658) return 2;
  if (adc > 563) return 3;
  if (adc > 487) return 4;
  if (adc > 440) return 5;
  if (adc > 400) return 6;
  return 7;
}