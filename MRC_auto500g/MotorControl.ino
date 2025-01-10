#include "Newkub.h"

void motor(int speedL, int speedR) {
  speedL = (speedL * 255) / 100;
  speedR = (speedR * 255) / 100;

  //motor Left speed
  if (speedL == 0) {
    digitalWrite(DIR_L, LOW);
    analogWrite(PWM_L, 0);
  } else if (speedL > 0) {
    digitalWrite(DIR_L, LOW);
    analogWrite(PWM_L, speedL);  //50 = 50
  } else {
    digitalWrite(DIR_L, HIGH);
    analogWrite(PWM_L, -speedL);  //-(-50) = 50
  }

  //motor Right speed
  if (speedR == 0) {
    digitalWrite(DIR_R, LOW);
    analogWrite(PWM_R, 0);
  } else if (speedR > 0) {
    digitalWrite(DIR_R, LOW);
    analogWrite(PWM_R, speedR);  //50 = 50
  } else {
    digitalWrite(DIR_R, HIGH);
    analogWrite(PWM_R, -speedR);  //-(-50) = 50
  }
}