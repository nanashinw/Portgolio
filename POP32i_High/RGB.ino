#include <Wire.h>
#include "Adafruit_TCS34725.h"



Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
uint16_t r, g, b, c, colorTemp, lux;



void StatRGB() {
  if (tcs.begin()) {
    oled.text(0, 0, "Found sensor");
  } else {
    oled.text(0, 0, "No TCS34725 found ... check your connections");
  }
  oled.show();
}


void Colour_Check() {
  for(int i = 0 ; i<10; i++){
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
  float x = (r+g+b)/3;

  if(i>=1){
  if ( g>x && g>=r && g>=b && lux >= 2 && colorTemp <= 3900) {  //Green
    ColourState = 1;
    i = 10;
    Serial.println("Green");
    oled.clear();
    oled.text(0,0,"Green");
    oled.show();
    ServoGreen();
    ao(); delay(300);
    // BK(); delay(0); //ถอยเข้าช่อง
  } else if ( r>x &&  r>=g && r>=b && lux <= 1 ) {  //Red 800
    i = 10;
    ColourState = 1;
    Serial.println("Red");
    oled.clear();
    oled.text(0,0,"Red");
    oled.show();
    BK(); delay(400); //ถอยปล่อย แก้delay
    ao(); delay(300);
    ServoRed();
    ao(); delay(300);
    BK(); delay(500); //ถอยเข้าช่อง แก้delay
    TurnR();
    TurnR();
  } else if ( b>x && b>r && b>=g && lux >= 1 && colorTemp <= 5000) {  //Blue
    ColourState = 1;
    i = 10;
    ServoBlue();
    Serial.println("Blue");
    oled.clear();
    oled.text(0,0,"Blue");
    oled.show();
    ao(); delay(300);
    ServoBlue();
    ao(); delay(300);
    BK(); delay(500); //ถอยเข้าช่อง
  } else if ( (b<r && b<g) && lux >= 1 && colorTemp <= 3000 ) {  //Yellow
    ColourState = 1;
    i = 10;
    Serial.println("Yellow");
    oled.clear();
    oled.text(0,0,"Yellow");
    oled.show();
    BK(); delay(500); //ถอยปล่อย แก้delay
    ao(); delay(300);
    ServoYellow();
    ao(); delay(300);
    BK(); delay(400); //ถอยเข้าช่อง แก้delay
    TurnR();
    TurnR();
  } else {
    i = 10;
    ColourState = 0;
    Serial.println("While");
    oled.clear();
    oled.text(0,0,"While");
    oled.show();
  }
  }
  }
}

void Read_Color_Box(){ //อ่าค่าสีแสดงจอแบบละเอียด
   
 for(int i = 0 ; i<=10; i++){
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  oled.clear();
  oled.text(0,0,"Lux");
  oled.text(0,5,"%d", lux);
  oled.text(1,0,"R");
  oled.text(1,5,"%d", r);
  oled.text(2,0,"G");
  oled.text(2,5,"%d", g);
  oled.text(3,0,"B");
  oled.text(3,5,"%d", b);
  oled.text(4,0,"Temp");
  oled.text(4,5,"%d", colorTemp);
  if(i>=1){
  float x = (r+g+b)/3 ;
  if( r>x &&  r>=g && r>=b && lux <= 1 ){ 
    oled.text(6,0,"Color");
    oled.text(6,6,"Red");
    i = 10 ;
  }else if( b>x && b>r && b>=g && lux >= 1 && colorTemp <= 5000){
    oled.text(6,0,"Color");
    oled.text(6,6,"Blue");
    i = 10 ;
  }else if( (b<r && b<g) && lux >= 1 && colorTemp <= 3000 ){
    oled.text(6,0,"Color");
    oled.text(6,6,"Yellow");                       //ปล่อยสีเหลือง
    i = 10 ;
  }else if( g>x && g>=r && g>=b && lux >= 2 && (colorTemp > 5000 && colorTemp < 5999)){
    oled.text(6,0,"Color");
    oled.text(6,6,"Green");
    beep(500);                      //ปล่อยสีเขียว
    i = 10 ;
  }else{
    oled.text(6,0,"Color");
    oled.text(6,6,"White");
    i = 10 ;
  }
  oled.show();
  }
  delay(100);
 }
}
