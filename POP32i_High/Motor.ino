#define PWMA 1
#define PWMB 2
#define PWMC 3
#define PWMD 4

void MotorF(int LS,int RS){
  motor(PWMA,LS);
  motor(PWMB,RS);
}

void MotorB(int LS,int RS){
  motor(PWMC,LS);
  motor(PWMD,RS);
}

void MotorStop(){
  motor(PWMA,0);
  motor(PWMB,0);
  motor(PWMC,0);
  motor(PWMD,0);
}

void FD(){
  MotorF(Speed-3,Speed);
  MotorB(Speed-3,Speed);
}

void BK(){
  MotorF(-Speed,-Speed-3);
  MotorB(-Speed,-Speed-3);
}