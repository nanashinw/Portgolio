void Start() {
  FD();
  delay(FD_start);
  MotorStop();
  delay(500);
}

void FD_TWO_2() {
  count_Isee = 0;
  Stateonline = 0;
  for (int i = 0; i < 1700; i++) {
    if(analog(5) > 3000){
      count_Isee++;
    }
    if(analog(0) < Ref0){
      MotorF(50,0);
      MotorB(50,0);
      delay(1);
    }else if(analog(4) < Ref4){
      MotorF(0,50);
      MotorB(0,50);
       delay(1);
    }else if(analog(2) < Ref2){
        Stateonline = 1;
        MotorStop();
        delay(100);
        FD();
        delay(200);
        break;
    }else{
      MotorF(50,50);
      MotorB(50,50);
      delay(1);
    }
  }
  oled.clear();
  oled.text(0,0,"count_Isee : %d",count_Isee);
  oled.show();
}

void FD_TWO() {
  count_Isee = 0;
  Stateonline = 0;
  for (int i = 0; i <= delay_Takep; i++) { //มากไป 3000
    if(analog(0) < Ref0){ //50
      MotorF(80,0);
      MotorB(80,0);
      delay(1);
    }else if(analog(4) < Ref4){ //50
      MotorF(0,80);
      MotorB(0,80);
      delay(1);
    }else{
      MotorF(80,80); //50
      MotorB(80,80);
      delay(1);
    }
  }
  oled.clear();
  oled.text(0,0,"Success");
  oled.show();
}


void FD_ONE() {
  ColourState = 0;
  Stateonline = 0;
  Isee = 0;
  for (int i = 0; i < FD_time_one; i++) {
    long Limit = analog(5);
    if (Limit > 3000) {
      ao();
      delay(100);
      Isee = 1;
      count_Isee++;
      beep();
      oled.clear();
      oled.text(0, 0, "Limit touch");
      oled.show();
      break;
    } else {
      if (analog(2) < Ref1) {
        Stateonline = 1;
        MotorStop();
        delay(100);
        // FD();
        // delay(100);
        break;
      } else if (analog(1) < Ref1) {
        MotorF(0, Speed);
        MotorB(0, Speed);
        delay(1);
      } else if (analog(3) < Ref3) {
        MotorF(Speed, 0);
        MotorB(Speed, 0);
        delay(1);
      } else if (analog(0) < Ref0) {
        MotorF(Speed, 0);
        MotorB(Speed, 0);
        delay(1);
      } else if (analog(4) < Ref4) {
        MotorF(0, Speed);
        MotorB(0, Speed);
        delay(1);
      } else {
        FD();
        delay(1);
      }
    }
  }
  MotorStop();
  delay(300);
  // MotorF(-30,-30);
  // MotorB(-30,-30);
  // delay(50);
  // ao();
  // delay(100);
  // if(Isee == 0){
  //   Colour_Check();
  // }
}

void cross_FD() {
  // if (ColourState == 0) {
    BK();
    delay(100);
    MotorStop();
    delay(100);
    for (int i = 0; i < 1; i++) {
      while (analog(1) > Ref1 && analog(3) > Ref3) {
        FD();
      }
      if (analog(1) < Ref1 ) {
        MotorF(0, Speed);
        MotorB(0, Speed);
        while (analog(3) > Ref3 ) {}//right
      } else if (analog(3) < Ref3) {
        MotorF(Speed, 0);
        MotorB(Speed, 0);
        while (analog(1) > Ref1) {}//lught
      }
      BK(); delay(250);
      MotorStop();
      delay(100);
    }
    delay(10);
    MotorStop();
    delay(200);
  // }
}


void June() {
  // if (ColourState == 0) {
    BK();
    delay(100);
    MotorStop();
    delay(50);
    for (int i = 0; i < 1; i++) {
      while (analog(1) > Ref1 && analog(3) > Ref3 ) {
        FD();
        if(analog(7) < 500){
          MotorStop(); delay(100);
          break;
        }
      }
      if (analog(1) < Ref1) {
        MotorF(0, Speed);
        MotorB(0, Speed);
        while (analog(3) > Ref3) {}
      } else if (analog(3) < Ref3) {
        MotorF(Speed, 0);
        MotorB(Speed, 0);
        while (analog(1) > Ref1) {}
      }
      MotorStop();
      delay(10);
    }
    delay(10);
    MotorStop();
    delay(50);
  // }
}


void cross_Bright() {
  // if (ColourState == 0) {
    MotorStop();
    delay(100);
    for (int i = 0; i < 1; i++) {
      while (analog(1) > Ref1 && analog(3) > Ref3) {
        FD();
        if(analog(7) < 500){
          MotorStop(); delay(100);
          break;
        }
      }
      if (analog(1) < Ref1 ) {
        MotorF(0, Speed);
        MotorB(0, Speed);
        while (analog(3) > Ref3 ) {}//right
      } else if (analog(3) < Ref3) {
        MotorF(Speed, 0);
        MotorB(Speed, 0);
        while (analog(1) > Ref1) {}//lught
      }
      BK(); delay(250);
      MotorStop();
      delay(100);
    }
    delay(10);
    MotorStop();
    delay(200);
  // }
}