#include <Wire.h>
#define MOTOR_I2C_ADDRESS 0x50

#define numCh 3

// int pin_ch[numCh] = {9,10,11}; //new
// int pin_ch[numCh] = {9,11,12}; //ohm
// int pin_ch[numCh] = {10,9,11}; //belle
int pin_ch[numCh] = {10,9,11}; //great



int MAX[numCh] = {1800,1800,1700};
int MIN[numCh] = {1200,1200,1200};

// int MAX[numCh] = {1800,1800,1800}; //ohm
// int MIN[numCh] = {1100,1100,1100};

int ch[numCh]; //ch[1] forward , ch[3] L-R

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  // pinMode(12, INPUT);
  // pinMode(13, INPUT);
  Motor(0,0);
  Serial.print("Ready ..........");
  // while (digitalRead(8) == 1);
  // Motor(255, 255);
  // delay(2000);
  // Motor(0,0);
  // viewRemote();
  // viewRaw();
  // viewMotor();
  delay(500);
}

//ch[0] ch[1]
void loop() {
  Readremote();
  if(ch[2] < 0){
    if(ch[0] == 0){
      controlMotors(ch[1], ch[0],50);
    }else{
      controlMotors(ch[1], ch[0],100);
    }
  }else{
    controlMotors(ch[1], ch[0],200);
  }
  delay(20); // ลดการประมวลผลให้ CPU ทำงานเบาลง
}



void Soccer(){
  Readremote();
  if(ch[2] < 0){
    controlMotors(ch[1], ch[0],100);
  }else{
    controlMotors(ch[1], ch[0],200);
  }
  delay(20); // ลดการประมวลผลให้ CPU ทำงานเบาลง
}
