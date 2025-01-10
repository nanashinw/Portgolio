
void TurnL(){
  MotorF(-TurnSpeed,TurnSpeed);
  MotorB(-TurnSpeed,TurnSpeed);
  delay(TurnLdelaytime);
  MotorStop();
  delay(300);
}

void TurnR(){
  MotorF(TurnSpeed,-TurnSpeed);
  MotorB(TurnSpeed,-TurnSpeed);
  delay(TurnRdelaytime);
  MotorStop();
  delay(300);
}