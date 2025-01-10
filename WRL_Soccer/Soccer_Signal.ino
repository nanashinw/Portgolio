void Readremote() {
  int x = 0;
  for (int i = 0; i < numCh; i++) {
    x = map(pulseIn(pin_ch[i], HIGH, 30000), MIN[i], MAX[i], -255, 255);
    if (x > 255) x = 255;
    if (x < -255) x = -255;
    if(x > -45 && x < 45) x = 0;
    ch[i] = x;
  }
}

void viewRaw() {
  while (true) {
    for (int i = 0; i < numCh; i++) {
      Serial.print(pulseIn(pin_ch[i], HIGH, 30000));
      Serial.print(",\t");
    }
    Serial.println("");
    Readremote();
  if(ch[2] < 0){
    controlMotors(ch[1], ch[0],100);
  }else{
    controlMotors(ch[1], ch[0],255);
  }
  delay(20); // ลดการประมวลผลให้ CPU ทำงานเบาลง
  }
}


void viewRemote() {
  while (1) {
    for(int i = 0; i < numCh; i++){
      Serial.print(ch[i]);
      Serial.print("\t");
    }
    Serial.println("");
    Readremote();
  //     Readremote();
  // if(ch[2] < 0){
  //   controlMotors(ch[1], ch[0],100);
  // }else{
  //   controlMotors(ch[1], ch[0],190);
  // }
  // delay(20); // ลดการประมวลผลให้ CPU ทำงานเบาลง
  }
}