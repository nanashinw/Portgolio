void tfade(long timer){
  float speedup = 40;
  float speeddown = 90;
  float timer70 = timer * 0.6;
  float timer30 = timer * 0.4;
  unsigned long LT = millis();
  while(millis()-LT <= timer70){
    speedup = speedup + 0.05;
    if(speedup >= 90) speedup = 90;
    tn(speedup,0.015,0.17);
  }
  speeddown = speedup;
  LT = millis();
  while(millis()-LT <= timer30){
    speeddown = speeddown - 0.05;
    if(speeddown <= 40) speeddown = 40;
    tn(speeddown,0.015,0.15);
  }
}


void stop(long timer){
  float speeddown = 40;
  unsigned long LT = millis();
  while (millis() - LT <= timer) {
    speeddown = speeddown - 0.05;
    if(speeddown <= 0) speeddown = 0;
    tn(speeddown,0.01,0.1);
  }
}

void curve(int direction,int timer){
  if(direction == L){
    tl(35,0.01,0.1);
  }else if(direction == R){
    tr(35,0.01,0.1);
  }
  ttime(35,0.017,0.1,timer);
}

void curve(int direction,int timer,int Speed){
  if(direction == L){
    tl(Speed,0.01,0.1);
  }else if(direction == R){
    tr(Speed,0.01,0.1);
  }
  ttime(Speed,0.017,0.1,timer);
}

//example
//tfade(1200,40,90,0.05);
void tfade(long timer,long min,long max,float timetofade){
  float speedup = min;
  float speeddown = max;
  float timer70 = timer * 0.6;
  float timer30 = timer * 0.4;
  unsigned long LT = millis();
  while(millis()-LT <= timer70){
    speedup = speedup + timetofade;
    if(speedup >= max) speedup = max;
    tn(speedup,0.015,0.17);
  }
  speeddown = speedup;
  LT = millis();
  while(millis()-LT <= timer30){
    speeddown = speeddown - timetofade;
    if(speeddown <= min) speeddown = min;
    tn(speeddown,0.015,0.15);
  }
}

void upp(long timer,long min,long max,float timetofade){
  float speedup = min;
  float speeddown = max;
  unsigned long LT = millis();
  while(millis()-LT <= timer){
    speedup = speedup + timetofade;
    if(speedup >= max) speedup = max;
    tn(speedup,0.015,0.17);
  }
}


void tfadeCross(long timer){
  float speedup = 40;
  float speeddown = 90;
  float timer70 = timer * 0.6;
  float timer30 = timer * 0.4;
  unsigned long LT = millis();
  while(millis()-LT <= timer70){
    speedup = speedup + 0.05;
    if(speedup >= 90) speedup = 90;
    ReadLine();
    if(F[0] > 200 && F[7] > 200){
      move(speedup, speedup, 0);
    }else{
      tn(speedup,0.015,0.17);
    }
  }
  speeddown = speedup;
  LT = millis();
  while(millis()-LT <= timer30){
    speeddown = speeddown - 0.05;
    if(speeddown <= 40) speeddown = 40;
    ReadLine();
    if(F[0] > 200 or F[7] > 200){
      move(speeddown, speeddown, 0);
    }else{
      tn(speeddown,0.015,0.15);
    }
  }
}


void _Left(long timer){
  float speeddown = 50;
  unsigned long LT = millis();
  while (millis() - LT <= timer) {
    speeddown = speeddown - 0.01;
    if(speeddown <= 0) speeddown = 0;
    motor(-speeddown, speeddown);
  }
}
