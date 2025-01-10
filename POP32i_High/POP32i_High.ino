#include <POP32.h>
 
int Ref0, Ref1, Ref2, Ref3, Ref4;
int Speed = 50;

int TurnRdelaytime = 590;
int TurnLdelaytime = 700 ;

int TurnSpeed = 50;

bool Stateonline = 0;
bool ColourState = 0;
bool Isee = 0;

int color_count = 0;
int count_Isee = 0;

int FD_start = 870;  //1620 /950
int FD_time_one = 870; //900

int delay_Takep = 1500;
int delay_Bright = 3200;

void setup() {
  StatRGB();
  Serial.begin(9600);
  _Ref();
  beep();
  waitSW_OK();
  beep();
  oled.clear();
  Start();
}

void Program1() {
  //----------------------------------------------------
  //Limit check
    if(Isee == 1){
      if(analog(6) > 2000){//สะพาน
        
        oled.clear();
        oled.text(0,0,"Bright");
        oled.show();
        for(int i = 0;delay_Bright/2 > i; i++){
          if(analog(0) < Ref1){
            MotorF(Speed, 0);
            MotorB(Speed, 0);
          }else if(analog(4) < Ref4){
            MotorF(0, Speed);
            MotorB(0, Speed);
          }else{
            FD();
          }
          delay(1);
        }
        MotorStop(); delay(100);
        TurnL();
        cross_Bright();
        TurnR();
        FD(); delay(delay_Bright/2);
        MotorStop(); delay(100);
      }else{
        oled.clear();
        oled.text(0,0,"Takep");
        oled.show();
        FD(); delay(delay_Takep);
        MotorStop(); delay(100);
        count_Isee = 0;
      }
    }
    //-----------------------------------------------
    TurnL();
    FD_ONE();
    if (Stateonline == 0) {

    } else if (Stateonline == 1) {
      cross_FD();
      TurnR();
      FD_ONE();
      if (Stateonline == 0) {

      } else if (Stateonline == 1) {
        June();
        Colour_Check();
        BK(); delay(250);
        MotorStop(); delay(100);
          if(ColourState == 0){
            // BK(); delay(50);
            Colour_Check();
            if(ColourState == 1){
              Stateonline = 0;
            }
          }else if (ColourState == 1){
            Stateonline = 0;
          }

        if (Stateonline == 0) {

        } else if (Stateonline == 1) {
          cross_FD();
          TurnR();
          FD_ONE();
          if (Stateonline == 0) {

          } else if (Stateonline == 1) {
            cross_FD();
            TurnR();
            FD_ONE();
          }
        }
      }
    }
  }

  void Program2() {
    if (SW_A()) {
      TurnL();
    } else if (SW_B()) {
      TurnR();
    } else if (SW_OK()) {
      FD_ONE();
    }
  }

  void Program3(){
    Knob_Servo();
  }

  void loop() {
    Program1();
  }
