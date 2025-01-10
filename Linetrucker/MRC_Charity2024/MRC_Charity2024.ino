#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 NEW;
#define L 100
#define R 101

//define pin motorA
#define dir1A 2
#define dir2A 3
#define pwmA 5

//define pin motorB
#define dir1B 4
#define dir2B 7
#define pwmB 6
#define numsensor 8
// int pin[numsensor] = {A0, A1, A2, A3, A4, A5, A6, A7};
int pin[numsensor] = {A7, A6, A5, A4, A3, A2, A1, A0};
int MAX[numsensor] = {633,	629,	622,	634,	622,	630,	635,	664};  //เอาค่า max มาลบ 100 เช่น 982-100 = 882
int MIN[numsensor] = { 140,	139,	137,	140,	141,	139,	142,	182 };
unsigned long F[numsensor];
int last_value = 0;

float leftmotor, rightmotor, position, lasterror, powermotor, error;

void setup() {
  Serial.begin(9600);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(pwmB, OUTPUT);
  // (sck, mosi, miso, cs);
  //^ begin(cl, mo, mi, ce);
  // NEW.begin(A0, A1, A2, A3);

  // view();
  // viewReadLine();
  // while (true) {
  //   Read();
  // }



  //waitSW part1
  while (digitalRead(8) == 1)
    ;

  //waitSW part2
  // while(true){
  //   if(digitalRead(8) == 1){
  //     break;
  //   }
  // }
  
  delay(1000);
  tfade(600,35,100,0.15);
  curve(L,300,40);
  tfade(650,35,90,0.15);
  curve(L,300,40);
  tfade(1050,35,90,0.1);
  curve(R,300,40);
  tfade(800,35,90,0.09);

  // curve(L,300,40);
  // tfade(500,45,100,0.05);
  // curve(R, 200);
  // curve(R, 200);
  // curve(L, 200);
  // curve(L, 200);


  // tfade(500,45,100,0.05);
  // curve(R, 200);
  // tfade(1050,45,100,0.05);
  // curve(L, 200);
  // tfade(1300,45,100,0.05);
  // curve(R, 350);
  // tfade(1400,45,100,0.05);
  // curve(L, 400);





//  motor(100, 100);
//  delay(1000);
  motor(0, 0);
}
  // tfade(1400); strant


void loop() {
  motor(0, 0);
  Serial.println(digitalRead(8));
}


void view() {
  while (true) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(analogRead(pin[i]));
      Serial.print(",\t");
    }
    Serial.println("");
  }
}

void motor(int speedL, int speedR) {
  speedL = (speedL * 255) / 100;
  speedR = (speedR * 255) / 100;

  //motor Left speed
  if (speedL == 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, 0);
  } else if (speedL > 0) {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, speedL);  //50 = 50
  } else {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, -speedL);  //-(-50) = 50
  }

  //motor Right speed
  if (speedR == 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, 0);
  } else if (speedR > 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, speedR);  //50 = 50
  } else {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, -speedR);  //-(-50) = 50
  }
}

void Read() {
  // int x = 0;
  // int count = 0;
  // for (int i = numsensor - 1; i > -1; i--) {
  //   x = map(NEW.readADC(i), MIN[i], MAX[i], 1000, 0);
  //   if (x > 1000) x = 1000;
  //   if (x < 0) x = 0;
  //   F[count] = x;
  //   count++;
  // }
  int x = 0;
  for (int i = 0; i < numsensor; i++) {
    x = map(analogRead(pin[i]), MIN[i], MAX[i], 0, 1000);
    if (x > 1000) x = 1000;
    if (x < 0) x = 0;
    F[i] = x;
  }
}

int ReadLine() {
  unsigned long avg = 0, sum = 0;
  int online = 0;
  Read();
  for (int i = 0; i < numsensor; i++) {
    if (F[i] > 200) {
      online = 1;
    }
    if (F[i] > 50) {
      avg = avg + (F[i] * (i * 1000));
      sum = sum + F[i];
    }
  }
  if (online == 0) {
    if (last_value > (numsensor - 1) * 1000 / 2) {
      return (numsensor - 1) * 1000;
    } else {
      return 0;
    }
  } else {
    last_value = avg / sum;
  }
  return last_value;
}

void viewReadLine() {
  while (true) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println(ReadLine());
  }
}

//Kp แกะเส้น
//Kd

void tn(float Speed, float Kp, float Kd) {
  position = ReadLine();
  error = position - 3500;
  powermotor = (Kp * error) + (Kd * (error - lasterror));
  lasterror = error;
  leftmotor = Speed + powermotor;
  rightmotor = Speed - powermotor;
  if (leftmotor > Speed) leftmotor = Speed;
  if (leftmotor < -Speed) leftmotor = -Speed;
  if (rightmotor > Speed) rightmotor = Speed;
  if (rightmotor < -Speed) rightmotor = -Speed;
  motor(leftmotor, rightmotor);
}

void ttime(float speed, float kp, float kd, long timer) {
  unsigned long last_time = millis();
  while (millis() - last_time <= timer) {
    tn(speed, kp, kd);
  }
}

//line 45 degree celles
void trr(float speed, float kp, float kd) {
  ReadLine();
  while (F[7] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[4] < 400 or F[7] < 400) {
    tn(speed, kp, kd);
  }
}

void tll(float speed, float kp, float kd) {
  ReadLine();
  while (F[0] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[0] < 400 or F[3] < 400) {
    tn(speed, kp, kd);
  }
}

void tr(float speed, float kp, float kd) {
  ReadLine();
  while (F[7] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[7] < 400) {
    tn(speed, kp, kd);
  }
}

void tl(float speed, float kp, float kd) {
  ReadLine();
  while (F[0] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[0] < 400) {
    tn(speed, kp, kd);
  }
}

void t(float speed, float kp, float kd) {
  ReadLine();
  while (F[0] > 200 or F[7] > 200) {
    tn(speed, kp, kd);
  }
  ReadLine();
  while (F[0] < 400 or F[7] < 400) {
    tn(speed, kp, kd);
  }
}

void move(int speedL, int speedR, int Timer) {
  motor(speedL, speedR);
  delay(Timer);
}

void l() {
  move(-30, 30, 0);
  ReadLine();
  while (F[0] > 200) {
    ReadLine();
  }
  ReadLine();
  while (F[0] < 400) {
    ReadLine();
  }
}

void r() {
  move(30, -30, 0);
  ReadLine();
  while (F[7] > 200) {
    ReadLine();
  }
  ReadLine();
  while (F[7] < 400) {
    ReadLine();
  }
}

