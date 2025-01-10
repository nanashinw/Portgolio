void Motor(int a,int b){
  //Left Motor(a)
  if(a == 0){
    Wire.beginTransmission(MOTOR_I2C_ADDRESS);
    Wire.write(0x85);
    Wire.write(3); //stop
    Wire.write(0);
    Wire.endTransmission();
  }else if(a > 0){
    Wire.beginTransmission(MOTOR_I2C_ADDRESS);
    Wire.write(0x85);
    Wire.write(1); //forward
    Wire.write(a);
    Wire.endTransmission();
  }else if(a < 0){
    Wire.beginTransmission(MOTOR_I2C_ADDRESS);
    Wire.write(0x85);
    Wire.write(2);  //backward
    Wire.write(-a);
    Wire.endTransmission();
  }

  //Right Motor(b)
  if(b == 0){
    Wire.beginTransmission(MOTOR_I2C_ADDRESS);
    Wire.write(0x86);
    Wire.write(3); //stop
    Wire.write(0);
    Wire.endTransmission();
  }else if(b > 0){
    Wire.beginTransmission(MOTOR_I2C_ADDRESS);
    Wire.write(0x86);
    Wire.write(1); //forward
    Wire.write(b);
    Wire.endTransmission();
  }else if(b < 0){
    Wire.beginTransmission(MOTOR_I2C_ADDRESS);
    Wire.write(0x86);
    Wire.write(2);  //backward
    Wire.write(-b);
    Wire.endTransmission();
  }
}

void controlMotors(int xAxis, int yAxis,int Speed){
  int leftMotorSpeed = constrain(yAxis + xAxis, -Speed, Speed);
  int rightMotorSpeed = constrain(yAxis - xAxis, -Speed, Speed);
  if (leftMotorSpeed < -20 && leftMotorSpeed > 20) leftMotorSpeed = 0;
  if (rightMotorSpeed < -20 && rightMotorSpeed > 20) rightMotorSpeed = 0;
  Motor(leftMotorSpeed,rightMotorSpeed);
}

void viewMotor(){
while (1) {
  int leftMotorSpeed = constrain(ch[0] + ch[1], -255, 255);
  int rightMotorSpeed = constrain(ch[0] - ch[1], -255, 255);
  if (leftMotorSpeed > -20 && leftMotorSpeed < 20) leftMotorSpeed = 0;
  if (rightMotorSpeed > -20 && rightMotorSpeed < 20) rightMotorSpeed = 0;
  Serial.print(leftMotorSpeed);
  Serial.print("\t");
  Serial.println(rightMotorSpeed);
  Readremote();
}
}