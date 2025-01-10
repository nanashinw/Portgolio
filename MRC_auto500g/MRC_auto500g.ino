#include "Newkub.h"

// total sensor
#define numsensor 5 // ---Change here
int pin[numsensor] = {5, 7, 14, 6, 2};
int MAX = 1;
int MIN = 0;
unsigned long F[numsensor];
int last_value = 0;
float leftmotor, rightmotor, position, lasterror, powermotor, error;

unsigned long S[2];
int pins[2] = {A1, A2};
int MAXS[2] = {820, 818};
int MINS[2] = {258, 286};

void setup()
{
  pinMode(PWM_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(DIR_L, OUTPUT);
  pinMode(DIR_R, OUTPUT);
  pinMode(RR, INPUT_PULLUP);
  pinMode(M, INPUT_PULLUP);
  pinMode(L, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(LL, INPUT_PULLUP);
  pinMode(Light_L, INPUT);
  pinMode(Light_R, INPUT);
  analogWrite(PWM_L, 0);
  analogWrite(PWM_R, 0);
  digitalWrite(DIR_L, LOW);
  digitalWrite(DIR_R, LOW);
  // Serial.begin(9600);

  //---------------------------------------------
  // view function
  //  view();
  //  viewdiff();
  //  viewReadObs();
  //  viewBatt();
  //  viewIR();
  //  viewIRraw();--

  //----------------------------------------------

  //-----------------------------------------------------
  // practics
  // Start module !!!!!!
  // wait_SW8();
  while (digitalRead(13) == 0)
    ;
  delay(4999);
  if (readDipSwitch() == 0) // normal track
  {
    GO_test(40, 70);
  }
  else if (readDipSwitch() == 1) // test track
  {
    while (1)
    {
      Track_turn(70);
    }
  }
  else if (readDipSwitch() == 2) // test motor
  {
    motor(50, 50);
    delay(1000);
    motor(-50, 50);
    delay(1000);
    motor(50, -50);
    delay(1000);
    motor(-50, -50);
    delay(1000);
  }
  else if (readDipSwitch() == 3) // right
  {
    motor(100, 0);
    delay(150);
    motor(65, 100);
    delay(600);
    motor(0, 100);
    delay(125);
    GO_test(40, 100);
  }
  else if (readDipSwitch() == 4)
  { // left
    motor(0, 100);
    delay(150);
    motor(100, 65);
    delay(600);
    motor(100, 0);
    delay(125);
    GO_test(40, 100);
  }
  else if (readDipSwitch() == 5) // PID track
  {
    routine_pid(30, 70, 0.025, 0.2);
  }
  else if (readDipSwitch() == 6)
  {
    motor(100, 0);
    delay(150);
    unsigned long last_time = millis();
    while (millis() - last_time <= 1000)
    {
      if (analogRead(A2) > 400)
      {
        motor(0, 100);
      }
      else
      {
        motor(100, 100);
      }
    }
    motor(0, 100);
    delay(195);
    GO_test(40, 100);
  }
  //------------------------------------------------------

  //----------------------------------------------------
  // in the stadium
  while (digitalRead(13) == 0) // normal track
    ;
  if (readDipSwitch() == 0)
  {
    GO_remote(40, 100);
  }
  else if (readDipSwitch() == 1) // right+
  {
    motor(100, 0);
    delay(150);
    motor(65, 100);
    delay(600);
    motor(0, 100);
    delay(125);
    GO_remote(40, 100);
  }
  else if (readDipSwitch() == 2) // left
  {
    motor(0, 100);
    delay(150);
    motor(100, 65);
    delay(600);
    motor(100, 0);
    delay(125);
    GO_remote(40, 100);
  }
  else if (readDipSwitch() == 3)//แตะขอบ
  {
    motor(100, 0);
    delay(150);
    unsigned long last_time = millis();
    while (millis() - last_time <= 1000)
    {
      if (analogRead(A2) > 400)
      {
        motor(0, 100);
      }
      else
      {
        motor(100, 100);
      }
    }
    motor(0, 100);
    delay(195);
    GO_test(40, 100);
  }
  //----------------------------------------------------
}

void loop()
{
  // Serial.println(digitalRead(13));
  motor(0, 0);
}