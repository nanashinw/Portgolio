void view() {
  Serial.begin(9600);
  while (1) {
    for (int i = 0; i < numsensor; i++) {
      Serial.print(nashi(pin[i]));
      Serial.print(",\t");
    }
    Serial.println("");
  }
  Serial.end();
}

void viewIR() {
  Serial.begin(9600);
  ReadIR();
  while (1) {
    ReadIR();
    for (int i = 0; i < 2; i++) {
      Serial.print(S[i]);
      Serial.print(",\t");
    }
    Serial.println("");
  }
  Serial.end();
}

void viewIRraw() {
  Serial.begin(9600);
  ReadIR();
  while (1) {
    ReadIR();
    for (int i = 0; i < 2; i++) {
      Serial.print(analogRead(pins[i]));
      Serial.print(",\t");
    }
    Serial.println("");
  }
  Serial.end();
}

void viewReadObs() {
  Serial.begin(9600);
  ReadObs();
  while (1) {
    ReadObs();
    for (int i = 0; i < numsensor; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println(ReadObs());
  }
  Serial.end();
}

void viewdiff(){
  Serial.begin(9600);
  while (1) {
    Serial.println(readDipSwitch());
  }
  Serial.end();
}


void viewBatt(void)
{
   Serial.begin(9600);
  while(1){
  int adc = analogRead(VBATT);
  float adcVolt = (float)adc * (5.0f / 1023.0f);
  float vBatt = adcVolt * (1.0f + (10.0f / 3.9f));
  Serial.println(vBatt);
  }
   Serial.end();
}