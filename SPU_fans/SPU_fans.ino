#include <Servo.h>

#include <light_CD74HC4067.h>
CD74HC4067 mux(A0, A1, A2, A3); //ตัวรับส่งสัญญาณ

Servo esc;
#define pwmA 5 
#define dir1A 2
#define dir2A 3
#define pwmB 6
#define dir1B 4
#define dir2B 7

#define numsensor 16
int Max[numsensor] = {400,400,400,400,400,400,400,400,400,400,400,400,400,400,400,400};
int Min[numsensor] = {150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150};

const int signal_pin = A4;
unsigned long sensorValue[numsensor];
int Background = 0;
int last_value;
float leftmotor, rightmotor, powermotor, error, last_error, position;

void setup() {
  initt();

  // see8();
  // view();
  // viewReadLine();
  // viewDistance();

  digitalWrite(13, HIGH);
  while (analogRead(6) > 500); delay(200);
  digitalWrite(13, LOW);   

  openfan(1550);
  delay(300);



  trackTime(50, 0.0135, 0.13, 375);
  T(10, 0.0135, 0.13);
  TL(10, 0.0135, 0.13);
  L();
  trackTime(30, 0.0135, 0.13, 975);
  TR(30, 0.0135, 0.13);
  haftRline();
  trackTime(30, 0.0135, 0.14, 4500);
  T(30, 0.0135, 0.13);
  trackTime(90, 0.0135, 0.14, 2000);
  // trackTime(15, 0.012, 0.15, 550);
  // trackTime(50, 0.01, 0.13, 200);
  // trackTime(35, 0.012, 0.16, 1000);
  // trackTime(50, 0.01, 0.13, 400);

  // trackTime(50, 0.013, 0.16, 700);
  // trackTime(50, 0.013, 0.15, 650);
  // trackTime(50, 0.01, 0.13, 450);








  // Motor(30,30);
  // delay(1000);

  Motor(0, 0);
  delay(100);
  esc.writeMicroseconds(0);
}

void loop() {

}

void see8(){
  while (true) {
    Serial.print(analogRead(6));
    Serial.println(" ");
  }
}

void initt() {
  esc.attach(8);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(signal_pin, INPUT);
  Serial.begin(9600);
  for (int i = 0; i < 900 ; i++) {
    esc.writeMicroseconds(i);
    delay(5);
  }
}


void Move(int a, int b, int c) {
  Motor(a, b);
  delay(c);
}

void openfan(int sp) {
  for (int i = 1000; i < sp ; i++) {
    esc.writeMicroseconds(i);
    delay(3);
  }
}

void TrackNormal(int BaseSpeed, float kp, float kd) {
  position = ReadLine();
  error = position - 7500;
  powermotor = (kp * error) + (kd * (error - last_error));
  last_error = error;
  leftmotor = BaseSpeed + powermotor;
  rightmotor = BaseSpeed - powermotor;
  if (leftmotor > 100) leftmotor = 100;
  if (leftmotor <= -100) leftmotor = -100;
  if (rightmotor > 100) rightmotor = 100;
  if (rightmotor <= -100) rightmotor = -100;
  Motor(leftmotor, rightmotor);
}

void trackTime(int BaseSpeed, float kp, float kd, long timer) {
  unsigned long Last_time = millis();
  while (millis() - Last_time < timer) {
    TrackNormal(BaseSpeed, kp, kd);
  }
}

void T(float speed, float kp, float kd) {
  ReadLine();
  while (sensorValue[0] > 200 or sensorValue[15] > 200) {
    TrackNormal(speed, kp, kd);
  }
  ReadLine();
  while (sensorValue[0] < 400 or sensorValue[15] < 400) {
    TrackNormal(speed, kp, kd);
  }
}

void TL(float speed, float kp, float kd) {
  ReadLine();
  while (sensorValue[0] > 200) {
    TrackNormal(speed, kp, kd);
  }
  ReadLine();
  while (sensorValue[0] < 400) {
    TrackNormal(speed, kp, kd);
  }
}

void TR(float speed, float kp, float kd) {
  ReadLine();
  while (sensorValue[15] > 200) {
    TrackNormal(speed, kp, kd);
  }
  ReadLine();
  while (sensorValue[15] < 400) {
    TrackNormal(speed, kp, kd);
  }
}

void L() {
  Move(-40, 40, 0);
  ReadLine();
  while (sensorValue[0] > 200) {
    ReadLine();
  }
  ReadLine();
  while (sensorValue[0] < 400) {
    ReadLine();
  }
}

void R() {
  Move(40, -40, 0);
  ReadLine();
  while (sensorValue[15] > 200) {
    ReadLine();
  }
  ReadLine();
  while (sensorValue[15] < 400) {
    ReadLine();
  }
}


void haftRline()
{
  Move(60,10,60);
  ReadLine();
  while(sensorValue[15] < 400){
    Move(60,10,0);
    ReadLine();
  }

}

void TrackObject(int BaseSpeed, float kp, float kd, long timer){
  unsigned long Last_time = millis();
  while (millis() - Last_time < timer) {
    TrackNormal(BaseSpeed, kp, kd);
  }
}

void Motor(int a, int b) {
  a = (a * 255) / 100;
  b = (b * 255) / 100;
  if (a == 0) {
    analogWrite(pwmA, 255);
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, LOW);
  }
  else if (a > 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, a);
  }
  else {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, -a);
  }
  if (b == 0) {
    analogWrite(pwmB, 255);
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, LOW);
  }
  else if (b > 0) {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, b);
  }
  else {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, -b);
  }
}

void readPrivate()
{
  for (int i = 0; i < 16; i++) {
    mux.channel(i);
    sensorValue[i]  = analogRead(signal_pin);
  }
}

void Read() {
  readPrivate();
  for (int i = 0; i < numsensor; i++) {
    int x = 0;
    x = map(sensorValue[i], Min[i], Max[i], 0, 1000);
    if (x > 1000) x = 1000;
    if (x < 0) x = 0;
    sensorValue[i] = x;
  }
}

int ReadLine() {
  int k;
  int on_line = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  unsigned long value = 0;
  on_line = 0;
  Read();
  avg = 0;
  sum = 0;
  for (int i = 0; i < numsensor; i++) {
    value = sensorValue[i];
    if (Background == 1) {
      value = 1000 - value;
      sensorValue[i] = value;
    }
    if (value > 200) on_line = 1;
    if (value > 50) {
      avg += value * (i * 1000);
      sum += value;
    }
  }
  if (on_line == 0) {
    if (last_value < ((numsensor - 1) * 1000) / 2) {
      return 0;
    }
    else {
      return (numsensor - 1) * 1000;
    }
  }
  else {
    last_value = avg / sum;
  }
  return last_value;
}

void view() {
  while (true) {
    readPrivate();
    for (int i = 0; i < numsensor; i++) {
      Serial.print(sensorValue[i]);
      Serial.print(",\t");
    }
    Serial.println(" ");
  }
}

void viewReadLine() {
  while (true) {
    ReadLine();
    for (int i = 0; i < numsensor; i++) {
      Serial.print(sensorValue[i]);
      Serial.print('\t');
    }
    Serial.println(ReadLine());
  }
}

void viewDistance(){
  while (true) {
    Serial.println(digitalRead(12));
  }
}
