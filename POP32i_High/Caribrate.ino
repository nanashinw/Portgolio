void _Ref(){
  Ref0 = (((500+2200)/2)+500)/2;
  Ref1 = (((290+1400)/2)+290)/2;
  Ref2 = (((250+1500)/2)+250)/2;
  Ref3 = (((300+1900)/2)+300)/2;
  Ref4 = (((300+1700)/2)+300)/2;
}


void Cheaksen(){
  int numSen = 7;
  for(int i = 0;i<=numSen;i++){
    oled.text(i,0,"Sen [%d] = %d",i,analog(i));
  }
  oled.show();
  oled.clear();
}
