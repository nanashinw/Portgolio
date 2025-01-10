
void Knob_Servo(){
  long value;
  while(1){
    value = map(knob(),0,4000,0,180);
    Serial.println(value);
    servo(1,value);
    servo(2,value);
    servo(3,value);
    servo(4,value);
    delay(10);
  }
}


void ServoRed(){
  servo(1,0);
  delay(300);
  servo(1,90);
  delay(300);
  servo(1,0);
  delay(300);
  servo(1,90);
  delay(300);
}

void ServoBlue(){
  servo(1,180);
  delay(300);
  servo(1,90);
  delay(300);
  servo(1,180);
  delay(300);
    servo(1,90);
  delay(300);
}

void ServoYellow(){
  servo(2,0);
  delay(300);
  servo(2,90);
  delay(300);
  servo(2,0);
  delay(300);
    servo(2,90);
  delay(300);
}

void ServoGreen(){
  servo(2,180);
  delay(300);
  servo(2,90);
  delay(300);
  servo(2,180);
  delay(300);
  servo(2,90);
  delay(300);
}